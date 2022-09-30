/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander_apply_decisions.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 11:50:37 by mbourgeo          #+#    #+#             */
/*   Updated: 2022/09/30 15:35:21 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_exp_apply_decision(t_pars *pars)
{
	//printf("\npars->prev_exp_decision\n");
	//ft_print_exp_proc(pars->prev_exp_decision);
	pars->new_exp_decision = pars->exp_decision[pars->prev_exp_decision.exp_read_mode][ft_char_type(pars->temp[0])];
	//printf("char : %d\n", pars->user_input[0]);
	//printf("char type : %d\n", ft_char_type(pars->user_input[0]));
	//printf("\npars->new_exp_decision\n");
	//ft_print_exp_proc(pars->new_exp_decision);
	pars->ft_exp[pars->new_exp_decision.buffer_action](pars);
	pars->ft_exp[pars->new_exp_decision.char_action](pars);
	//pars->lex_read_mode = pars->new_exp_decision.lex_read_mode;
	pars->prev_exp_decision = pars->new_exp_decision;
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
