/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander_init_decisions.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 00:47:14 by mbourgeo          #+#    #+#             */
/*   Updated: 2022/10/07 23:40:22 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_init_exp_decision_1(t_pars *pars)
{
	//pars->exp_decision[NEW_EXP_RD_MD][TOK_NEW] = (t_exp_proc){EXP_KEEP, EXP_SKIP, NEW_EXP_RD_MD};
	pars->exp_decision[NEW_EXP_RD_MD][SEP_CHAR] = (t_exp_proc){EXP_KEEP, EXP_SKIP, NEW_EXP_RD_MD, TOK_NEW};
	pars->exp_decision[NEW_EXP_RD_MD][STD_CHAR] = (t_exp_proc){EXP_KEEP, EXP_TAKE, STD_EXP_RD_MD, TOK_WORD};
	pars->exp_decision[NEW_EXP_RD_MD][SPL_CHAR] = (t_exp_proc){EXP_KEEP, EXP_SKIP, SPL_EXP_RD_MD, TOK_WORD};
	pars->exp_decision[NEW_EXP_RD_MD][DBL_CHAR] = (t_exp_proc){EXP_KEEP, EXP_SKIP, DBL_EXP_RD_MD, TOK_WORD};
	pars->exp_decision[NEW_EXP_RD_MD][DOL_CHAR] = (t_exp_proc){EXP_DOL, EXP_SKIP, DOL_EXP_RD_MD, TOK_WORD};
	pars->exp_decision[NEW_EXP_RD_MD][END_CHAR] = (t_exp_proc){EXP_NONE, EXP_SKIP, ERR_EXP_RD_MD, TOK_WORD};
//	pars->exp_decision[NEW_EXP_RD_MD][TOK_WORD] = (t_exp_proc){EXP_ANALYSIS, EXP_TAKE, STD_EXP_RD_MD};
//	pars->exp_decision[NEW_EXP_RD_MD][TOK_AMP] = (t_exp_proc){EXP_KEEP, EXP_TAKE, AMP_EXP_RD_MD};
//	pars->exp_decision[NEW_EXP_RD_MD][TOK_LSS] = (t_exp_proc){EXP_KEEP, EXP_TAKE, LT_EXP_RD_MD};
//	pars->exp_decision[NEW_EXP_RD_MD][TOK_GRT] = (t_exp_proc){EXP_KEEP, EXP_TAKE, GT_EXP_RD_MD};
//	pars->exp_decision[NEW_EXP_RD_MD][TOK_END_OF_INPUT] = (t_exp_proc){EXP_END, EXP_SKIP, NEW_EXP_RD_MD};
	//pars->exp_decision[STD_EXP_RD_MD][TOK_NEW] = (t_exp_proc){EXP_KEEP, EXP_SKIP, NEW_EXP_RD_MD};
	pars->exp_decision[STD_EXP_RD_MD][SEP_CHAR] = (t_exp_proc){EXP_KEEP, EXP_SKIP, NEW_EXP_RD_MD, TOK_WORD};
	pars->exp_decision[STD_EXP_RD_MD][STD_CHAR] = (t_exp_proc){EXP_KEEP, EXP_TAKE, STD_EXP_RD_MD, TOK_WORD};
	pars->exp_decision[STD_EXP_RD_MD][SPL_CHAR] = (t_exp_proc){EXP_REC, EXP_SKIP, SPL_EXP_RD_MD, TOK_WORD};
	pars->exp_decision[STD_EXP_RD_MD][DBL_CHAR] = (t_exp_proc){EXP_REC, EXP_SKIP, DBL_EXP_RD_MD, TOK_WORD};
	pars->exp_decision[STD_EXP_RD_MD][DOL_CHAR] = (t_exp_proc){EXP_DOL, EXP_SKIP, DOL_EXP_RD_MD, TOK_WORD};
	pars->exp_decision[STD_EXP_RD_MD][END_CHAR] = (t_exp_proc){EXP_CATCH, EXP_SKIP, NEW_EXP_RD_MD, TOK_WORD};
//	pars->exp_decision[STD_EXP_RD_MD][TOK_WORD] = (t_exp_proc){EXP_ANALYSIS, EXP_TAKE, STD_EXP_RD_MD};
//	pars->exp_decision[STD_EXP_RD_MD][TOK_AMP] = (t_exp_proc){EXP_KEEP, EXP_TAKE, AMP_EXP_RD_MD};
//	pars->exp_decision[STD_EXP_RD_MD][TOK_LSS] = (t_exp_proc){EXP_KEEP, EXP_TAKE, LT_EXP_RD_MD};
//	pars->exp_decision[STD_EXP_RD_MD][TOK_GRT] = (t_exp_proc){EXP_KEEP, EXP_TAKE, GT_EXP_RD_MD};
//	pars->exp_decision[STD_EXP_RD_MD][TOK_END_OF_INPUT] = (t_exp_proc){EXP_END, EXP_SKIP, NEW_EXP_RD_MD};
	return (0);
}

int	ft_init_exp_decision_2(t_pars *pars)
{
	pars->exp_decision[SPL_EXP_RD_MD][SEP_CHAR] = (t_exp_proc){EXP_KEEP, EXP_TAKE, SPL_EXP_RD_MD, TOK_WORD};
	pars->exp_decision[SPL_EXP_RD_MD][STD_CHAR] = (t_exp_proc){EXP_KEEP, EXP_TAKE, SPL_EXP_RD_MD, TOK_WORD};
	pars->exp_decision[SPL_EXP_RD_MD][SPL_CHAR] = (t_exp_proc){EXP_REC, EXP_SKIP, STD_EXP_RD_MD, TOK_WORD};
	pars->exp_decision[SPL_EXP_RD_MD][DBL_CHAR] = (t_exp_proc){EXP_KEEP, EXP_TAKE, SPL_EXP_RD_MD, TOK_WORD};
	pars->exp_decision[SPL_EXP_RD_MD][DOL_CHAR] = (t_exp_proc){EXP_KEEP, EXP_TAKE, SPL_EXP_RD_MD, TOK_WORD};
	pars->exp_decision[SPL_EXP_RD_MD][END_CHAR] = (t_exp_proc){EXP_NONE, EXP_SKIP, ERR_EXP_RD_MD, TOK_ERR_SPL};
	pars->exp_decision[DBL_EXP_RD_MD][SEP_CHAR] = (t_exp_proc){EXP_KEEP, EXP_TAKE, DBL_EXP_RD_MD, TOK_WORD};
	pars->exp_decision[DBL_EXP_RD_MD][STD_CHAR] = (t_exp_proc){EXP_KEEP, EXP_TAKE, DBL_EXP_RD_MD, TOK_WORD};
	pars->exp_decision[DBL_EXP_RD_MD][SPL_CHAR] = (t_exp_proc){EXP_KEEP, EXP_TAKE, DBL_EXP_RD_MD, TOK_WORD};
	pars->exp_decision[DBL_EXP_RD_MD][DBL_CHAR] = (t_exp_proc){EXP_REC, EXP_SKIP, STD_EXP_RD_MD, TOK_WORD};
	pars->exp_decision[DBL_EXP_RD_MD][DOL_CHAR] = (t_exp_proc){EXP_DOL, EXP_SKIP, DOL_EXP_RD_MD, TOK_WORD};
	pars->exp_decision[DBL_EXP_RD_MD][END_CHAR] = (t_exp_proc){EXP_ERR_DBL, EXP_SKIP, ERR_EXP_RD_MD, TOK_ERR_DBL};
	//pars->exp_decision[NEW_EXP_RD_MD][TOK_NEW] = (t_exp_proc){EXP_KEEP, EXP_SKIP, NEW_EXP_RD_MD};
	/*pars->exp_decision[NEW_EXP_RD_MD][TOK_WORD] = (t_exp_proc){EXP_KEEP, EXP_TAKE, STD_EXP_RD_MD};
	pars->exp_decision[NEW_EXP_RD_MD][TOK_PIPE] = (t_exp_proc){EXP_CATCH, EXP_SKIP, NEW_EXP_RD_MD};
	pars->exp_decision[NEW_EXP_RD_MD][TOK_AMP] = (t_exp_proc){EXP_KEEP, EXP_TAKE, AMP_EXP_RD_MD};
	pars->exp_decision[NEW_EXP_RD_MD][TOK_LSS] = (t_exp_proc){EXP_KEEP, EXP_TAKE, LT_EXP_RD_MD};
	pars->exp_decision[NEW_EXP_RD_MD][TOK_GRT] = (t_exp_proc){EXP_KEEP, EXP_TAKE, GT_EXP_RD_MD};
	pars->exp_decision[NEW_EXP_RD_MD][TOK_END_OF_INPUT] = (t_exp_proc){EXP_END, EXP_SKIP, NEW_EXP_RD_MD};
	*/
	return (0);
}

