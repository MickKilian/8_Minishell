/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_init_decisions.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 00:47:14 by mbourgeo          #+#    #+#             */
/*   Updated: 2022/09/28 11:33:33 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_init_pars_decision_1(t_pars *pars)
{
	pars->decision[NEW_PARS_RD_MD][TOK_NEW] = (t_pars_proc){PARS_KEEP, PARS_SKIP, NEW_PARS_RD_MD};
	pars->decision[NEW_PARS_RD_MD][TOK_WORD] = (t_pars_proc){PARS_KEEP, PARS_TAKE, STD_PARS_RD_MD};
	pars->decision[NEW_PARS_RD_MD][TOK_PIPE] = (t_pars_proc){PARS_CATCH, PARS_SKIP, NEW_PARS_RD_MD};
	pars->decision[NEW_PARS_RD_MD][TOK_AMP] = (t_pars_proc){PARS_KEEP, PARS_TAKE, AMP_PARS_RD_MD};
	pars->decision[NEW_PARS_RD_MD][TOK_LSS] = (t_pars_proc){PARS_KEEP, PARS_TAKE, LT_PARS_RD_MD};
	pars->decision[NEW_PARS_RD_MD][TOK_GRT] = (t_pars_proc){PARS_KEEP, PARS_TAKE, GT_PARS_RD_MD};
	pars->decision[NEW_PARS_RD_MD][TOK_END_OF_INPUT] = (t_pars_proc){PARS_END, PARS_SKIP, NEW_PARS_RD_MD};
	pars->decision[STD_PARS_RD_MD][TOK_NEW] = (t_pars_proc){PARS_KEEP, PARS_SKIP, NEW_PARS_RD_MD};
	pars->decision[STD_PARS_RD_MD][TOK_WORD] = (t_pars_proc){PARS_KEEP, PARS_TAKE, STD_PARS_RD_MD};
	pars->decision[STD_PARS_RD_MD][TOK_PIPE] = (t_pars_proc){PARS_CATCH, PARS_SKIP, NEW_PARS_RD_MD};
	pars->decision[STD_PARS_RD_MD][TOK_AMP] = (t_pars_proc){PARS_KEEP, PARS_TAKE, AMP_PARS_RD_MD};
	pars->decision[STD_PARS_RD_MD][TOK_LSS] = (t_pars_proc){PARS_KEEP, PARS_TAKE, LT_PARS_RD_MD};
	pars->decision[STD_PARS_RD_MD][TOK_GRT] = (t_pars_proc){PARS_KEEP, PARS_TAKE, GT_PARS_RD_MD};
	pars->decision[STD_PARS_RD_MD][TOK_END_OF_INPUT] = (t_pars_proc){PARS_END, PARS_SKIP, NEW_PARS_RD_MD};
	return (0);
}

/*int	ft_init_pars_decision_1(t_pars *pars)
{
	pars->decision[NEW_PARS_RD_MD][SEP_CHAR] = (t_pars_proc){PARS_KEEP, PARS_SKIP, NEW_PARS_RD_MD, TOK_NEW};
	pars->decision[NEW_PARS_RD_MD][STD_CHAR] = (t_pars_proc){PARS_KEEP, PARS_TAKE, STD_PARS_RD_MD, TOK_WORD};
	pars->decision[NEW_PARS_RD_MD][SPL_CHAR] = (t_pars_proc){PARS_KEEP, PARS_TAKE, SPL_PARS_RD_MD, TOK_WORD};
	pars->decision[NEW_PARS_RD_MD][DBL_CHAR] = (t_pars_proc){PARS_KEEP, PARS_TAKE, DBL_PARS_RD_MD, TOK_WORD};
	pars->decision[NEW_PARS_RD_MD][ESCP_CHAR] = (t_pars_proc){PARS_KEEP, PARS_SKIP, ESCP_PARS_RD_MD, TOK_NEW};
	pars->decision[NEW_PARS_RD_MD][PIPE_CHAR] = (t_pars_proc){PARS_KEEP, PARS_TAKE, PIPE_PARS_RD_MD, TOK_PIPE};
	pars->decision[NEW_PARS_RD_MD][AMP_CHAR] = (t_pars_proc){PARS_KEEP, PARS_TAKE, AMP_PARS_RD_MD, TOK_AMP};
	pars->decision[NEW_PARS_RD_MD][LT_CHAR] = (t_pars_proc){PARS_KEEP, PARS_TAKE, LT_PARS_RD_MD, TOK_LSS};
	pars->decision[NEW_PARS_RD_MD][GT_CHAR] = (t_pars_proc){PARS_KEEP, PARS_TAKE, GT_PARS_RD_MD, TOK_GRT};
	pars->decision[NEW_PARS_RD_MD][END_CHAR] = (t_pars_proc){PARS_END, PARS_SKIP, NEW_PARS_RD_MD, TOK_END_OF_INPUT};
	pars->decision[STD_PARS_RD_MD][SEP_CHAR] = (t_pars_proc){PARS_CATCH, PARS_SKIP, NEW_PARS_RD_MD, TOK_NEW};
	pars->decision[STD_PARS_RD_MD][STD_CHAR] = (t_pars_proc){PARS_KEEP, PARS_TAKE, STD_PARS_RD_MD, TOK_WORD};
	pars->decision[STD_PARS_RD_MD][SPL_CHAR] = (t_pars_proc){PARS_KEEP, PARS_TAKE, SPL_PARS_RD_MD, TOK_WORD};
	pars->decision[STD_PARS_RD_MD][DBL_CHAR] = (t_pars_proc){PARS_KEEP, PARS_TAKE, DBL_PARS_RD_MD, TOK_WORD};
	pars->decision[STD_PARS_RD_MD][ESCP_CHAR] = (t_pars_proc){PARS_KEEP, PARS_SKIP, ESCP_PARS_RD_MD, TOK_WORD};
	pars->decision[STD_PARS_RD_MD][PIPE_CHAR] = (t_pars_proc){PARS_CATCH, PARS_TAKE, PIPE_PARS_RD_MD, TOK_PIPE};
	pars->decision[STD_PARS_RD_MD][AMP_CHAR] = (t_pars_proc){PARS_CATCH, PARS_TAKE, AMP_PARS_RD_MD, TOK_AMP};
	pars->decision[STD_PARS_RD_MD][LT_CHAR] = (t_pars_proc){PARS_CATCH, PARS_TAKE, LT_PARS_RD_MD, TOK_LSS};
	pars->decision[STD_PARS_RD_MD][GT_CHAR] = (t_pars_proc){PARS_CATCH, PARS_TAKE, GT_PARS_RD_MD, TOK_GRT};
	pars->decision[STD_PARS_RD_MD][END_CHAR] = (t_pars_proc){PARS_CATCH, PARS_SKIP, NEW_PARS_RD_MD, TOK_NEW};
	return (0);
}*/

