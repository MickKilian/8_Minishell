/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_init_decisions.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 00:47:14 by mbourgeo          #+#    #+#             */
/*   Updated: 2022/10/05 23:32:14 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_init_pars_decision_1(t_pars *pars)
{
	//pars->pars_decision[NEW_PARS_RD_MD][TOK_NEW] = (t_pars_proc){PARS_KEEP, PARS_SKIP, NEW_PARS_RD_MD};
	pars->pars_decision[NEW_PARS_RD_MD][TOK_WORD] = (t_pars_proc){PARS_KEEP, PARS_TAKE, STD_PARS_RD_MD};
	pars->pars_decision[NEW_PARS_RD_MD][TOK_PIPE] = (t_pars_proc){PARS_CATCH, PARS_SKIP, NEW_PARS_RD_MD};
	pars->pars_decision[NEW_PARS_RD_MD][TOK_AMP] = (t_pars_proc){PARS_KEEP, PARS_TAKE, AMP_PARS_RD_MD};
	pars->pars_decision[NEW_PARS_RD_MD][TOK_LSS] = (t_pars_proc){PARS_KEEP, PARS_TAKE, LT_PARS_RD_MD};
	pars->pars_decision[NEW_PARS_RD_MD][TOK_GRT] = (t_pars_proc){PARS_KEEP, PARS_TAKE, GT_PARS_RD_MD};
	pars->pars_decision[NEW_PARS_RD_MD][TOK_ERR_SPL] = (t_pars_proc){PARS_KEEP, PARS_TAKE, GT_PARS_RD_MD};
	pars->pars_decision[NEW_PARS_RD_MD][TOK_ERR_DBL] = (t_pars_proc){PARS_KEEP, PARS_TAKE, GT_PARS_RD_MD};
	pars->pars_decision[NEW_PARS_RD_MD][TOK_END_OF_INPUT] = (t_pars_proc){PARS_END, PARS_SKIP, NEW_PARS_RD_MD};
	//pars->pars_decision[STD_PARS_RD_MD][TOK_NEW] = (t_pars_proc){PARS_KEEP, PARS_SKIP, NEW_PARS_RD_MD};
	pars->pars_decision[STD_PARS_RD_MD][TOK_WORD] = (t_pars_proc){PARS_KEEP, PARS_TAKE, STD_PARS_RD_MD};
	pars->pars_decision[STD_PARS_RD_MD][TOK_PIPE] = (t_pars_proc){PARS_NEW, PARS_SKIP, NEW_PARS_RD_MD};
	pars->pars_decision[STD_PARS_RD_MD][TOK_AMP] = (t_pars_proc){PARS_KEEP, PARS_TAKE, AMP_PARS_RD_MD};
	pars->pars_decision[STD_PARS_RD_MD][TOK_LSS] = (t_pars_proc){PARS_KEEP, PARS_TAKE, LT_PARS_RD_MD};
	pars->pars_decision[STD_PARS_RD_MD][TOK_GRT] = (t_pars_proc){PARS_KEEP, PARS_TAKE, GT_PARS_RD_MD};
	pars->pars_decision[STD_PARS_RD_MD][TOK_END_OF_INPUT] = (t_pars_proc){PARS_END, PARS_SKIP, NEW_PARS_RD_MD};
	return (0);
}

int	ft_init_pars_decision_2(t_pars *pars)
{
	(void)pars;
	//pars->pars_decision[NEW_PARS_RD_MD][TOK_NEW] = (t_pars_proc){PARS_KEEP, PARS_SKIP, NEW_PARS_RD_MD};
	/*pars->pars_decision[NEW_PARS_RD_MD][TOK_WORD] = (t_pars_proc){PARS_KEEP, PARS_TAKE, STD_PARS_RD_MD};
	pars->pars_decision[NEW_PARS_RD_MD][TOK_PIPE] = (t_pars_proc){PARS_CATCH, PARS_SKIP, NEW_PARS_RD_MD};
	pars->pars_decision[NEW_PARS_RD_MD][TOK_AMP] = (t_pars_proc){PARS_KEEP, PARS_TAKE, AMP_PARS_RD_MD};
	pars->pars_decision[NEW_PARS_RD_MD][TOK_LSS] = (t_pars_proc){PARS_KEEP, PARS_TAKE, LT_PARS_RD_MD};
	pars->pars_decision[NEW_PARS_RD_MD][TOK_GRT] = (t_pars_proc){PARS_KEEP, PARS_TAKE, GT_PARS_RD_MD};
	pars->pars_decision[NEW_PARS_RD_MD][TOK_END_OF_INPUT] = (t_pars_proc){PARS_END, PARS_SKIP, NEW_PARS_RD_MD};
	*/
	return (0);
}