int	ft_init_exp_decision_3(t_pars *pars)
{
	pars->exp_decision[DOL_EXP_RD_MD][SEP_CHAR] = (t_exp_proc){EXP_DOL, EXP_TAKE, NEW_EXP_RD_MD, TOK_WORD};
	pars->exp_decision[DOL_EXP_RD_MD][STD_CHAR] = (t_exp_proc){EXP_KEEP, EXP_TAKE, DOL_EXP_RD_MD, TOK_WORD};
	pars->exp_decision[DOL_EXP_RD_MD][SPL_CHAR] = (t_exp_proc){EXP_DOL, EXP_SKIP, SPL_EXP_RD_MD, TOK_WORD};
	pars->exp_decision[DOL_EXP_RD_MD][DBL_CHAR] = (t_exp_proc){EXP_DOL, EXP_SKIP, DBL_EXP_RD_MD, TOK_WORD};
	pars->exp_decision[DOL_EXP_RD_MD][DOL_CHAR] = (t_exp_proc){EXP_DOL, EXP_SKIP, DOL_EXP_RD_MD, TOK_WORD};
	pars->exp_decision[DOL_EXP_RD_MD][END_CHAR] = (t_exp_proc){EXP_DOL, EXP_CATCH, NEW_EXP_RD_MD, TOK_WORD};
/*	pars->exp_decision[ESCP_EXP_RD_MD][SEP_CHAR] = (t_exp_proc){EXP_KEEP, EXP_SKIP, NEW_EXP_RD_MD, TOK_NEW};
	pars->exp_decision[ESCP_EXP_RD_MD][STD_CHAR] = (t_exp_proc){EXP_KEEP, EXP_TAKE, STD_EXP_RD_MD, TOK_WORD};
	pars->exp_decision[ESCP_EXP_RD_MD][SPL_CHAR] = (t_exp_proc){EXP_CATCH, EXP_SKIP, SPL_EXP_RD_MD, TOK_WORD};
	pars->exp_decision[ESCP_EXP_RD_MD][DBL_CHAR] = (t_exp_proc){EXP_CATCH, EXP_SKIP, DBL_EXP_RD_MD, TOK_WORD};
	pars->exp_decision[ESCP_EXP_RD_MD][ESCP_CHAR] = (t_exp_proc){EXP_KEEP, EXP_SKIP, ESCP_EXP_RD_MD, TOK_NEW};
	pars->exp_decision[ESCP_EXP_RD_MD][PIPE_CHAR] = (t_exp_proc){EXP_DROP, EXP_SKIP, ERR_EXP_RD_MD, TOK_NEW};
	pars->exp_decision[ESCP_EXP_RD_MD][AMP_CHAR] = (t_exp_proc){EXP_DROP, EXP_SKIP, ERR_EXP_RD_MD, TOK_NEW};
	pars->exp_decision[ESCP_EXP_RD_MD][LT_CHAR] = (t_exp_proc){EXP_DROP, EXP_TAKE, ERR_EXP_RD_MD, TOK_NEW};
	pars->exp_decision[ESCP_EXP_RD_MD][GT_CHAR] = (t_exp_proc){EXP_DROP, EXP_TAKE, ERR_EXP_RD_MD, TOK_NEW};
	pars->exp_decision[ESCP_EXP_RD_MD][END_CHAR] = (t_exp_proc){EXP_CATCH, EXP_SKIP, NEW_EXP_RD_MD, TOK_NEW};
	pars->exp_decision[PIPE_EXP_RD_MD][SEP_CHAR] = (t_exp_proc){EXP_CATCH, EXP_SKIP, NEW_EXP_RD_MD, TOK_NEW};
	pars->exp_decision[PIPE_EXP_RD_MD][STD_CHAR] = (t_exp_proc){EXP_CATCH, EXP_TAKE, STD_EXP_RD_MD, TOK_WORD};
	pars->exp_decision[PIPE_EXP_RD_MD][SPL_CHAR] = (t_exp_proc){EXP_CATCH, EXP_SKIP, SPL_EXP_RD_MD, TOK_WORD};
	pars->exp_decision[PIPE_EXP_RD_MD][DBL_CHAR] = (t_exp_proc){EXP_CATCH, EXP_SKIP, DBL_EXP_RD_MD, TOK_WORD};
	pars->exp_decision[PIPE_EXP_RD_MD][ESCP_CHAR] = (t_exp_proc){EXP_CATCH, EXP_SKIP, ESCP_EXP_RD_MD, TOK_NEW};
	pars->exp_decision[PIPE_EXP_RD_MD][PIPE_CHAR] = (t_exp_proc){EXP_KEEP, EXP_TAKE, OR_EXP_RD_MD, TOK_OP_OR};
//check following case
	pars->exp_decision[PIPE_EXP_RD_MD][AMP_CHAR] = (t_exp_proc){EXP_CATCH, EXP_TAKE, AMP_EXP_RD_MD, TOK_AMP};
	pars->exp_decision[PIPE_EXP_RD_MD][LT_CHAR] = (t_exp_proc){EXP_KEEP, EXP_TAKE, ERR_EXP_RD_MD, TOK_NEW};
	pars->exp_decision[PIPE_EXP_RD_MD][GT_CHAR] = (t_exp_proc){EXP_KEEP, EXP_TAKE, ERR_EXP_RD_MD, TOK_NEW};
	pars->exp_decision[PIPE_EXP_RD_MD][END_CHAR] = (t_exp_proc){EXP_DROP, EXP_SKIP, ERR_EXP_RD_MD, TOK_NEW};
	*/
	return (0);
}

