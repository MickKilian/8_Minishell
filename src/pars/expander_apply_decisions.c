/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander_apply_decisions.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 11:50:37 by mbourgeo          #+#    #+#             */
/*   Updated: 2022/10/06 15:45:50 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_exp_apply_decision(t_pars *pars)
{
	pars->prev_exp_decision = pars->new_exp_decision;
	//printf("\npars->prev_exp_decision\n");
	//ft_print_exp_proc(pars->prev_exp_decision);
	pars->new_exp_decision = pars->exp_decision[pars->prev_exp_decision.exp_read_mode][ft_char_type(pars->parser_text[0])];
	if (pars->new_exp_decision.buffer_action == EXP_ERR)
	{
		printf("entries are exp_read_mode: %d and char->type: %d\n", pars->prev_exp_decision.exp_read_mode, ft_char_type(pars->parser_text[0]));
		return (ft_msgerr(ERR_CASE), 1);
	}
	//printf("char : %c\n", pars->parser_text[0]);
	//printf("char type : %d\n", ft_char_type(pars->user_input[0]));
	//printf("member 1 : %d\n", pars->prev_exp_decision.exp_read_mode);
	//printf("member 2 : %d\n", ft_char_type(pars->parser_text[0]));
	//printf("\npars->new_exp_decision\n");
	//ft_print_exp_proc(pars->new_exp_decision);
	//printf("ready for action \n");
	//printf("buffer_action : %d\n", pars->new_exp_decision.buffer_action);
	//printf("exp_read_mode : %d\n", pars->new_exp_decision.exp_read_mode);
	//printf("wrk char is : %c, %d, %d, %d\n", pars->parser_text[0], pars->parser_text[0], pars->new_exp_decision.buffer_action, pars->new_exp_decision.char_action);
	pars->ft_exp[pars->new_exp_decision.buffer_action](pars);
	//printf("wrk char is : %c, %d, %d, %d\n", pars->parser_text[0], pars->parser_text[0], pars->new_exp_decision.buffer_action, pars->new_exp_decision.char_action);
	pars->ft_exp[pars->new_exp_decision.char_action](pars);
	//printf("wrk char is : %c, %d, %d, %d\n", pars->parser_text[0], pars->parser_text[0], pars->new_exp_decision.buffer_action, pars->new_exp_decision.char_action);
	//pars->lex_read_mode = pars->new_exp_decision.lex_read_mode;
	//pars->prev_exp_decision = pars->new_exp_decision;
	//printf("check read mode : %d\n", pars->prev_exp_decision.exp_read_mode);
	//printf("wrk char is : %c, %d, %d, %d\n", pars->parser_text[0], pars->parser_text[0], pars->new_exp_decision.buffer_action, pars->new_exp_decision.char_action);
	//ft_print_lex_proc(pars->new_exp_decision);
	return (0);
}

int	ft_print_exp_proc(t_exp_proc proc)
{
	printf("buffer_action : %d\n", proc.buffer_action);
	printf("char_action : %d\n", proc.char_action);
	printf("exp_read_mode : %d\n", proc.exp_read_mode);
	printf("token_type : %d\n", proc.token_type);
	return (0);
}