int	ft_init_pars_decision_3(t_pars *pars)
{
	(void)pars;
/*	pars->pars_decision[ESCP_PARS_RD_MD][SEP_CHAR] = (t_pars_proc){PARS_KEEP, PARS_SKIP, NEW_PARS_RD_MD, TOK_NEW};
	pars->pars_decision[ESCP_PARS_RD_MD][STD_CHAR] = (t_pars_proc){PARS_KEEP, PARS_TAKE, STD_PARS_RD_MD, TOK_WORD};
	pars->pars_decision[ESCP_PARS_RD_MD][SPL_CHAR] = (t_pars_proc){PARS_CATCH, PARS_SKIP, SPL_PARS_RD_MD, TOK_WORD};
	pars->pars_decision[ESCP_PARS_RD_MD][DBL_CHAR] = (t_pars_proc){PARS_CATCH, PARS_SKIP, DBL_PARS_RD_MD, TOK_WORD};
	pars->pars_decision[ESCP_PARS_RD_MD][ESCP_CHAR] = (t_pars_proc){PARS_KEEP, PARS_SKIP, ESCP_PARS_RD_MD, TOK_NEW};
	pars->pars_decision[ESCP_PARS_RD_MD][PIPE_CHAR] = (t_pars_proc){PARS_DROP, PARS_SKIP, SYNT_ERR_PARS_RD_MD, TOK_NEW};
	pars->pars_decision[ESCP_PARS_RD_MD][AMP_CHAR] = (t_pars_proc){PARS_DROP, PARS_SKIP, SYNT_ERR_PARS_RD_MD, TOK_NEW};
	pars->pars_decision[ESCP_PARS_RD_MD][LT_CHAR] = (t_pars_proc){PARS_DROP, PARS_TAKE, SYNT_ERR_PARS_RD_MD, TOK_NEW};
	pars->pars_decision[ESCP_PARS_RD_MD][GT_CHAR] = (t_pars_proc){PARS_DROP, PARS_TAKE, SYNT_ERR_PARS_RD_MD, TOK_NEW};
	pars->pars_decision[ESCP_PARS_RD_MD][END_CHAR] = (t_pars_proc){PARS_CATCH, PARS_SKIP, NEW_PARS_RD_MD, TOK_NEW};
	pars->pars_decision[PIPE_PARS_RD_MD][SEP_CHAR] = (t_pars_proc){PARS_CATCH, PARS_SKIP, NEW_PARS_RD_MD, TOK_NEW};
	pars->pars_decision[PIPE_PARS_RD_MD][STD_CHAR] = (t_pars_proc){PARS_CATCH, PARS_TAKE, STD_PARS_RD_MD, TOK_WORD};
	pars->pars_decision[PIPE_PARS_RD_MD][SPL_CHAR] = (t_pars_proc){PARS_CATCH, PARS_SKIP, SPL_PARS_RD_MD, TOK_WORD};
	pars->pars_decision[PIPE_PARS_RD_MD][DBL_CHAR] = (t_pars_proc){PARS_CATCH, PARS_SKIP, DBL_PARS_RD_MD, TOK_WORD};
	pars->pars_decision[PIPE_PARS_RD_MD][ESCP_CHAR] = (t_pars_proc){PARS_CATCH, PARS_SKIP, ESCP_PARS_RD_MD, TOK_NEW};
	pars->pars_decision[PIPE_PARS_RD_MD][PIPE_CHAR] = (t_pars_proc){PARS_KEEP, PARS_TAKE, OR_PARS_RD_MD, TOK_OP_OR};
//check following case
	pars->pars_decision[PIPE_PARS_RD_MD][AMP_CHAR] = (t_pars_proc){PARS_CATCH, PARS_TAKE, AMP_PARS_RD_MD, TOK_AMP};
	pars->pars_decision[PIPE_PARS_RD_MD][LT_CHAR] = (t_pars_proc){PARS_KEEP, PARS_TAKE, SYNT_ERR_PARS_RD_MD, TOK_NEW};
	pars->pars_decision[PIPE_PARS_RD_MD][GT_CHAR] = (t_pars_proc){PARS_KEEP, PARS_TAKE, SYNT_ERR_PARS_RD_MD, TOK_NEW};
	pars->pars_decision[PIPE_PARS_RD_MD][END_CHAR] = (t_pars_proc){PARS_DROP, PARS_SKIP, SYNT_ERR_PARS_RD_MD, TOK_NEW};
	*/
	return (0);
}