int	ft_init_pars_decision_2(t_pars *pars)
{
	(void)pars;
/*	pars->decision[SPL_PARS_RD_MD][SEP_CHAR] = (t_pars_proc){PARS_KEEP, PARS_TAKE, SPL_PARS_RD_MD, TOK_WORD};
	pars->decision[SPL_PARS_RD_MD][STD_CHAR] = (t_pars_proc){PARS_KEEP, PARS_TAKE, SPL_PARS_RD_MD, TOK_WORD};
	pars->decision[SPL_PARS_RD_MD][SPL_CHAR] = (t_pars_proc){PARS_KEEP, PARS_TAKE, STD_PARS_RD_MD, TOK_WORD};
	pars->decision[SPL_PARS_RD_MD][DBL_CHAR] = (t_pars_proc){PARS_KEEP, PARS_TAKE, SPL_PARS_RD_MD, TOK_WORD};
	pars->decision[SPL_PARS_RD_MD][ESCP_CHAR] = (t_pars_proc){PARS_KEEP, PARS_SKIP, SPL_PARS_RD_MD, TOK_WORD};
	pars->decision[SPL_PARS_RD_MD][PIPE_CHAR] = (t_pars_proc){PARS_KEEP, PARS_TAKE, SPL_PARS_RD_MD, TOK_WORD};
	pars->decision[SPL_PARS_RD_MD][AMP_CHAR] = (t_pars_proc){PARS_KEEP, PARS_TAKE, SPL_PARS_RD_MD, TOK_WORD};
	pars->decision[SPL_PARS_RD_MD][LT_CHAR] = (t_pars_proc){PARS_KEEP, PARS_TAKE, SPL_PARS_RD_MD, TOK_WORD};
	pars->decision[SPL_PARS_RD_MD][GT_CHAR] = (t_pars_proc){PARS_KEEP, PARS_TAKE, SPL_PARS_RD_MD, TOK_WORD};
	pars->decision[SPL_PARS_RD_MD][END_CHAR] = (t_pars_proc){PARS_ERR, PARS_DROP, SYNT_ERR_PARS_RD_MD, TOK_WORD};
	pars->decision[DBL_PARS_RD_MD][SEP_CHAR] = (t_pars_proc){PARS_KEEP, PARS_TAKE, DBL_PARS_RD_MD, TOK_WORD};
	pars->decision[DBL_PARS_RD_MD][STD_CHAR] = (t_pars_proc){PARS_KEEP, PARS_TAKE, DBL_PARS_RD_MD, TOK_WORD};
	pars->decision[DBL_PARS_RD_MD][SPL_CHAR] = (t_pars_proc){PARS_KEEP, PARS_TAKE, DBL_PARS_RD_MD, TOK_WORD};
	pars->decision[DBL_PARS_RD_MD][DBL_CHAR] = (t_pars_proc){PARS_KEEP, PARS_TAKE, STD_PARS_RD_MD, TOK_WORD};
	pars->decision[DBL_PARS_RD_MD][ESCP_CHAR] = (t_pars_proc){PARS_KEEP, PARS_SKIP, DBL_PARS_RD_MD, TOK_WORD};
	pars->decision[DBL_PARS_RD_MD][PIPE_CHAR] = (t_pars_proc){PARS_KEEP, PARS_TAKE, DBL_PARS_RD_MD, TOK_WORD};
	pars->decision[DBL_PARS_RD_MD][AMP_CHAR] = (t_pars_proc){PARS_KEEP, PARS_TAKE, DBL_PARS_RD_MD, TOK_WORD};
	pars->decision[DBL_PARS_RD_MD][LT_CHAR] = (t_pars_proc){PARS_KEEP, PARS_TAKE, DBL_PARS_RD_MD, TOK_WORD};
	pars->decision[DBL_PARS_RD_MD][GT_CHAR] = (t_pars_proc){PARS_KEEP, PARS_TAKE, DBL_PARS_RD_MD, TOK_WORD};
	pars->decision[DBL_PARS_RD_MD][END_CHAR] = (t_pars_proc){PARS_ERR, PARS_SKIP, SYNT_ERR_PARS_RD_MD, TOK_WORD};
	*/
	return (0);
}

