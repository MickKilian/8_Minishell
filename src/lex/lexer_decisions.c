/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_decisions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 00:47:14 by mbourgeo          #+#    #+#             */
/*   Updated: 2022/09/15 11:59:28 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_init_decision_1(t_lex *lex)
{
	lex->decision[NEW_MODE][SEP_CHAR] = {KEEP, SKIP, NEW_MODE};
	lex->decision[NEW_MODE][STD_CHAR] = {KEEP, TAKE, STD_MODE};
	lex->decision[NEW_MODE][SPLQ_CHAR] = {KEEP, SKIP, SPL_MODE};
	lex->decision[NEW_MODE][DBLQ_CHAR] = {KEEP, SKIP, DBL_MODE};
	lex->decision[NEW_MODE][PIPE_CHAR] = {KEEP, TAKE, PIPE_MODE};
	lex->decision[NEW_MODE][AMP_CHAR] = {KEEP, TAKE, AMP_MODE};
	lex->decision[NEW_MODE][LT_CHAR] = {KEEP, TAKE, REDIN_MODE};
	lex->decision[NEW_MODE][GT_CHAR] = {KEEP, TAKE, REDOUT_MODE};
	lex->decision[STD_MODE][SEP_CHAR] = {NEXT, SKIP, STD_MODE};
	lex->decision[STD_MODE][STD_CHAR] = {KEEP, TAKE, STD_MODE};
	lex->decision[STD_MODE][SPLQ_CHAR] = {KEEP, SKIP, SPL_MODE};
	lex->decision[STD_MODE][DBLQ_CHAR] = {KEEP, SKIP, DBL_MODE};
	lex->decision[STD_MODE][PIPE_CHAR] = {CATCH, TAKE, PIPE_MODE};
	lex->decision[STD_MODE][AMP_CHAR] = {CATCH, TAKE, AMP_MODE};
	lex->decision[STD_MODE][LT_CHAR] = {CATCH, TAKE, REDIN_MODE};
	lex->decision[STD_MODE][GT_CHAR] = {CATCH, TAKE, REDOUT_MODE};
	return (0);
}

int	ft_init_decision_2(t_lex *lex)
{
	lex->decision[SPL_MODE][SEP_CHAR] = {KEEP, TAKE, SPL_MODE};
	lex->decision[SPL_MODE][STD_CHAR] = {KEEP, TAKE, SPL_MODE};
	lex->decision[SPL_MODE][SPLQ_CHAR] = {CATCH, SKIP, NEW_MODE};
	lex->decision[SPL_MODE][DBLQ_CHAR] = {KEEP, TAKE, SPL_MODE};
	lex->decision[SPL_MODE][PIPE_CHAR] = {KEEP, TAKE, SPL_MODE};
	lex->decision[SPL_MODE][AMP_CHAR] = {KEEP, TAKE, SPL_MODE};
	lex->decision[SPL_MODE][LT_CHAR] = {KEEP, TAKE, SPL_MODE};
	lex->decision[SPL_MODE][GT_CHAR] = {KEEP, TAKE, SPL_MODE};
	lex->decision[DBL_MODE][SEP_CHAR] = {KEEP, TAKE, DBL_MODE};
	lex->decision[DBL_MODE][STD_CHAR] = {KEEP, TAKE, DBL_MODE};
	lex->decision[DBL_MODE][SPLQ_CHAR] = {CATCH, SKIP, NEW_MODE};
	lex->decision[DBL_MODE][DBLQ_CHAR] = {KEEP, TAKE, DBL_MODE};
	lex->decision[DBL_MODE][PIPE_CHAR] = {KEEP, TAKE, DBL_MODE};
	lex->decision[DBL_MODE][AMP_CHAR] = {KEEP, TAKE, DBL_MODE};
	lex->decision[DBL_MODE][LT_CHAR] = {KEEP, TAKE, DBL_MODE};
	lex->decision[DBL_MODE][GT_CHAR] = {KEEP, TAKE, DBL_MODE};
	return (0);
}

int	ft_init_decision_3(t_lex *lex)
{
	lex->decision[PIPE_MODE][SEP_CHAR] = {CATCH, SKIP NEW_MODE};
	lex->decision[PIPE_MODE][STD_CHAR] = {CATCH, TAKE, SPL_MODE};
	lex->decision[PIPE_MODE][SPLQ_CHAR] = {CATCH, SKIP, SPL_MODE};
	lex->decision[PIPE_MODE][DBLQ_CHAR] = {CATCH, SKIP, SPL_MODE};
	lex->decision[PIPE_MODE][PIPE_CHAR] = {KEEP, TAKE, OR_MODE};
//check following case
	lex->decision[PIPE_MODE][AMP_CHAR] = {CATCH, TAKE, AMP_MODE};
	lex->decision[PIPE_MODE][LT_CHAR] = {TAKE, CONT_REC, SPL_MODE};
	lex->decision[PIPE_MODE][GT_CHAR] = {TAKE, CONT_REC, SPL_MODE};
	lex->decision[AMP_MODE][SEP_CHAR] = {DROP, SKIP, SYNT_ERR_MODE};
	lex->decision[AMP_MODE][STD_CHAR] = {DROP, SKIP, SYNT_ERR_MODE};
	lex->decision[AMP_MODE][SPLQ_CHAR] = {DROP, SKIP, SYNT_ERR_MODE};
	lex->decision[AMP_MODE][DBLQ_CHAR] = {DROP, SKIP, SYNT_ERR_MODE};
	lex->decision[AMP_MODE][PIPE_CHAR] = {DROP, SKIP, SYNT_ERR_MODE};
	lex->decision[AMP_MODE][AMP_CHAR] = {CATCH, TAKE, AND_MODE};
	lex->decision[AMP_MODE][LT_CHAR] = {DROP, SKIP, SYNT_ERR_MODE};
	lex->decision[AMP_MODE][GT_CHAR] = {DROP, SKIP, SYNT_ERR_MODE};
	return (0);
}

int	ft_init_decision_4(t_lex *lex)
{
	lex->decision[LT_MODE][SEP_CHAR] = {CATCH, SKIP, NEW_MODE};
	lex->decision[LT_MODE][STD_CHAR] = {CATCH, TAKE, STD_MODE};
	lex->decision[LT_MODE][SPLQ_CHAR] = {CATCH, SKIP, SPL_MODE};
	lex->decision[LT_MODE][DBLQ_CHAR] = {CATCH, SKIP, DBL_MODE};
	lex->decision[LT_MODE][PIPE_CHAR] = {DROP, SKIP, SYNT_ERR_MODE};
	lex->decision[LT_MODE][AMP_CHAR] = {DROP, SKIP, SYNT_ERR_MODE};
	lex->decision[LT_MODE][LT_CHAR] = {KEEP, TAKE, HEREDOC_MODE};
	lex->decision[LT_MODE][GT_CHAR] = {DROP, SKIP, SYNT_ERR_MODE};
	lex->decision[GT_MODE][SEP_CHAR] = {CATCH, SKIP, NEW_MODE};
	//CONTINUE
	lex->decision[GT_MODE][STD_CHAR] = {CATCH, TAKE, SPL_MODE};
	lex->decision[GT_MODE][SPLQ_CHAR] = {CATCH, SKIP, SPL_MODE};
	lex->decision[GT_MODE][DBLQ_CHAR] = {CATCH, SKIP, SPL_MODE};
	lex->decision[GT_MODE][PIPE_CHAR] = {KEEP, TAKE, OR_MODE};
	lex->decision[GT_MODE][AMP_CHAR] = {CATCH, TAKE, AMP_MODE};
	lex->decision[GT_MODE][LT_CHAR] = {TAKE, CONT_REC, SPL_MODE};
	lex->decision[GT_MODE][GT_CHAR] = {TAKE, CONT_REC, SPL_MODE};
	return (0);
}

int	ft_init_decision_5(t_lex *lex)
{
	lex->decision[HEREDOC_MODE][SEP_CHAR] = {CATCH, SKIP, NEW_MODE};
	lex->decision[HEREDOC_MODE][STD_CHAR] = {CATCH, TAKE, STD_MODE};
	lex->decision[HEREDOC_MODE][SPLQ_CHAR] = {CATCH, SKIP, SPL_MODE};
	lex->decision[HEREDOC_MODE][DBLQ_CHAR] = {CATCH, SKIP, DBL_MODE};
	lex->decision[HEREDOC_MODE][PIPE_CHAR] = {DROP, SKIP, SYNT_ERR_MODE};
	lex->decision[HEREDOC_MODE][AMP_CHAR] = {DROP, SKIP, SYNT_ERR_MODE};
	lex->decision[HEREDOC_MODE][LT_CHAR] = {KEEP, TAKE, HEREDOC_MODE};
	lex->decision[HEREDOC_MODE][GT_CHAR] = {TAKE, CONT_REC, SPL_MODE};
	return (0);
}
