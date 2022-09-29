/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexparser_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 00:47:14 by mbourgeo          #+#    #+#             */
/*   Updated: 2022/09/29 22:20:43 by mbourgeo         ###   ########.fr       */
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
		ft_lexer(&lex);
		//printf("came back\n");
		//printf("check reading mode : %d\n", lex.new_decision.lex_read_mode);
		if (lex.new_decision.lex_read_mode != SYNT_ERR_LEX_RD_MD)
			ft_print_lexer_content(&lex);
		ft_parser(&lex, &pars);
		ft_print_parser_content(&pars);
		ft_freeall(&lex);
		free(temp);
		temp = NULL;
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
		ft_lex_apply_decision(lex);
		lex->user_input++;
	}
	//printf("exit check reading mode : %d\n", lex->new_decision.lex_read_mode);
	//if (*lex->user_input == '\n')
	//	*lex->user_input = '\0';
	//printf("input_char : %c\n", *lex->user_input);
	//
	if (lex->new_decision.lex_read_mode != SYNT_ERR_LEX_RD_MD)
		ft_lex_apply_decision(lex);
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
	printf("first token : %p\n", pars->token);
	pars->token = lex->token;
	printf("now token : <%p> %s\n", pars->token, pars->token->id);
	printf("first nb_of_tokens : %d\n", lex->nb_of_tokens);
	while (i++ < lex->nb_of_tokens)
	{
		printf("current token : %s\n", pars->token->id);
		ft_pars_apply_decision(pars);
		printf("following token : %s\n", pars->token->id);
		pars->token = pars->token->next;
		printf("following token : %s\n", pars->token->id);
	}
/*	while (*pars->user_input && *pars->user_input != '\n' && pars->prev_decision.pars_read_mode != SYNT_ERR_PARS_RD_MD)
	{	
		//printf("input_char : %c of type <%d>\n", *lex->user_input, ft_char_type(lex->user_input[0]));
		ft_lex_apply_decision(pars);
		pars->user_input++;
	}
	//printf("exit check reading mode : %d\n", lex->new_decision.lex_read_mode);
	//if (*lex->user_input == '\n')
	//	*lex->user_input = '\0';
	//printf("input_char : %c\n", *lex->user_input);
	//
	if (lex->new_decision.lex_read_mode != SYNT_ERR_LEX_RD_MD)
		ft_lex_apply_decision(lex);
	//printf("just after check reading mode : %d\n", lex->new_decision.lex_read_mode);
	if (lex->new_decision.lex_read_mode != SYNT_ERR_LEX_RD_MD)
		lex->token = lex->token->next;
	//lex->token = lex->token->next;
	//printf("end lexer\n");*/
	return (0);
}

int	ft_print_lexer_content(t_lex *lex)
{
	int	i;

	i = 0;
	printf("LEXER CONTENT\n");
	while (i++ < lex->nb_of_tokens + 10)
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
	printf("nb commands : %d\n", pars->nb_of_commands);
	while (i++ < pars->nb_of_commands)
	{
		printf("------> starting command id<%d> verif_id<%d>\n", i, pars->command->id);
		while (j++ < pars->command->nb_of_tokens)
		{
			//printf("here\n");
			//printf("lex->token->id : %s\n", lex->token->id);
			//printf("%s :%d: <%s>\n", lex->token->id, lex->token->id[0], ft_getlabel_token_types(lex->token->type));
			printf("%s <%s>\n", pars->command->token->id, ft_getlabel_token_types(pars->command->token->type));
			pars->command->token = pars->command->token->next;
		}
		pars->command = pars->command->next;
	}
	return (0);
}