int	ft_init_pars_decision_3(t_pars *pars)
{
	(void)pars;
/*	pars->decision[ESCP_PARS_RD_MD][SEP_CHAR] = (t_pars_proc){PARS_KEEP, PARS_SKIP, NEW_PARS_RD_MD, TOK_NEW};
	pars->decision[ESCP_PARS_RD_MD][STD_CHAR] = (t_pars_proc){PARS_KEEP, PARS_TAKE, STD_PARS_RD_MD, TOK_WORD};
	pars->decision[ESCP_PARS_RD_MD][SPL_CHAR] = (t_pars_proc){PARS_CATCH, PARS_SKIP, SPL_PARS_RD_MD, TOK_WORD};
	pars->decision[ESCP_PARS_RD_MD][DBL_CHAR] = (t_pars_proc){PARS_CATCH, PARS_SKIP, DBL_PARS_RD_MD, TOK_WORD};
	pars->decision[ESCP_PARS_RD_MD][ESCP_CHAR] = (t_pars_proc){PARS_KEEP, PARS_SKIP, ESCP_PARS_RD_MD, TOK_NEW};
	pars->decision[ESCP_PARS_RD_MD][PIPE_CHAR] = (t_pars_proc){PARS_DROP, PARS_SKIP, SYNT_ERR_PARS_RD_MD, TOK_NEW};
	pars->decision[ESCP_PARS_RD_MD][AMP_CHAR] = (t_pars_proc){PARS_DROP, PARS_SKIP, SYNT_ERR_PARS_RD_MD, TOK_NEW};
	pars->decision[ESCP_PARS_RD_MD][LT_CHAR] = (t_pars_proc){PARS_DROP, PARS_TAKE, SYNT_ERR_PARS_RD_MD, TOK_NEW};
	pars->decision[ESCP_PARS_RD_MD][GT_CHAR] = (t_pars_proc){PARS_DROP, PARS_TAKE, SYNT_ERR_PARS_RD_MD, TOK_NEW};
	pars->decision[ESCP_PARS_RD_MD][END_CHAR] = (t_pars_proc){PARS_CATCH, PARS_SKIP, NEW_PARS_RD_MD, TOK_NEW};
	pars->decision[PIPE_PARS_RD_MD][SEP_CHAR] = (t_pars_proc){PARS_CATCH, PARS_SKIP, NEW_PARS_RD_MD, TOK_NEW};
	pars->decision[PIPE_PARS_RD_MD][STD_CHAR] = (t_pars_proc){PARS_CATCH, PARS_TAKE, STD_PARS_RD_MD, TOK_WORD};
	pars->decision[PIPE_PARS_RD_MD][SPL_CHAR] = (t_pars_proc){PARS_CATCH, PARS_SKIP, SPL_PARS_RD_MD, TOK_WORD};
	pars->decision[PIPE_PARS_RD_MD][DBL_CHAR] = (t_pars_proc){PARS_CATCH, PARS_SKIP, DBL_PARS_RD_MD, TOK_WORD};
	pars->decision[PIPE_PARS_RD_MD][ESCP_CHAR] = (t_pars_proc){PARS_CATCH, PARS_SKIP, ESCP_PARS_RD_MD, TOK_NEW};
	pars->decision[PIPE_PARS_RD_MD][PIPE_CHAR] = (t_pars_proc){PARS_KEEP, PARS_TAKE, OR_PARS_RD_MD, TOK_OP_OR};
//check following case
	pars->decision[PIPE_PARS_RD_MD][AMP_CHAR] = (t_pars_proc){PARS_CATCH, PARS_TAKE, AMP_PARS_RD_MD, TOK_AMP};
	pars->decision[PIPE_PARS_RD_MD][LT_CHAR] = (t_pars_proc){PARS_KEEP, PARS_TAKE, SYNT_ERR_PARS_RD_MD, TOK_NEW};
	pars->decision[PIPE_PARS_RD_MD][GT_CHAR] = (t_pars_proc){PARS_KEEP, PARS_TAKE, SYNT_ERR_PARS_RD_MD, TOK_NEW};
	pars->decision[PIPE_PARS_RD_MD][END_CHAR] = (t_pars_proc){PARS_DROP, PARS_SKIP, SYNT_ERR_PARS_RD_MD, TOK_NEW};
	*/
	return (0);
}

