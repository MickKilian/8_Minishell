/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_apply_decision.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 11:50:37 by mbourgeo          #+#    #+#             */
/*   Updated: 2022/10/06 17:48:49 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_pars_apply_decision(t_pars *pars)
{
	pars->prev_pars_decision = pars->new_pars_decision;
	//printf("\npars->prev_pars_decision\n");
	//ft_print_pars_proc(pars->prev_pars_decision);
	//printf("read mode : %d\n", pars->prev_pars_decision.pars_read_mode);
	//printf("token type : %d\n", pars->token->type);
	pars->new_pars_decision = pars->pars_decision[pars->prev_pars_decision.pars_read_mode][pars->token->type];
	//printf("char : %d\n", pars->user_input[0]);
	//printf("char type : %d\n", ft_char_type(pars->user_input[0]));
	if (pars->new_pars_decision.pars_list_action == PARS_ERR)
	{
		printf("\033[33;2mentries are pars_read_mode: %s and token->type: %s\n\033[0m", ft_getlabel_pars_read_modes(pars->prev_pars_decision.pars_read_mode),
			ft_getlabel_token_types(pars->token->type));
		return (ft_msgerr(ERR_CASE), 1);
	}
	//printf("\npars->new_pars_decision\n");
	//ft_print_pars_proc(pars->new_pars_decision);
	//if (pars->new_pars_decision.pars_list_action == PARS_NEW)
	//	printf("\033[33;2mcalling ft_new from list_action\033[0m\n");
	pars->ft_pars[pars->new_pars_decision.pars_list_action](pars);
	//if (pars->new_pars_decision.token_action == PARS_NEW)
	//	printf("\033[33;2mcalling ft_new from token_action\033[0m\n");
	pars->ft_pars[pars->new_pars_decision.token_action](pars);
	//pars->pars_read_mode = pars->new_pars_decision.lex_read_mode;
	//pars->prev_pars_decision = pars->new_pars_decision;
	//ft_print_pars_proc(pars->new_pars_decision);
	return (0);
}

int	ft_print_pars_proc(t_pars_proc proc)
{
	printf("list_action : %d\n", proc.pars_list_action);
	printf("token_action : %d\n", proc.token_action);
	printf("pars_read_mode : %d\n", proc.pars_read_mode);
	return (0);
}
