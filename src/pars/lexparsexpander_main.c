/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexparsexpander_main.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 00:47:14 by mbourgeo          #+#    #+#             */
/*   Updated: 2022/10/06 03:36:09 by mbourgeo         ###   ########.fr       */
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
	ft_init_lex_decisions(&lex);
	ft_init_lex_actions(&lex);
	ft_bzero(&pars, sizeof(t_pars));
	ft_init_pars_decisions(&pars);
	ft_init_pars_actions(&pars);
	ft_init_exp_decisions(&pars);
	ft_init_exp_actions(&pars);
	//ft_init_token_types(&lex);
	//temp = readline("$>");
	fd = open("lexer.test", O_RDONLY, 644);
	if (fd < 0)
		return (ft_msgerr(ERR_TESTFILE), 1);
	lex.user_input = get_next_line(fd);
	temp = lex.user_input;
	while (lex.user_input)
	{
		//printf("taken char : %d\n", lex.nb_taken_char);
		printf("\n--------------------------\n");
		printf("%s", lex.user_input);
		printf("--------------------------\n");
		//if (ft_mallocator(&lex.user_input, ft_strlen(temp) * sizeof(char)))
		//	return (ft_msgerr(ERR_MALLOC), 1);
		//lex.user_input = temp;
		if (ft_lexer(&lex))
		{
			//printf("error herehere\n");
			//ft_tklist_freeall(&lex);
			ft_free_tokenlist(lex.token);
			lex.token = NULL;
			lex.temp = ft_strndup("", 0);
			lex.token = ft_token_addnext(lex.token, ft_new_token(lex.temp));
			lex.nb_of_tokens = 1;
			//printf("check err : %d\n", lex.new_decision.token_type);
			lex.token->type = lex.new_decision.token_type;
			free(lex.temp);
			lex.temp = NULL;
		}
		//printf("came back\n");
		//printf("check reading mode : %d\n", lex.new_decision.lex_read_mode);
		//if (lex.new_decision.lex_read_mode != SYNT_ERR_LEX_RD_MD)
		ft_print_lexer_content(&lex);
		pars.nb_of_commands = 0;
		pars.nb_of_tokens = lex.nb_of_tokens;
		ft_parser(&lex, &pars);
		ft_tklist_freeall(&lex);
		free(temp);
		temp = NULL;
		ft_print_parser_content(&pars);
		ft_expander(&pars);
		ft_print_expander_content(&pars);
		ft_cmdlist_freeall(&pars);
		//ft_bzero(&(lex.prev_decision), sizeof(t_lex_proc));
		//ft_bzero(&(lex.new_decision), sizeof(t_lex_proc));
		lex.user_input = get_next_line(fd);
		temp = lex.user_input;
	}
	//printf("here\n");
	if (temp)
	{
		free(temp);
		temp = NULL;
	}
	//printf("here\n");
	//ft_freeall(&lex);
	close(fd);
	return (0);
}

int	ft_lexer(t_lex *lex)
{
	while (*lex->user_input && *lex->user_input != '\n' && lex->prev_decision.lex_read_mode != SYNT_ERR_LEX_RD_MD)
	{	
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
	if (lex->new_decision.lex_read_mode != SYNT_ERR_LEX_RD_MD)
		if (ft_lex_apply_decision(lex))
		{
			//printf("error hereherehere\n");
			return (1);
		}
	//printf("just after check reading mode : %d\n", lex->new_decision.lex_read_mode);
	if (lex->new_decision.lex_read_mode != SYNT_ERR_LEX_RD_MD)
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
		ft_pars_apply_decision(pars);
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
			printf("check : %s\n", pars->token->id);
			pars->nb_taken_char = 0;
			pars->offset_start = 0;
			pars->start_char = 0;
			pars->start_dol = 0;
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
						printf("wrk char is : %c\n", pars->parser_text[0]);
						//printf("nb_taken_char : %d\n", pars->nb_taken_char);
						//printf("offset_start : %d\n", pars->offset_start);
						//printf("start_char : %d\n", pars->nb_taken_char);
						//printf("start_dol : %d\n", pars->start_dol);
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
			//printf("je suis la\n");
			//printf("exp_read_mode : %d\n", pars->new_exp_decision.exp_read_mode);
			//printf("offset_start : %d\n", pars->offset_start);
			//printf("start_char : %d\n", pars->start_char);
			//printf("nb_taken_char : %d\n", pars->nb_taken_char);
			//printf("prgs   %s <%s>\n", pars->token->id, ft_getlabel_token_types(pars->token->type));
			//printf("new token : %s\n", pars->command->token->next->id);
			pars->command->token = pars->command->token->next;
			pars->nb_taken_char = 0;
			pars->offset_start = 0;
			pars->start_char = 0;
			pars->start_dol = 0;
			//printf("new token : %s\n", pars->token->id);
		}
		//printf("\n");
		pars->command = pars->command->next;
		j = 0;
	}
	return (0);
}

int	ft_print_lexer_content(t_lex *lex)
{
	int	i;

	i = 0;
	printf("LEXER CONTENT\n");
	//printf("check : %d\n", lex->nb_of_tokens);
	while (i++ < lex->nb_of_tokens)
	{
		//printf("here\n");
		//printf("lex->token->id : %s\n", lex->token->id);
		//printf("%s :%d: <%s>\n", lex->token->id, lex->token->id[0], ft_getlabel_token_types(lex->token->type));
		printf("%s <%s>\n", lex->token->id, ft_getlabel_token_types(lex->token->type));
		lex->token = lex->token->next;
	}
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
	return (0);
}