int	ft_init_exp_decision_4(t_pars *pars)
{
	(void)pars;
/*	pars->exp_decision[AMP_EXP_RD_MD][SEP_CHAR] = (t_exp_proc){EXP_CATCH, EXP_SKIP, NEW_EXP_RD_MD, TOK_NEW};
	pars->exp_decision[AMP_EXP_RD_MD][STD_CHAR] = (t_exp_proc){EXP_CATCH, EXP_TAKE, STD_EXP_RD_MD, TOK_WORD};
	pars->exp_decision[AMP_EXP_RD_MD][SPL_CHAR] = (t_exp_proc){EXP_CATCH, EXP_SKIP, ERR_EXP_RD_MD, TOK_NEW};
	pars->exp_decision[AMP_EXP_RD_MD][DBL_CHAR] = (t_exp_proc){EXP_DROP, EXP_SKIP, ERR_EXP_RD_MD, TOK_NEW};
	pars->exp_decision[AMP_EXP_RD_MD][ESCP_CHAR] = (t_exp_proc){EXP_CATCH, EXP_SKIP, ESCP_EXP_RD_MD, TOK_NEW};
	pars->exp_decision[AMP_EXP_RD_MD][PIPE_CHAR] = (t_exp_proc){EXP_DROP, EXP_SKIP, ERR_EXP_RD_MD, TOK_NEW};
	pars->exp_decision[AMP_EXP_RD_MD][AMP_CHAR] = (t_exp_proc){EXP_KEEP, EXP_TAKE, AND_EXP_RD_MD, TOK_OP_AND};
	pars->exp_decision[AMP_EXP_RD_MD][LT_CHAR] = (t_exp_proc){EXP_DROP, EXP_SKIP, ERR_EXP_RD_MD, TOK_NEW};
	pars->exp_decision[AMP_EXP_RD_MD][GT_CHAR] = (t_exp_proc){EXP_DROP, EXP_SKIP, ERR_EXP_RD_MD, TOK_NEW};
	pars->exp_decision[AMP_EXP_RD_MD][END_CHAR] = (t_exp_proc){EXP_DROP, EXP_SKIP, ERR_EXP_RD_MD, TOK_NEW};
	pars->exp_decision[LT_EXP_RD_MD][SEP_CHAR] = (t_exp_proc){EXP_CATCH, EXP_SKIP, NEW_EXP_RD_MD, TOK_NEW};
	pars->exp_decision[LT_EXP_RD_MD][STD_CHAR] = (t_exp_proc){EXP_CATCH, EXP_TAKE, STD_EXP_RD_MD, TOK_WORD};
	pars->exp_decision[LT_EXP_RD_MD][SPL_CHAR] = (t_exp_proc){EXP_CATCH, EXP_SKIP, SPL_EXP_RD_MD, TOK_WORD};
	pars->exp_decision[LT_EXP_RD_MD][DBL_CHAR] = (t_exp_proc){EXP_CATCH, EXP_SKIP, DBL_EXP_RD_MD, TOK_WORD};
	pars->exp_decision[LT_EXP_RD_MD][ESCP_CHAR] = (t_exp_proc){EXP_CATCH, EXP_SKIP, ESCP_EXP_RD_MD, TOK_NEW};
	pars->exp_decision[LT_EXP_RD_MD][PIPE_CHAR] = (t_exp_proc){EXP_DROP, EXP_SKIP, ERR_EXP_RD_MD, TOK_NEW};
	pars->exp_decision[LT_EXP_RD_MD][AMP_CHAR] = (t_exp_proc){EXP_DROP, EXP_SKIP, ERR_EXP_RD_MD, TOK_NEW};
	pars->exp_decision[LT_EXP_RD_MD][LT_CHAR] = (t_exp_proc){EXP_KEEP, EXP_TAKE, HEREDOC_EXP_RD_MD, TOK_HEREDOC};
	pars->exp_decision[LT_EXP_RD_MD][GT_CHAR] = (t_exp_proc){EXP_DROP, EXP_SKIP, ERR_EXP_RD_MD, TOK_WORD};
	pars->exp_decision[LT_EXP_RD_MD][END_CHAR] = (t_exp_proc){EXP_CATCH, EXP_SKIP, NEW_EXP_RD_MD, TOK_NEW};
	*/
	return (0);
}