int	ft_init_pars_decision_4(t_pars *pars)
{
	(void)pars;
/*	pars->pars_decision[AMP_PARS_RD_MD][SEP_CHAR] = (t_pars_proc){PARS_CATCH, PARS_SKIP, NEW_PARS_RD_MD, TOK_NEW};
	pars->pars_decision[AMP_PARS_RD_MD][STD_CHAR] = (t_pars_proc){PARS_CATCH, PARS_TAKE, STD_PARS_RD_MD, TOK_WORD};
	pars->pars_decision[AMP_PARS_RD_MD][SPL_CHAR] = (t_pars_proc){PARS_CATCH, PARS_SKIP, SYNT_ERR_PARS_RD_MD, TOK_NEW};
	pars->pars_decision[AMP_PARS_RD_MD][DBL_CHAR] = (t_pars_proc){PARS_DROP, PARS_SKIP, SYNT_ERR_PARS_RD_MD, TOK_NEW};
	pars->pars_decision[AMP_PARS_RD_MD][ESCP_CHAR] = (t_pars_proc){PARS_CATCH, PARS_SKIP, ESCP_PARS_RD_MD, TOK_NEW};
	pars->pars_decision[AMP_PARS_RD_MD][PIPE_CHAR] = (t_pars_proc){PARS_DROP, PARS_SKIP, SYNT_ERR_PARS_RD_MD, TOK_NEW};
	pars->pars_decision[AMP_PARS_RD_MD][AMP_CHAR] = (t_pars_proc){PARS_KEEP, PARS_TAKE, AND_PARS_RD_MD, TOK_OP_AND};
	pars->pars_decision[AMP_PARS_RD_MD][LT_CHAR] = (t_pars_proc){PARS_DROP, PARS_SKIP, SYNT_ERR_PARS_RD_MD, TOK_NEW};
	pars->pars_decision[AMP_PARS_RD_MD][GT_CHAR] = (t_pars_proc){PARS_DROP, PARS_SKIP, SYNT_ERR_PARS_RD_MD, TOK_NEW};
	pars->pars_decision[AMP_PARS_RD_MD][END_CHAR] = (t_pars_proc){PARS_DROP, PARS_SKIP, SYNT_ERR_PARS_RD_MD, TOK_NEW};
	pars->pars_decision[LT_PARS_RD_MD][SEP_CHAR] = (t_pars_proc){PARS_CATCH, PARS_SKIP, NEW_PARS_RD_MD, TOK_NEW};
	pars->pars_decision[LT_PARS_RD_MD][STD_CHAR] = (t_pars_proc){PARS_CATCH, PARS_TAKE, STD_PARS_RD_MD, TOK_WORD};
	pars->pars_decision[LT_PARS_RD_MD][SPL_CHAR] = (t_pars_proc){PARS_CATCH, PARS_SKIP, SPL_PARS_RD_MD, TOK_WORD};
	pars->pars_decision[LT_PARS_RD_MD][DBL_CHAR] = (t_pars_proc){PARS_CATCH, PARS_SKIP, DBL_PARS_RD_MD, TOK_WORD};
	pars->pars_decision[LT_PARS_RD_MD][ESCP_CHAR] = (t_pars_proc){PARS_CATCH, PARS_SKIP, ESCP_PARS_RD_MD, TOK_NEW};
	pars->pars_decision[LT_PARS_RD_MD][PIPE_CHAR] = (t_pars_proc){PARS_DROP, PARS_SKIP, SYNT_ERR_PARS_RD_MD, TOK_NEW};
	pars->pars_decision[LT_PARS_RD_MD][AMP_CHAR] = (t_pars_proc){PARS_DROP, PARS_SKIP, SYNT_ERR_PARS_RD_MD, TOK_NEW};
	pars->pars_decision[LT_PARS_RD_MD][LT_CHAR] = (t_pars_proc){PARS_KEEP, PARS_TAKE, HEREDOC_PARS_RD_MD, TOK_HEREDOC};
	pars->pars_decision[LT_PARS_RD_MD][GT_CHAR] = (t_pars_proc){PARS_DROP, PARS_SKIP, SYNT_ERR_PARS_RD_MD, TOK_WORD};
	pars->pars_decision[LT_PARS_RD_MD][END_CHAR] = (t_pars_proc){PARS_CATCH, PARS_SKIP, NEW_PARS_RD_MD, TOK_NEW};
	*/
	return (0);
}

