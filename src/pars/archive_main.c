/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 00:47:14 by mbourgeo          #+#    #+#             */
/*   Updated: 2022/10/08 17:05:10 by mbourgeo         ###   ########.fr       */
/*   Updated: 2022/09/30 16:01:12 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(void)
{
	if (ft_read_prompt())
		return (1);
	return (0);
}

int	ft_read_prompt(void)
{
	t_lex		lex;
	t_pars		pars;
	int			fd;
	char		*temp;

	//if (ft_mallocator(&lex, sizeof(t_lex)))
	//	return (ft_msgerr(ERR_MALLOC), NULL);
	ft_bzero(&lex, sizeof(t_lex));
	ft_bzero(&pars, sizeof(t_pars));
	ft_general_initialize(&lex, &pars);
	//ft_init_token_types(&lex);
	//temp = readline("$>");
	fd = open("lexer.test", O_RDONLY, 644);
	if (fd < 0)
		return (ft_msgerr(ERR_TESTFILE), 1);
	lex.user_input = get_next_line(fd);
	temp = lex.user_input;
	while (lex.user_input)
	{
		ft_general_initialize(&lex, &pars);
		printf("\n--------------------------\n");
		printf("\033[0;32m%s\033[0m", lex.user_input);
		printf("--------------------------\n");
		if (ft_lexer(&lex))
		{
			ft_free_tokenlist(lex.token);
			lex.token = NULL;
			lex.temp = ft_strndup("", 0);
			lex.token = ft_token_addnext(lex.token, ft_new_token(lex.temp));
			lex.nb_of_tokens = 1;
			lex.token->type = lex.new_decision.token_type;
			free(lex.temp);
			lex.temp = NULL;
		}
		ft_print_lexer_content(&lex);
		pars.nb_of_commands = 0;
		pars.nb_of_tokens = lex.nb_of_tokens;
		if (ft_parser(&lex, &pars))
		{
			ft_tklist_freeall(&lex);
			free(temp);
			temp = NULL;
			ft_cmdlist_freeall(&pars);
			break ;
		}
		ft_tklist_freeall(&lex);
		free(temp);
		temp = NULL;
		ft_print_parser_content(&pars);
		ft_expander(&pars);
		ft_print_expander_content(&pars);
		if (ft_redirector(&pars))
		{
			ft_tklist_freeall(&lex);
			free(temp);
			temp = NULL;
			ft_cmdlist_freeall(&pars);
			break ;
		}
		ft_print_redirector_content(&pars);
		ft_transformer(&pars);
		pars.cmd = pars.cmd_head;
		ft_print_transformer_content(pars.cmd);
		ft_cmdlist_freeall(&pars);
		lex.user_input = get_next_line(fd);
		temp = lex.user_input;
	}
	if (temp)
	{
		free(temp);
		temp = NULL;
	}
	close(fd);
	return (0);
}

int	ft_lexer(t_lex *lex)
{
	while (*lex->user_input && *lex->user_input != '\n' && lex->prev_decision.lex_read_mode != ERR_LEX_RD_MD)
	{	
		if (ft_lex_apply_decision(lex))
			return (1);
		lex->user_input++;
	}
	if (lex->new_decision.lex_read_mode != ERR_LEX_RD_MD)
	{
		if (ft_lex_apply_decision(lex))
			return (1);
	}
	if (lex->new_decision.lex_read_mode == ERR_LEX_RD_MD)
	{
		return (ft_msgerr((char *)ft_getlabel_error_msgs(lex->new_decision.token_type - TOK_ERR_MARK - 1)));
	}
	if (lex->new_decision.lex_read_mode != ERR_LEX_RD_MD)
		lex->token = lex->token->next;
	return (0);
}

int	ft_parser(t_lex *lex, t_pars *pars)
{
	int	i;

	i = 0;
	pars->token = lex->token;
	while (i++ < pars->nb_of_tokens)
	{
		if (ft_pars_apply_decision(pars))
			return (1);
		pars->token = pars->token->next;
	}
	pars->command->token = pars->command->token->next;
	pars->command = pars->command->next;
	return (0);
}

int	ft_expander(t_pars *pars)
{
	int		i;
	int		j;
	char	*temp;

	i = 0;
	j = 0;
	while (i++ < pars->nb_of_commands)
	{
		while (j++ < pars->command->nb_of_tokens)
		{
			pars->token = pars->command->token;
			pars->offset_start = 0;
			pars->start_std = 0;
			pars->start_dol = 0;
			pars->nb_taken_char = 0;
			pars->before_dol_mode = 0;
			pars->parser_text = ft_strndup(pars->token->id, 0);
			temp = pars->parser_text;
			while (1)
			{
				if (pars->token->type == TOK_WORD)
						ft_exp_apply_decision(pars);
				if (pars->parser_text[0] == '\0')
				{
					free(temp);
					break ;
				}
				pars->parser_text++;
				pars->offset_start++;
			}
			pars->command->token = pars->command->token->next;
			pars->nb_taken_char = 0;
			pars->start_std = 0;
			pars->start_dol = 0;
			pars->offset_start = 0;
		}
		pars->command = pars->command->next;
		j = 0;
	}
	return (0);
}

int	ft_redirector(t_pars *pars)
{
	int		i;
	int		j;
	int		k;
	int		count;

	i = 0;
	j = 0;
	count = 0;
	ft_init_redir_decisions(pars);
	ft_init_redir_actions(pars);
	while (i++ < pars->nb_of_commands)
	{
		k = pars->command->nb_of_tokens;
		while (j++ < k)
		{
			pars->token = pars->command->token;
				if (ft_redir_apply_decision(pars))
					return (1);
			pars->command->token = pars->command->token->next;
		}
		pars->command = pars->command->next;
		count += pars->command->nb_of_tokens;
		j = 0;
	}
	return (0);
}

int	ft_transformer(t_pars *pars)
{
	int		i;

	i = 0;
	while (i++ < pars->nb_of_commands)
	{
		pars->cmd = ft_cmd_addnext(pars->cmd, ft_new_cmd(ft_token_list_to_tab(pars->command)));
		if (i == 1)
			pars->cmd_head = pars->cmd;
		pars->cmd->id = pars->command->id;
		pars->cmd->nb_of_tokens = pars->command->nb_of_tokens;
		pars->cmd->fd_in = pars->command->fd_in;
		pars->cmd->fd_out = pars->command->fd_out;
		pars->command = pars->command->next;
	}
	pars->cmd = pars->cmd_head;
	return (0);
}

int	ft_print_lexer_content(t_lex *lex)
{
	int	i;

	i = 0;
	printf("\nLEXER CONTENT\n");
	while (i++ < lex->nb_of_tokens)
	{
		printf("%s <%s>\n", lex->token->id, ft_getlabel_token_types(lex->token->type));
		lex->token = lex->token->next;
	}
	printf("\033[0m");
	printf("\n");
	return (0);
}

int	ft_print_parser_content(t_pars *pars)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	printf("\nPARSER CONTENT\n");
	while (i++ < pars->nb_of_commands)
	{
		printf("------> starting command id <%d>\n", pars->command->id);
		while (j++ < pars->command->nb_of_tokens)
		{
			printf("%s <%s>\n", pars->command->token->id, ft_getlabel_token_types(pars->command->token->type));
			pars->command->token = pars->command->token->next;
		}
		pars->command = pars->command->next;
		j = 0;
	}
	printf("\033[0m");
	printf("\n");
	return (0);
}

int	ft_print_expander_content(t_pars *pars)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	printf("\nEXPANDER CONTENT\n");
	while (i++ < pars->nb_of_commands)
	{
		printf("------> starting command id <\033[0m%d\033[0m>\n", pars->command->id);
		while (j++ < pars->command->nb_of_tokens)
		{
			printf("\033[0m%s \033[0m<%s>\n", pars->command->token->id, ft_getlabel_token_types(pars->command->token->type));
			pars->command->token = pars->command->token->next;
		}
		pars->command = pars->command->next;
		j = 0;
	}
	printf("\n");
	return (0);
}

int	ft_print_redirector_content(t_pars *pars)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	printf("\nREDIRECTOR CONTENT\n");
	while (i++ < pars->nb_of_commands)
	{
		printf("------> starting command id <\033[0;31m%d\033[0m> <in \033[0;32m%d\033[0m> <out \033[0;32m%d\033[0m>\n", pars->command->id,
				pars->command->fd_in, pars->command->fd_out);
		while (j++ < pars->command->nb_of_tokens)
		{
			printf("\033[0;31m%s \033[0m<%s>\n", pars->command->token->id, ft_getlabel_token_types(pars->command->token->type));
			pars->command->token = pars->command->token->next;
		}
		pars->command = pars->command->next;
		j = 0;
	}
	printf("\033[0m");
	printf("\n");
	return (0);
}

int	ft_print_transformer_content(t_cmd *cmd)
{
	int	i;

	i = 0;
	printf("\nTRANSFORMER CONTENT\n");
	while (cmd)
	{
		printf("------> starting command id <\033[0;31m%d\033[0m> <in \033[0;32m%d\033[0m> <out \033[0;32m%d\033[0m>\n", cmd->id,
				cmd->fd_in, cmd->fd_out);
		while (i++ < cmd->nb_of_tokens)
		{
			printf("\033[0;31m%s\033[0m\n", cmd->token[i - 1]);
		}
		cmd = cmd->next;
		i = 0;
	}
	printf("\033[0m");
	printf("\n");
	return (0);
}