int	ft_init_exp_decision_5(t_pars *pars)
{
	(void)pars;
/*	pars->exp_decision[GT_EXP_RD_MD][SEP_CHAR] = (t_exp_proc){EXP_CATCH, EXP_SKIP, NEW_EXP_RD_MD, TOK_NEW};
	pars->exp_decision[GT_EXP_RD_MD][STD_CHAR] = (t_exp_proc){EXP_CATCH, EXP_TAKE, STD_EXP_RD_MD, TOK_WORD};
	pars->exp_decision[GT_EXP_RD_MD][SPL_CHAR] = (t_exp_proc){EXP_CATCH, EXP_SKIP, SPL_EXP_RD_MD, TOK_WORD};
	pars->exp_decision[GT_EXP_RD_MD][DBL_CHAR] = (t_exp_proc){EXP_CATCH, EXP_SKIP, SPL_EXP_RD_MD, TOK_WORD};
	pars->exp_decision[GT_EXP_RD_MD][ESCP_CHAR] = (t_exp_proc){EXP_CATCH, EXP_SKIP, ESCP_EXP_RD_MD, TOK_NEW};
	pars->exp_decision[GT_EXP_RD_MD][PIPE_CHAR] = (t_exp_proc){EXP_CATCH, EXP_SKIP, ERR_EXP_RD_MD, TOK_NEW};
	pars->exp_decision[GT_EXP_RD_MD][AMP_CHAR] = (t_exp_proc){EXP_CATCH, EXP_SKIP, ERR_EXP_RD_MD, TOK_NEW};
	pars->exp_decision[GT_EXP_RD_MD][LT_CHAR] = (t_exp_proc){EXP_CATCH, EXP_SKIP, ERR_EXP_RD_MD, TOK_NEW};
	pars->exp_decision[GT_EXP_RD_MD][GT_CHAR] = (t_exp_proc){EXP_KEEP, EXP_TAKE, GGRT_EXP_RD_MD, TOK_GGRT};
	pars->exp_decision[GT_EXP_RD_MD][END_CHAR] = (t_exp_proc){EXP_CATCH, EXP_SKIP, NEW_EXP_RD_MD, TOK_NEW};
	pars->exp_decision[OR_EXP_RD_MD][SEP_CHAR] = (t_exp_proc){EXP_CATCH, EXP_SKIP, NEW_EXP_RD_MD, TOK_NEW};
	pars->exp_decision[OR_EXP_RD_MD][STD_CHAR] = (t_exp_proc){EXP_CATCH, EXP_TAKE, STD_EXP_RD_MD, TOK_WORD};
	pars->exp_decision[OR_EXP_RD_MD][SPL_CHAR] = (t_exp_proc){EXP_CATCH, EXP_SKIP, ERR_EXP_RD_MD, TOK_NEW};
	pars->exp_decision[OR_EXP_RD_MD][DBL_CHAR] = (t_exp_proc){EXP_DROP, EXP_SKIP, ERR_EXP_RD_MD, TOK_NEW};
	pars->exp_decision[OR_EXP_RD_MD][ESCP_CHAR] = (t_exp_proc){EXP_CATCH, EXP_SKIP, ESCP_EXP_RD_MD, TOK_NEW};
	pars->exp_decision[OR_EXP_RD_MD][PIPE_CHAR] = (t_exp_proc){EXP_DROP, EXP_SKIP, ERR_EXP_RD_MD, TOK_NEW};
	pars->exp_decision[OR_EXP_RD_MD][AMP_CHAR] = (t_exp_proc){EXP_CATCH, EXP_TAKE, AND_EXP_RD_MD, TOK_OP_AND};
	pars->exp_decision[OR_EXP_RD_MD][LT_CHAR] = (t_exp_proc){EXP_DROP, EXP_SKIP, ERR_EXP_RD_MD, TOK_NEW};
	pars->exp_decision[OR_EXP_RD_MD][GT_CHAR] = (t_exp_proc){EXP_DROP, EXP_SKIP, ERR_EXP_RD_MD, TOK_NEW};
	pars->exp_decision[OR_EXP_RD_MD][END_CHAR] = (t_exp_proc){EXP_CATCH, EXP_SKIP, NEW_EXP_RD_MD, TOK_NEW};
	*/
	return (0);
}

