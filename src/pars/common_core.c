/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common_core.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 00:47:14 by mbourgeo          #+#    #+#             */
/*   Updated: 2022/10/08 22:56:26 by mbourgeo         ###   ########.fr       */
/*   Updated: 2022/09/30 16:01:12 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_cmd	*ft_read_prompt(char *user_input)
{
	t_lex		lex;
	t_pars		pars;

	ft_bzero(&lex, sizeof(t_lex));
	ft_bzero(&pars, sizeof(t_pars));
	ft_general_initialize(&lex, &pars);
	lex.user_input = user_input;
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
		ft_cmdlist_freeall(&pars);
		return (NULL);
	}
	ft_tklist_freeall(&lex);
	ft_print_parser_content(&pars);
	ft_expander(&pars);
	ft_print_expander_content(&pars);
	if (ft_redirector(&pars))
	{
		ft_tklist_freeall(&lex);
		ft_cmdlist_freeall(&pars);
		return (NULL);
	}
	ft_print_redirector_content(&pars);
	ft_transformer(&pars);
	pars.cmd = pars.cmd_head;
	ft_print_transformer_content(pars.cmd);
	ft_cmdlist_freeall(&pars);
	return (pars.cmd);
}

int	ft_lexer(t_lex *lex)
{
	while (*lex->user_input && *lex->user_input != '\n' && lex->prev_decision.lex_read_mode != ERR_LEX_RD_MD)
	{	
		//ft_init_lex_decisions(lex);
		//ft_init_lex_actions(lex);
		//printf("\033[37;1mHello World!\033[0m\n");
		//printf("input_char : %c of type <%d>\n", *lex->user_input, ft_char_type(lex->user_input[0]));
		if (ft_lex_apply_decision(lex))
		{
			//printf("error herehere\n");
			return (1);
		}
		lex->user_input++;
	}
	//printf("exit check reading mode : %d\n", lex->new_decision.lex_read_mode);
	//if (*lex->user_input == '\n')
	//	*lex->user_input = '\0';
	//printf("input_char : %c\n", *lex->user_input);
	//
	if (lex->new_decision.lex_read_mode != ERR_LEX_RD_MD)
	{
		//printf("before : %c\n", lex->user_input[0]);
		//printf("before : %s\n", ft_getlabel_lex_read_modes(lex->new_decision.lex_read_mode));
		//printf("before : %s\n", ft_getlabel_char_types(ft_char_type(lex->user_input[0])));
		if (ft_lex_apply_decision(lex))
		{
			//printf("error hereherehere\n");
			//printf("after : %d\n", lex->nb_of_tokens);
			return (1);
		}
	}
	if (lex->new_decision.lex_read_mode == ERR_LEX_RD_MD)
	{
		//printf("err : %d, %d\n", lex->new_decision.token_type, TOK_ERR_MARK);
		return (ft_msgerr((char *)ft_getlabel_error_msgs(lex->new_decision.token_type - TOK_ERR_MARK - 1)));
	}
	//printf("just after check reading mode : %d\n", lex->new_decision.lex_read_mode);
	if (lex->new_decision.lex_read_mode != ERR_LEX_RD_MD)
		lex->token = lex->token->next;
	//lex->token = lex->token->next;
	//printf("end lexer\n");
	return (0);
}

int	ft_parser(t_lex *lex, t_pars *pars)
{
	int	i;

	i = 0;
	pars->token = lex->token;
	//printf("check : %d\n", pars->nb_of_commands);
	while (i++ < pars->nb_of_tokens)
	{
		if (ft_pars_apply_decision(pars))
			return (1);
		pars->token = pars->token->next;
	}
	//printf("check commands: %d\n", pars->nb_of_commands);
	//printf("shifting token in command from : %s to : %s\n", pars->command->token->id, pars->command->token->next->id);
	pars->command->token = pars->command->token->next;
	//printf("shifting command : %s to : %s\n", pars->command->token->id, pars->command->next->token->id);
	pars->command = pars->command->next;
	return (0);
}

int	ft_expander(t_pars *pars)
{
	int		i;
	int		j;
	char	*temp;

	//printf("\nin expander\n");
	//printf("nb_of_commands : %d\n", pars->nb_of_commands);
	//printf("nb_of_tokens : %d\n", pars->command->nb_of_tokens);
	i = 0;
	j = 0;
	while (i++ < pars->nb_of_commands)
	{
		while (j++ < pars->command->nb_of_tokens)
		{
			pars->token = pars->command->token;
			//printf("check : %s\n", pars->token->id);
			pars->offset_start = 0;
			pars->start_std = 0;
			pars->start_dol = 0;
			pars->nb_taken_char = 0;
			pars->before_dol_mode = 0;
			//printf("wrk token : %s\n", pars->token->id);
			//printf("offset_start : %d\n", pars->offset_start);
			//printf("start_char : %d\n", pars->start_char);
			//printf("nb_taken_char : %d\n", pars->nb_taken_char);
			pars->parser_text = ft_strndup(pars->token->id, 0);
			temp = pars->parser_text;
			//printf("working token : %s\n", pars->parser_text);
			while (1)
			{
				//printf("wrk char is : %c\n", pars->parser_text[0]);
				//printf("je suis ici avec char : %c\n", pars->parser_text[0]);
				if (pars->token->type == TOK_WORD)
					{
						//printf("this will be work\n");
						//printf("wrk char is : %c\n", pars->parser_text[0]);
						//printf("in main : %d, %d, %d, %d\n", pars->offset_start, pars->start_std, pars->start_dol, pars->nb_taken_char);
						//printf("before_dol_mode : %d\n", pars->before_dol_mode);
						ft_exp_apply_decision(pars);
					}
				//else
					//printf("nothing to do\n");
				if (pars->parser_text[0] == '\0')
				{
					//printf("breaking the loop\n");
					free(temp);
					break ;
				}
				pars->parser_text++;
				pars->offset_start++;
			}
			//printf("in main exit: %d, %d, %d, %d\n", pars->offset_start, pars->start_std, pars->start_dol, pars->nb_taken_char);
			//printf("exp_read_mode : %d\n", pars->new_exp_decision.exp_read_mode);
			//printf("prgs   %s <%s>\n", pars->token->id, ft_getlabel_token_types(pars->token->type));
			//printf("new token : %s\n", pars->command->token->next->id);
			pars->command->token = pars->command->token->next;
			pars->nb_taken_char = 0;
			pars->start_std = 0;
			pars->start_dol = 0;
			pars->offset_start = 0;
			//printf("new token : %s\n", pars->token->id);
		}
		//printf("\n");
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
	//printf("\nin redirector\n");
	//printf("nb_of_tokens : %d\n", pars->nb_of_tokens);
	//printf("nb_of_commands : %d\n", pars->nb_of_commands);
	//printf("nb_of_tokens in command : %d\n", pars->command->nb_of_tokens);
	while (i++ < pars->nb_of_commands)
	{
		k = pars->command->nb_of_tokens;
		while (j++ < k)
		{
			pars->token = pars->command->token;
			//printf("new token : %s\n", pars->token->id);
			//while (1)
			//{
				if (ft_redir_apply_decision(pars))
				{
					return (1);
				}
				//printf("\033[37;1mHello World!\033[0m\n");
			//}
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
//		printf("test %d\n", cmd->id);
//		j = 0;
//		while (cmd->token[j++])
//			printf("   +++content[%d] : <%s>\n", j - 1, cmd->token[j - 1]);
//		if (!cmd->token[--j])
//			printf("I got out at i : %d\n", j);
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
	//printf("check : %d\n", lex->nb_of_tokens);
	while (i++ < lex->nb_of_tokens)
	{
		//printf("here\n");
		//printf("lex->token->id : %s\n", lex->token->id);
		//printf("%s :%d: <%s>\n", lex->token->id, lex->token->id[0], ft_getlabel_token_types(lex->token->type));
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
	//printf("check : %d\n", pars->nb_of_commands);
	while (i++ < pars->nb_of_commands)
	{
		printf("------> starting command id <%d>\n", pars->command->id);
		//printf("------> starting command id<%d> verif_id<%d>\n", i, pars->command->id);
		//printf("nb of tokens in command : %d\n", pars->command->nb_of_tokens);
		while (j++ < pars->command->nb_of_tokens)
		{
			//printf("here\n");
			//printf("lex->token->id : %s\n", lex->token->id);
			//printf("%s :%d: <%s>\n", lex->token->id, lex->token->id[0], ft_getlabel_token_types(lex->token->type));
			printf("%s <%s>\n", pars->command->token->id, ft_getlabel_token_types(pars->command->token->type));
			pars->command->token = pars->command->token->next;
		}
		//printf("just stopped on token : %s\n", pars->command->token->id);
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
		//printf("------> starting command id<%d> verif_id<%d>\n", i, pars->command->id);
		//printf("nb of tokens in command : %d\n", pars->command->nb_of_tokens);
		while (j++ < pars->command->nb_of_tokens)
		{
			//printf("here\n");
			//printf("lex->token->id : %s\n", lex->token->id);
			//printf("%s :%d: <%s>\n", lex->token->id, lex->token->id[0], ft_getlabel_token_types(lex->token->type));
			printf("\033[0m%s \033[0m<%s>\n", pars->command->token->id, ft_getlabel_token_types(pars->command->token->type));
			pars->command->token = pars->command->token->next;
		}
		//printf("just stopped on token : %s\n", pars->command->token->id);
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
	//printf("check : %d\n", pars->nb_of_commands);
	while (i++ < pars->nb_of_commands)
	{
		printf("------> starting command id <\033[0;31m%d\033[0m> <in \033[0;32m%d\033[0m> <out \033[0;32m%d\033[0m>\n", pars->command->id,
				pars->command->fd_in, pars->command->fd_out);
		//printf("------> starting command id<%d> verif_id<%d>\n", i, pars->command->id);
		//printf("nb of tokens in command : %d\n", pars->command->nb_of_tokens);
		while (j++ < pars->command->nb_of_tokens)
		{
			//printf("here\n");
			//printf("lex->token->id : %s\n", lex->token->id);
			//printf("%s :%d: <%s>\n", lex->token->id, lex->token->id[0], ft_getlabel_token_types(lex->token->type));
			printf("\033[0;31m%s \033[0m<%s>\n", pars->command->token->id, ft_getlabel_token_types(pars->command->token->type));
			pars->command->token = pars->command->token->next;
		}
		//printf("just stopped on token : %s\n", pars->command->token->id);
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
		//printf("just stopped on token : %s\n", pars->command->token->id);
		cmd = cmd->next;
		i = 0;
	}
	printf("\033[0m");
	printf("\n");
	return (0);
}
