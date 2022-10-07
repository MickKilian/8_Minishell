/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirector_init_decisions.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 00:47:14 by mbourgeo          #+#    #+#             */
/*   Updated: 2022/10/08 00:14:38 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_init_redir_decision_1(t_pars *pars)
{
	pars->redir_decision[NEW_REDIR_RD_MD][TOK_WORD] = (t_redir_proc){REDIR_KEEP, REDIR_KEEP, STD_REDIR_RD_MD};
	pars->redir_decision[NEW_REDIR_RD_MD][TOK_LSS] = (t_redir_proc){REDIR_IN, REDIR_DEL_TWO, STD_REDIR_RD_MD};
	pars->redir_decision[NEW_REDIR_RD_MD][TOK_GRT] = (t_redir_proc){REDIR_OUT, REDIR_DEL_TWO, STD_REDIR_RD_MD};
	pars->redir_decision[NEW_REDIR_RD_MD][TOK_GGRT] = (t_redir_proc){REDIR_OUT_APPEND, REDIR_DEL_TWO, STD_REDIR_RD_MD};
	pars->redir_decision[NEW_REDIR_RD_MD][TOK_ERR_SPL] = (t_redir_proc){REDIR_KEEP, REDIR_KEEP, STD_REDIR_RD_MD};
	pars->redir_decision[NEW_REDIR_RD_MD][TOK_ERR_DBL] = (t_redir_proc){REDIR_KEEP, REDIR_KEEP, STD_REDIR_RD_MD};
	pars->redir_decision[STD_REDIR_RD_MD][TOK_WORD] = (t_redir_proc){REDIR_KEEP, REDIR_KEEP, STD_REDIR_RD_MD};
	pars->redir_decision[STD_REDIR_RD_MD][TOK_LSS] = (t_redir_proc){REDIR_IN, REDIR_DEL_TWO, STD_REDIR_RD_MD};
	pars->redir_decision[STD_REDIR_RD_MD][TOK_GRT] = (t_redir_proc){REDIR_OUT, REDIR_DEL_TWO, STD_REDIR_RD_MD};
	pars->redir_decision[STD_REDIR_RD_MD][TOK_GGRT] = (t_redir_proc){REDIR_OUT_APPEND, REDIR_DEL_TWO, STD_REDIR_RD_MD};
	return (0);
}

int	ft_init_redir_decision_2(t_pars *pars)
{
	(void)pars;
	return (0);
}

int	ft_init_redir_decision_3(t_pars *pars)
{
	(void)pars;
	return (0);
}

int	ft_init_redir_decision_4(t_pars *pars)
{
	(void)pars;
	return (0);
}

int	ft_init_redir_decision_5(t_pars *pars)
{
	(void)pars;
	return (0);
}

int	ft_init_redir_decision_6(t_pars *pars)
{
	(void)pars;
	return (0);
}

int	ft_init_redir_decision_7(t_pars *pars)
{
	(void)pars;
	return (0);
}
