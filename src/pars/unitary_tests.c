/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unitary_tests.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 00:47:14 by mbourgeo          #+#    #+#             */
/*   Updated: 2022/10/08 17:25:44 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(void)
{
	if (ft_unitary_tests())
		return (1);
	return (0);
}

t_cmd	ft_read_prompt(char *user_input)
{
	t_lex		lex;
	t_pars		pars;
	char		*temp;

	lex.user_input = user_input;
	ft_bzero(lex, sizeof(t_lex));
	ft_bzero(pars, sizeof(t_pars));
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
	return (pars.cmd);
}

int	ft_unitary_tests(void)
{
	int			fd;

	fd = open("parser.test", O_RDONLY, 644);
	if (fd < 0)
		return (ft_msgerr(ERR_TESTFILE), 1);
	user_input = get_next_line(fd);
	temp = user_input;
	while (lex.user_input)
	{
		ft_read_prompt(user_input);
		user_input = get_next_line(fd);
		temp = user_input;
	}
	if (temp)
	{
		free(temp);
		temp = NULL;
	}
	close(fd);
	return (0);
}