int	ft_init_exp_decision_6(t_pars *pars)
{
	(void)pars;
/*	pars->exp_decision[AND_EXP_RD_MD][SEP_CHAR] = (t_exp_proc){EXP_CATCH, EXP_SKIP, NEW_EXP_RD_MD, TOK_NEW};
	pars->exp_decision[AND_EXP_RD_MD][STD_CHAR] = (t_exp_proc){EXP_CATCH, EXP_TAKE, STD_EXP_RD_MD, TOK_WORD};
	pars->exp_decision[AND_EXP_RD_MD][SPL_CHAR] = (t_exp_proc){EXP_CATCH, EXP_SKIP, SPL_EXP_RD_MD, TOK_WORD};
	pars->exp_decision[AND_EXP_RD_MD][DBL_CHAR] = (t_exp_proc){EXP_CATCH, EXP_SKIP, DBL_EXP_RD_MD, TOK_WORD};
	pars->exp_decision[AND_EXP_RD_MD][ESCP_CHAR] = (t_exp_proc){EXP_CATCH, EXP_SKIP, ESCP_EXP_RD_MD, TOK_NEW};
	pars->exp_decision[AND_EXP_RD_MD][PIPE_CHAR] = (t_exp_proc){EXP_DROP, EXP_SKIP, ERR_EXP_RD_MD, TOK_NEW};
	pars->exp_decision[AND_EXP_RD_MD][AMP_CHAR] = (t_exp_proc){EXP_DROP, EXP_SKIP, ERR_EXP_RD_MD, TOK_NEW};
	pars->exp_decision[AND_EXP_RD_MD][LT_CHAR] = (t_exp_proc){EXP_KEEP, EXP_TAKE, HEREDOC_EXP_RD_MD, TOK_HEREDOC};
	pars->exp_decision[AND_EXP_RD_MD][GT_CHAR] = (t_exp_proc){EXP_DROP, EXP_SKIP, ERR_EXP_RD_MD, TOK_WORD};
	pars->exp_decision[AND_EXP_RD_MD][END_CHAR] = (t_exp_proc){EXP_DROP, EXP_SKIP, ERR_EXP_RD_MD, TOK_NEW};
	pars->exp_decision[HEREDOC_EXP_RD_MD][SEP_CHAR] = (t_exp_proc){EXP_CATCH, EXP_SKIP, NEW_EXP_RD_MD, TOK_NEW};
	pars->exp_decision[HEREDOC_EXP_RD_MD][STD_CHAR] = (t_exp_proc){EXP_CATCH, EXP_TAKE, STD_EXP_RD_MD, TOK_WORD};
	pars->exp_decision[HEREDOC_EXP_RD_MD][SPL_CHAR] = (t_exp_proc){EXP_CATCH, EXP_SKIP, SPL_EXP_RD_MD, TOK_WORD};
	pars->exp_decision[HEREDOC_EXP_RD_MD][DBL_CHAR] = (t_exp_proc){EXP_CATCH, EXP_SKIP, DBL_EXP_RD_MD, TOK_WORD};
	pars->exp_decision[HEREDOC_EXP_RD_MD][ESCP_CHAR] = (t_exp_proc){EXP_KEEP, EXP_SKIP, ESCP_EXP_RD_MD, TOK_NEW};
	pars->exp_decision[HEREDOC_EXP_RD_MD][PIPE_CHAR] = (t_exp_proc){EXP_DROP, EXP_SKIP, ERR_EXP_RD_MD, TOK_NEW};
	pars->exp_decision[HEREDOC_EXP_RD_MD][AMP_CHAR] = (t_exp_proc){EXP_DROP, EXP_SKIP, ERR_EXP_RD_MD, TOK_NEW};
	pars->exp_decision[HEREDOC_EXP_RD_MD][LT_CHAR] = (t_exp_proc){EXP_DROP, EXP_TAKE, ERR_EXP_RD_MD, TOK_NEW};
	pars->exp_decision[HEREDOC_EXP_RD_MD][GT_CHAR] = (t_exp_proc){EXP_DROP, EXP_TAKE, ERR_EXP_RD_MD, TOK_NEW};
	pars->exp_decision[HEREDOC_EXP_RD_MD][END_CHAR] = (t_exp_proc){EXP_CATCH, EXP_SKIP, NEW_EXP_RD_MD, TOK_NEW};
	*/
	return (0);
}