int	ft_init_pars_decision_5(t_pars *pars)
{
	(void)pars;
/*	pars->pars_decision[GT_PARS_RD_MD][SEP_CHAR] = (t_pars_proc){PARS_CATCH, PARS_SKIP, NEW_PARS_RD_MD, TOK_NEW};
	pars->pars_decision[GT_PARS_RD_MD][STD_CHAR] = (t_pars_proc){PARS_CATCH, PARS_TAKE, STD_PARS_RD_MD, TOK_WORD};
	pars->pars_decision[GT_PARS_RD_MD][SPL_CHAR] = (t_pars_proc){PARS_CATCH, PARS_SKIP, SPL_PARS_RD_MD, TOK_WORD};
	pars->pars_decision[GT_PARS_RD_MD][DBL_CHAR] = (t_pars_proc){PARS_CATCH, PARS_SKIP, SPL_PARS_RD_MD, TOK_WORD};
	pars->pars_decision[GT_PARS_RD_MD][ESCP_CHAR] = (t_pars_proc){PARS_CATCH, PARS_SKIP, ESCP_PARS_RD_MD, TOK_NEW};
	pars->pars_decision[GT_PARS_RD_MD][PIPE_CHAR] = (t_pars_proc){PARS_CATCH, PARS_SKIP, SYNT_ERR_PARS_RD_MD, TOK_NEW};
	pars->pars_decision[GT_PARS_RD_MD][AMP_CHAR] = (t_pars_proc){PARS_CATCH, PARS_SKIP, SYNT_ERR_PARS_RD_MD, TOK_NEW};
	pars->pars_decision[GT_PARS_RD_MD][LT_CHAR] = (t_pars_proc){PARS_CATCH, PARS_SKIP, SYNT_ERR_PARS_RD_MD, TOK_NEW};
	pars->pars_decision[GT_PARS_RD_MD][GT_CHAR] = (t_pars_proc){PARS_KEEP, PARS_TAKE, GGRT_PARS_RD_MD, TOK_GGRT};
	pars->pars_decision[GT_PARS_RD_MD][END_CHAR] = (t_pars_proc){PARS_CATCH, PARS_SKIP, NEW_PARS_RD_MD, TOK_NEW};
	pars->pars_decision[OR_PARS_RD_MD][SEP_CHAR] = (t_pars_proc){PARS_CATCH, PARS_SKIP, NEW_PARS_RD_MD, TOK_NEW};
	pars->pars_decision[OR_PARS_RD_MD][STD_CHAR] = (t_pars_proc){PARS_CATCH, PARS_TAKE, STD_PARS_RD_MD, TOK_WORD};
	pars->pars_decision[OR_PARS_RD_MD][SPL_CHAR] = (t_pars_proc){PARS_CATCH, PARS_SKIP, SYNT_ERR_PARS_RD_MD, TOK_NEW};
	pars->pars_decision[OR_PARS_RD_MD][DBL_CHAR] = (t_pars_proc){PARS_DROP, PARS_SKIP, SYNT_ERR_PARS_RD_MD, TOK_NEW};
	pars->pars_decision[OR_PARS_RD_MD][ESCP_CHAR] = (t_pars_proc){PARS_CATCH, PARS_SKIP, ESCP_PARS_RD_MD, TOK_NEW};
	pars->pars_decision[OR_PARS_RD_MD][PIPE_CHAR] = (t_pars_proc){PARS_DROP, PARS_SKIP, SYNT_ERR_PARS_RD_MD, TOK_NEW};
	pars->pars_decision[OR_PARS_RD_MD][AMP_CHAR] = (t_pars_proc){PARS_CATCH, PARS_TAKE, AND_PARS_RD_MD, TOK_OP_AND};
	pars->pars_decision[OR_PARS_RD_MD][LT_CHAR] = (t_pars_proc){PARS_DROP, PARS_SKIP, SYNT_ERR_PARS_RD_MD, TOK_NEW};
	pars->pars_decision[OR_PARS_RD_MD][GT_CHAR] = (t_pars_proc){PARS_DROP, PARS_SKIP, SYNT_ERR_PARS_RD_MD, TOK_NEW};
	pars->pars_decision[OR_PARS_RD_MD][END_CHAR] = (t_pars_proc){PARS_CATCH, PARS_SKIP, NEW_PARS_RD_MD, TOK_NEW};
	*/
	return (0);
}