int	ft_init_pars_decision_4(t_pars *pars)
{
	(void)pars;
/*	pars->decision[AMP_PARS_RD_MD][SEP_CHAR] = (t_pars_proc){PARS_CATCH, PARS_SKIP, NEW_PARS_RD_MD, TOK_NEW};
	pars->decision[AMP_PARS_RD_MD][STD_CHAR] = (t_pars_proc){PARS_CATCH, PARS_TAKE, STD_PARS_RD_MD, TOK_WORD};
	pars->decision[AMP_PARS_RD_MD][SPL_CHAR] = (t_pars_proc){PARS_CATCH, PARS_SKIP, SYNT_ERR_PARS_RD_MD, TOK_NEW};
	pars->decision[AMP_PARS_RD_MD][DBL_CHAR] = (t_pars_proc){PARS_DROP, PARS_SKIP, SYNT_ERR_PARS_RD_MD, TOK_NEW};
	pars->decision[AMP_PARS_RD_MD][ESCP_CHAR] = (t_pars_proc){PARS_CATCH, PARS_SKIP, ESCP_PARS_RD_MD, TOK_NEW};
	pars->decision[AMP_PARS_RD_MD][PIPE_CHAR] = (t_pars_proc){PARS_DROP, PARS_SKIP, SYNT_ERR_PARS_RD_MD, TOK_NEW};
	pars->decision[AMP_PARS_RD_MD][AMP_CHAR] = (t_pars_proc){PARS_KEEP, PARS_TAKE, AND_PARS_RD_MD, TOK_OP_AND};
	pars->decision[AMP_PARS_RD_MD][LT_CHAR] = (t_pars_proc){PARS_DROP, PARS_SKIP, SYNT_ERR_PARS_RD_MD, TOK_NEW};
	pars->decision[AMP_PARS_RD_MD][GT_CHAR] = (t_pars_proc){PARS_DROP, PARS_SKIP, SYNT_ERR_PARS_RD_MD, TOK_NEW};
	pars->decision[AMP_PARS_RD_MD][END_CHAR] = (t_pars_proc){PARS_DROP, PARS_SKIP, SYNT_ERR_PARS_RD_MD, TOK_NEW};
	pars->decision[LT_PARS_RD_MD][SEP_CHAR] = (t_pars_proc){PARS_CATCH, PARS_SKIP, NEW_PARS_RD_MD, TOK_NEW};
	pars->decision[LT_PARS_RD_MD][STD_CHAR] = (t_pars_proc){PARS_CATCH, PARS_TAKE, STD_PARS_RD_MD, TOK_WORD};
	pars->decision[LT_PARS_RD_MD][SPL_CHAR] = (t_pars_proc){PARS_CATCH, PARS_SKIP, SPL_PARS_RD_MD, TOK_WORD};
	pars->decision[LT_PARS_RD_MD][DBL_CHAR] = (t_pars_proc){PARS_CATCH, PARS_SKIP, DBL_PARS_RD_MD, TOK_WORD};
	pars->decision[LT_PARS_RD_MD][ESCP_CHAR] = (t_pars_proc){PARS_CATCH, PARS_SKIP, ESCP_PARS_RD_MD, TOK_NEW};
	pars->decision[LT_PARS_RD_MD][PIPE_CHAR] = (t_pars_proc){PARS_DROP, PARS_SKIP, SYNT_ERR_PARS_RD_MD, TOK_NEW};
	pars->decision[LT_PARS_RD_MD][AMP_CHAR] = (t_pars_proc){PARS_DROP, PARS_SKIP, SYNT_ERR_PARS_RD_MD, TOK_NEW};
	pars->decision[LT_PARS_RD_MD][LT_CHAR] = (t_pars_proc){PARS_KEEP, PARS_TAKE, HEREDOC_PARS_RD_MD, TOK_HEREDOC};
	pars->decision[LT_PARS_RD_MD][GT_CHAR] = (t_pars_proc){PARS_DROP, PARS_SKIP, SYNT_ERR_PARS_RD_MD, TOK_WORD};
	pars->decision[LT_PARS_RD_MD][END_CHAR] = (t_pars_proc){PARS_CATCH, PARS_SKIP, NEW_PARS_RD_MD, TOK_NEW};
	*/
	return (0);
}