int	ft_init_exp_decision_7(t_pars *pars)
{
	(void)pars;
/*	pars->exp_decision[GGRT_EXP_RD_MD][SEP_CHAR] = (t_exp_proc){EXP_CATCH, EXP_SKIP, NEW_EXP_RD_MD, TOK_NEW};
	pars->exp_decision[GGRT_EXP_RD_MD][STD_CHAR] = (t_exp_proc){EXP_CATCH, EXP_TAKE, STD_EXP_RD_MD, TOK_WORD};
	pars->exp_decision[GGRT_EXP_RD_MD][SPL_CHAR] = (t_exp_proc){EXP_CATCH, EXP_SKIP, SPL_EXP_RD_MD, TOK_WORD};
	pars->exp_decision[GGRT_EXP_RD_MD][DBL_CHAR] = (t_exp_proc){EXP_CATCH, EXP_SKIP, SPL_EXP_RD_MD, TOK_WORD};
	pars->exp_decision[GGRT_EXP_RD_MD][ESCP_CHAR] = (t_exp_proc){EXP_CATCH, EXP_SKIP, ESCP_EXP_RD_MD, TOK_NEW};
	pars->exp_decision[GGRT_EXP_RD_MD][PIPE_CHAR] = (t_exp_proc){EXP_CATCH, EXP_SKIP, ERR_EXP_RD_MD, TOK_NEW};
	pars->exp_decision[GGRT_EXP_RD_MD][AMP_CHAR] = (t_exp_proc){EXP_CATCH, EXP_SKIP, ERR_EXP_RD_MD, TOK_NEW};
	pars->exp_decision[GGRT_EXP_RD_MD][LT_CHAR] = (t_exp_proc){EXP_CATCH, EXP_SKIP, ERR_EXP_RD_MD, TOK_NEW};
	pars->exp_decision[GGRT_EXP_RD_MD][GT_CHAR] = (t_exp_proc){EXP_CATCH, EXP_SKIP, SPL_EXP_RD_MD, TOK_GGRT};
	pars->exp_decision[GGRT_EXP_RD_MD][END_CHAR] = (t_exp_proc){EXP_CATCH, EXP_SKIP, NEW_EXP_RD_MD, TOK_NEW};
	*/
	return (0);
}