int	ft_init_pars_decision_6(t_pars *pars)
{
	(void)pars;
/*	pars->pars_decision[AND_PARS_RD_MD][SEP_CHAR] = (t_pars_proc){PARS_CATCH, PARS_SKIP, NEW_PARS_RD_MD, TOK_NEW};
	pars->pars_decision[AND_PARS_RD_MD][STD_CHAR] = (t_pars_proc){PARS_CATCH, PARS_TAKE, STD_PARS_RD_MD, TOK_WORD};
	pars->pars_decision[AND_PARS_RD_MD][SPL_CHAR] = (t_pars_proc){PARS_CATCH, PARS_SKIP, SPL_PARS_RD_MD, TOK_WORD};
	pars->pars_decision[AND_PARS_RD_MD][DBL_CHAR] = (t_pars_proc){PARS_CATCH, PARS_SKIP, DBL_PARS_RD_MD, TOK_WORD};
	pars->pars_decision[AND_PARS_RD_MD][ESCP_CHAR] = (t_pars_proc){PARS_CATCH, PARS_SKIP, ESCP_PARS_RD_MD, TOK_NEW};
	pars->pars_decision[AND_PARS_RD_MD][PIPE_CHAR] = (t_pars_proc){PARS_DROP, PARS_SKIP, SYNT_ERR_PARS_RD_MD, TOK_NEW};
	pars->pars_decision[AND_PARS_RD_MD][AMP_CHAR] = (t_pars_proc){PARS_DROP, PARS_SKIP, SYNT_ERR_PARS_RD_MD, TOK_NEW};
	pars->pars_decision[AND_PARS_RD_MD][LT_CHAR] = (t_pars_proc){PARS_KEEP, PARS_TAKE, HEREDOC_PARS_RD_MD, TOK_HEREDOC};
	pars->pars_decision[AND_PARS_RD_MD][GT_CHAR] = (t_pars_proc){PARS_DROP, PARS_SKIP, SYNT_ERR_PARS_RD_MD, TOK_WORD};
	pars->pars_decision[AND_PARS_RD_MD][END_CHAR] = (t_pars_proc){PARS_DROP, PARS_SKIP, SYNT_ERR_PARS_RD_MD, TOK_NEW};
	pars->pars_decision[HEREDOC_PARS_RD_MD][SEP_CHAR] = (t_pars_proc){PARS_CATCH, PARS_SKIP, NEW_PARS_RD_MD, TOK_NEW};
	pars->pars_decision[HEREDOC_PARS_RD_MD][STD_CHAR] = (t_pars_proc){PARS_CATCH, PARS_TAKE, STD_PARS_RD_MD, TOK_WORD};
	pars->pars_decision[HEREDOC_PARS_RD_MD][SPL_CHAR] = (t_pars_proc){PARS_CATCH, PARS_SKIP, SPL_PARS_RD_MD, TOK_WORD};
	pars->pars_decision[HEREDOC_PARS_RD_MD][DBL_CHAR] = (t_pars_proc){PARS_CATCH, PARS_SKIP, DBL_PARS_RD_MD, TOK_WORD};
	pars->pars_decision[HEREDOC_PARS_RD_MD][ESCP_CHAR] = (t_pars_proc){PARS_KEEP, PARS_SKIP, ESCP_PARS_RD_MD, TOK_NEW};
	pars->pars_decision[HEREDOC_PARS_RD_MD][PIPE_CHAR] = (t_pars_proc){PARS_DROP, PARS_SKIP, SYNT_ERR_PARS_RD_MD, TOK_NEW};
	pars->pars_decision[HEREDOC_PARS_RD_MD][AMP_CHAR] = (t_pars_proc){PARS_DROP, PARS_SKIP, SYNT_ERR_PARS_RD_MD, TOK_NEW};
	pars->pars_decision[HEREDOC_PARS_RD_MD][LT_CHAR] = (t_pars_proc){PARS_DROP, PARS_TAKE, SYNT_ERR_PARS_RD_MD, TOK_NEW};
	pars->pars_decision[HEREDOC_PARS_RD_MD][GT_CHAR] = (t_pars_proc){PARS_DROP, PARS_TAKE, SYNT_ERR_PARS_RD_MD, TOK_NEW};
	pars->pars_decision[HEREDOC_PARS_RD_MD][END_CHAR] = (t_pars_proc){PARS_CATCH, PARS_SKIP, NEW_PARS_RD_MD, TOK_NEW};
	*/
	return (0);
}