int	ft_init_pars_decision_5(t_pars *pars)
{
	(void)pars;
/*	pars->decision[GT_PARS_RD_MD][SEP_CHAR] = (t_pars_proc){PARS_CATCH, PARS_SKIP, NEW_PARS_RD_MD, TOK_NEW};
	pars->decision[GT_PARS_RD_MD][STD_CHAR] = (t_pars_proc){PARS_CATCH, PARS_TAKE, STD_PARS_RD_MD, TOK_WORD};
	pars->decision[GT_PARS_RD_MD][SPL_CHAR] = (t_pars_proc){PARS_CATCH, PARS_SKIP, SPL_PARS_RD_MD, TOK_WORD};
	pars->decision[GT_PARS_RD_MD][DBL_CHAR] = (t_pars_proc){PARS_CATCH, PARS_SKIP, SPL_PARS_RD_MD, TOK_WORD};
	pars->decision[GT_PARS_RD_MD][ESCP_CHAR] = (t_pars_proc){PARS_CATCH, PARS_SKIP, ESCP_PARS_RD_MD, TOK_NEW};
	pars->decision[GT_PARS_RD_MD][PIPE_CHAR] = (t_pars_proc){PARS_CATCH, PARS_SKIP, SYNT_ERR_PARS_RD_MD, TOK_NEW};
	pars->decision[GT_PARS_RD_MD][AMP_CHAR] = (t_pars_proc){PARS_CATCH, PARS_SKIP, SYNT_ERR_PARS_RD_MD, TOK_NEW};
	pars->decision[GT_PARS_RD_MD][LT_CHAR] = (t_pars_proc){PARS_CATCH, PARS_SKIP, SYNT_ERR_PARS_RD_MD, TOK_NEW};
	pars->decision[GT_PARS_RD_MD][GT_CHAR] = (t_pars_proc){PARS_KEEP, PARS_TAKE, GGRT_PARS_RD_MD, TOK_GGRT};
	pars->decision[GT_PARS_RD_MD][END_CHAR] = (t_pars_proc){PARS_CATCH, PARS_SKIP, NEW_PARS_RD_MD, TOK_NEW};
	pars->decision[OR_PARS_RD_MD][SEP_CHAR] = (t_pars_proc){PARS_CATCH, PARS_SKIP, NEW_PARS_RD_MD, TOK_NEW};
	pars->decision[OR_PARS_RD_MD][STD_CHAR] = (t_pars_proc){PARS_CATCH, PARS_TAKE, STD_PARS_RD_MD, TOK_WORD};
	pars->decision[OR_PARS_RD_MD][SPL_CHAR] = (t_pars_proc){PARS_CATCH, PARS_SKIP, SYNT_ERR_PARS_RD_MD, TOK_NEW};
	pars->decision[OR_PARS_RD_MD][DBL_CHAR] = (t_pars_proc){PARS_DROP, PARS_SKIP, SYNT_ERR_PARS_RD_MD, TOK_NEW};
	pars->decision[OR_PARS_RD_MD][ESCP_CHAR] = (t_pars_proc){PARS_CATCH, PARS_SKIP, ESCP_PARS_RD_MD, TOK_NEW};
	pars->decision[OR_PARS_RD_MD][PIPE_CHAR] = (t_pars_proc){PARS_DROP, PARS_SKIP, SYNT_ERR_PARS_RD_MD, TOK_NEW};
	pars->decision[OR_PARS_RD_MD][AMP_CHAR] = (t_pars_proc){PARS_CATCH, PARS_TAKE, AND_PARS_RD_MD, TOK_OP_AND};
	pars->decision[OR_PARS_RD_MD][LT_CHAR] = (t_pars_proc){PARS_DROP, PARS_SKIP, SYNT_ERR_PARS_RD_MD, TOK_NEW};
	pars->decision[OR_PARS_RD_MD][GT_CHAR] = (t_pars_proc){PARS_DROP, PARS_SKIP, SYNT_ERR_PARS_RD_MD, TOK_NEW};
	pars->decision[OR_PARS_RD_MD][END_CHAR] = (t_pars_proc){PARS_CATCH, PARS_SKIP, NEW_PARS_RD_MD, TOK_NEW};
	*/
	return (0);
}

