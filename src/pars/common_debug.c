/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common_debug.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 00:47:14 by mbourgeo          #+#    #+#             */
/*   Updated: 2022/10/08 04:08:56 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_flag(void)
{
	printf("\033[37;1mHello World!\033[0m\n");
}

int	ft_print_debug_lex(t_lex *lex)
{
	printf("\033[33;2m");
	printf("\ndebug/LEXER\n");
	if (lex->new_decision.buffer_action == LEX_ERR)
		printf("\031[33;2m\n<- ERROR in LEXER -> \n\033[0m");
	printf("\033[33;2m");
	printf("char : \033[32;1m%c\033[0m\n", lex->user_input[0]);
	printf("\033[33;2m");
	printf("[1] : %s\n", ft_getlabel_lex_read_modes(lex->prev_decision.lex_read_mode));
	printf("[2] : %s\n", ft_getlabel_char_types(ft_char_type(lex->user_input[0])));
	printf("buffer_action : %s\n", ft_getlabel_lex_actions(lex->new_decision.buffer_action));
	printf("character_action : %s\n", ft_getlabel_lex_actions(lex->new_decision.char_action));
	printf("lex_read_mode : %s\n", ft_getlabel_lex_read_modes(lex->new_decision.lex_read_mode));
	printf("token_type : %s\n", ft_getlabel_token_types(lex->new_decision.token_type));
	printf("\033[0m\n");
	return (0);
}

int	ft_print_debug_pars(t_pars *pars)
{
	printf("\033[33;2m");
	printf("\ndebug/PARSER\n");
	if (pars->new_pars_decision.token_action == PARS_ERR)
		printf("\033[31;2m\n<- ERROR in PARSER -> \n\033[0m");
	printf("\033[33;2m");
	printf("[1] : %s\n", ft_getlabel_pars_read_modes(pars->prev_pars_decision.pars_read_mode));
	printf("[2] : %s\n", ft_getlabel_token_types(pars->token->type));
	printf("token_action : %s\n", ft_getlabel_pars_actions(pars->new_pars_decision.token_action));
	printf("list_action : %s\n", ft_getlabel_pars_actions(pars->new_pars_decision.pars_list_action));
	printf("pars_read_mode : %s\n", ft_getlabel_pars_read_modes(pars->new_pars_decision.pars_read_mode));
	printf("\033[0m\n");
	return (0);
}

int	ft_print_debug_exp(t_pars *pars)
{
	printf("\033[33;2m");
	printf("\ndebug/EXPANDER\n");
	if (pars->new_exp_decision.buffer_action == EXP_ERR)
		printf("\031[33;2m\n<- ERROR in EXPANDER -> \n\033[0m");
	printf("\033[33;2m");
	printf("char : \033[32;1m%c\033[0m\n", pars->parser_text[0]);
	printf("\033[33;2m");
	printf("[1] : %s\n", ft_getlabel_exp_read_modes(pars->prev_exp_decision.exp_read_mode));
	printf("[2] : %s\n", ft_getlabel_char_types(ft_char_type(pars->parser_text[0])));
	printf("buffer_action : %s\n", ft_getlabel_exp_actions(pars->new_exp_decision.buffer_action));
	printf("char_action : %s\n", ft_getlabel_exp_actions(pars->new_exp_decision.char_action));
	printf("exp_read_mode : %s\n", ft_getlabel_exp_read_modes(pars->new_exp_decision.exp_read_mode));
	printf("token_type : %s\n", ft_getlabel_token_types(pars->new_exp_decision.token_type));
	printf("\033[0m\n");
	return (0);
}

int	ft_print_debug_redir(t_pars *pars)
{
	printf("\033[33;2m");
	printf("\ndebug/REDIRECTOR\n");
	if (pars->new_redir_decision.token_action == REDIR_ERR)
		printf("\033[31;2m\n<- ERROR in REDIRECTOR -> \n\033[0m");
	printf("\033[33;2m");
	printf("[1] : %s\n", ft_getlabel_redir_read_modes(pars->prev_redir_decision.redir_read_mode));
	printf("[2] : %s\n", ft_getlabel_token_types(pars->token->type));
	printf("token_action : %s\n", ft_getlabel_redir_actions(pars->new_redir_decision.token_action));
	printf("list_action : %s\n", ft_getlabel_redir_actions(pars->new_redir_decision.redir_list_action));
	printf("redir_read_mode : %s\n", ft_getlabel_redir_read_modes(pars->new_redir_decision.redir_read_mode));
	printf("\033[0m\n");
	return (0);
}