int	ft_init_pars_decision_7(t_pars *pars)
{
	(void)pars;
/*	pars->pars_decision[GGRT_PARS_RD_MD][SEP_CHAR] = (t_pars_proc){PARS_CATCH, PARS_SKIP, NEW_PARS_RD_MD, TOK_NEW};
	pars->pars_decision[GGRT_PARS_RD_MD][STD_CHAR] = (t_pars_proc){PARS_CATCH, PARS_TAKE, STD_PARS_RD_MD, TOK_WORD};
	pars->pars_decision[GGRT_PARS_RD_MD][SPL_CHAR] = (t_pars_proc){PARS_CATCH, PARS_SKIP, SPL_PARS_RD_MD, TOK_WORD};
	pars->pars_decision[GGRT_PARS_RD_MD][DBL_CHAR] = (t_pars_proc){PARS_CATCH, PARS_SKIP, SPL_PARS_RD_MD, TOK_WORD};
	pars->pars_decision[GGRT_PARS_RD_MD][ESCP_CHAR] = (t_pars_proc){PARS_CATCH, PARS_SKIP, ESCP_PARS_RD_MD, TOK_NEW};
	pars->pars_decision[GGRT_PARS_RD_MD][PIPE_CHAR] = (t_pars_proc){PARS_CATCH, PARS_SKIP, SYNT_ERR_PARS_RD_MD, TOK_NEW};
	pars->pars_decision[GGRT_PARS_RD_MD][AMP_CHAR] = (t_pars_proc){PARS_CATCH, PARS_SKIP, SYNT_ERR_PARS_RD_MD, TOK_NEW};
	pars->pars_decision[GGRT_PARS_RD_MD][LT_CHAR] = (t_pars_proc){PARS_CATCH, PARS_SKIP, SYNT_ERR_PARS_RD_MD, TOK_NEW};
	pars->pars_decision[GGRT_PARS_RD_MD][GT_CHAR] = (t_pars_proc){PARS_CATCH, PARS_SKIP, SPL_PARS_RD_MD, TOK_GGRT};
	pars->pars_decision[GGRT_PARS_RD_MD][END_CHAR] = (t_pars_proc){PARS_CATCH, PARS_SKIP, NEW_PARS_RD_MD, TOK_NEW};
	*/
	return (0);
}