int	ft_init_pars_decision_6(t_pars *pars)
{
	(void)pars;
/*	pars->decision[AND_PARS_RD_MD][SEP_CHAR] = (t_pars_proc){PARS_CATCH, PARS_SKIP, NEW_PARS_RD_MD, TOK_NEW};
	pars->decision[AND_PARS_RD_MD][STD_CHAR] = (t_pars_proc){PARS_CATCH, PARS_TAKE, STD_PARS_RD_MD, TOK_WORD};
	pars->decision[AND_PARS_RD_MD][SPL_CHAR] = (t_pars_proc){PARS_CATCH, PARS_SKIP, SPL_PARS_RD_MD, TOK_WORD};
	pars->decision[AND_PARS_RD_MD][DBL_CHAR] = (t_pars_proc){PARS_CATCH, PARS_SKIP, DBL_PARS_RD_MD, TOK_WORD};
	pars->decision[AND_PARS_RD_MD][ESCP_CHAR] = (t_pars_proc){PARS_CATCH, PARS_SKIP, ESCP_PARS_RD_MD, TOK_NEW};
	pars->decision[AND_PARS_RD_MD][PIPE_CHAR] = (t_pars_proc){PARS_DROP, PARS_SKIP, SYNT_ERR_PARS_RD_MD, TOK_NEW};
	pars->decision[AND_PARS_RD_MD][AMP_CHAR] = (t_pars_proc){PARS_DROP, PARS_SKIP, SYNT_ERR_PARS_RD_MD, TOK_NEW};
	pars->decision[AND_PARS_RD_MD][LT_CHAR] = (t_pars_proc){PARS_KEEP, PARS_TAKE, HEREDOC_PARS_RD_MD, TOK_HEREDOC};
	pars->decision[AND_PARS_RD_MD][GT_CHAR] = (t_pars_proc){PARS_DROP, PARS_SKIP, SYNT_ERR_PARS_RD_MD, TOK_WORD};
	pars->decision[AND_PARS_RD_MD][END_CHAR] = (t_pars_proc){PARS_DROP, PARS_SKIP, SYNT_ERR_PARS_RD_MD, TOK_NEW};
	pars->decision[HEREDOC_PARS_RD_MD][SEP_CHAR] = (t_pars_proc){PARS_CATCH, PARS_SKIP, NEW_PARS_RD_MD, TOK_NEW};
	pars->decision[HEREDOC_PARS_RD_MD][STD_CHAR] = (t_pars_proc){PARS_CATCH, PARS_TAKE, STD_PARS_RD_MD, TOK_WORD};
	pars->decision[HEREDOC_PARS_RD_MD][SPL_CHAR] = (t_pars_proc){PARS_CATCH, PARS_SKIP, SPL_PARS_RD_MD, TOK_WORD};
	pars->decision[HEREDOC_PARS_RD_MD][DBL_CHAR] = (t_pars_proc){PARS_CATCH, PARS_SKIP, DBL_PARS_RD_MD, TOK_WORD};
	pars->decision[HEREDOC_PARS_RD_MD][ESCP_CHAR] = (t_pars_proc){PARS_KEEP, PARS_SKIP, ESCP_PARS_RD_MD, TOK_NEW};
	pars->decision[HEREDOC_PARS_RD_MD][PIPE_CHAR] = (t_pars_proc){PARS_DROP, PARS_SKIP, SYNT_ERR_PARS_RD_MD, TOK_NEW};
	pars->decision[HEREDOC_PARS_RD_MD][AMP_CHAR] = (t_pars_proc){PARS_DROP, PARS_SKIP, SYNT_ERR_PARS_RD_MD, TOK_NEW};
	pars->decision[HEREDOC_PARS_RD_MD][LT_CHAR] = (t_pars_proc){PARS_DROP, PARS_TAKE, SYNT_ERR_PARS_RD_MD, TOK_NEW};
	pars->decision[HEREDOC_PARS_RD_MD][GT_CHAR] = (t_pars_proc){PARS_DROP, PARS_TAKE, SYNT_ERR_PARS_RD_MD, TOK_NEW};
	pars->decision[HEREDOC_PARS_RD_MD][END_CHAR] = (t_pars_proc){PARS_CATCH, PARS_SKIP, NEW_PARS_RD_MD, TOK_NEW};
	*/
	return (0);
}

