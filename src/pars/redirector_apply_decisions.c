/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirector_apply_decisions.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 11:50:37 by mbourgeo          #+#    #+#             */
/*   Updated: 2022/10/07 00:59:35 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_redir_apply_decision(t_pars *pars)
{
	pars->prev_redir_decision = pars->new_redir_decision;
	//printf("\npars->prev_redir_decision\n");
	//ft_print_redir_proc(pars->prev_redir_decision);
	//printf("read mode : %d\n", pars->prev_redir_decision.redir_read_mode);
	//printf("token type : %d\n", pars->token->type);
	pars->new_redir_decision = pars->redir_decision[pars->prev_redir_decision.redir_read_mode][pars->token->type];
	//printf("char : %d\n", pars->user_input[0]);
	//printf("char type : %d\n", ft_char_type(pars->user_input[0]));
	printf("\npars->new_redir_decision\n");
	ft_print_redir_proc(pars->new_redir_decision);
	if (pars->new_redir_decision.redir_list_action == REDIR_ERR)
	{
		printf("\033[33;2mentries are redir_read_mode: %s and token->type: %s\n\033[0m", ft_getlabel_redir_read_modes(pars->prev_redir_decision.redir_read_mode),
			ft_getlabel_token_types(pars->token->type));
		return (ft_msgerr(ERR_CASE), 1);
	}
	//if (pars->new_redir_decision.redir_list_action == REDIR_NEW)
	//	printf("\033[33;2mcalling ft_new from list_action\033[0m\n");
	pars->ft_redir[pars->new_redir_decision.redir_list_action](pars);
	//if (pars->new_redir_decision.token_action == REDIR_NEW)
	//	printf("\033[33;2mcalling ft_new from token_action\033[0m\n");
	pars->ft_redir[pars->new_redir_decision.token_action](pars);
	//pars->pars_read_mode = pars->new_redir_decision.lex_read_mode;
	//pars->prev_redir_decision = pars->new_redir_decision;
	//ft_print_redir_proc(pars->new_redir_decision);
	return (0);
}

int	ft_print_redir_proc(t_redir_proc proc)
{
	printf("list_action : %d\n", proc.redir_list_action);
	printf("token_action : %d\n", proc.token_action);
	printf("redir_read_mode : %d\n", proc.redir_read_mode);
	return (0);
}