int	ft_init_pars_decision_7(t_pars *pars)
{
	(void)pars;
/*	pars->decision[GGRT_PARS_RD_MD][SEP_CHAR] = (t_pars_proc){PARS_CATCH, PARS_SKIP, NEW_PARS_RD_MD, TOK_NEW};
	pars->decision[GGRT_PARS_RD_MD][STD_CHAR] = (t_pars_proc){PARS_CATCH, PARS_TAKE, STD_PARS_RD_MD, TOK_WORD};
	pars->decision[GGRT_PARS_RD_MD][SPL_CHAR] = (t_pars_proc){PARS_CATCH, PARS_SKIP, SPL_PARS_RD_MD, TOK_WORD};
	pars->decision[GGRT_PARS_RD_MD][DBL_CHAR] = (t_pars_proc){PARS_CATCH, PARS_SKIP, SPL_PARS_RD_MD, TOK_WORD};
	pars->decision[GGRT_PARS_RD_MD][ESCP_CHAR] = (t_pars_proc){PARS_CATCH, PARS_SKIP, ESCP_PARS_RD_MD, TOK_NEW};
	pars->decision[GGRT_PARS_RD_MD][PIPE_CHAR] = (t_pars_proc){PARS_CATCH, PARS_SKIP, SYNT_ERR_PARS_RD_MD, TOK_NEW};
	pars->decision[GGRT_PARS_RD_MD][AMP_CHAR] = (t_pars_proc){PARS_CATCH, PARS_SKIP, SYNT_ERR_PARS_RD_MD, TOK_NEW};
	pars->decision[GGRT_PARS_RD_MD][LT_CHAR] = (t_pars_proc){PARS_CATCH, PARS_SKIP, SYNT_ERR_PARS_RD_MD, TOK_NEW};
	pars->decision[GGRT_PARS_RD_MD][GT_CHAR] = (t_pars_proc){PARS_CATCH, PARS_SKIP, SPL_PARS_RD_MD, TOK_GGRT};
	pars->decision[GGRT_PARS_RD_MD][END_CHAR] = (t_pars_proc){PARS_CATCH, PARS_SKIP, NEW_PARS_RD_MD, TOK_NEW};
	*/
	return (0);
}
