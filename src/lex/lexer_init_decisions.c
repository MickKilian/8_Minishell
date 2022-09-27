/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_init_decisions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 00:47:14 by mbourgeo          #+#    #+#             */
/*   Updated: 2022/09/27 17:33:07 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_init_decision_1(t_lex *lex)
{
	lex->decision[NEW_MODE][SEP_CHAR] = (t_lex_proc){DROP, SKIP, NEW_MODE, NEW};
	lex->decision[NEW_MODE][STD_CHAR] = (t_lex_proc){KEEP, TAKE, STD_MODE, WORD};
	lex->decision[NEW_MODE][SPL_CHAR] = (t_lex_proc){KEEP, TAKE, SPL_MODE, WORD};
	lex->decision[NEW_MODE][DBL_CHAR] = (t_lex_proc){KEEP, TAKE, DBL_MODE, WORD};
	lex->decision[NEW_MODE][ESCP_CHAR] = (t_lex_proc){KEEP, SKIP, ESCP_MODE, NEW};
	lex->decision[NEW_MODE][PIPE_CHAR] = (t_lex_proc){KEEP, TAKE, PIPE_MODE, PIPE};
	lex->decision[NEW_MODE][AMP_CHAR] = (t_lex_proc){KEEP, TAKE, AMP_MODE, AMP};
	lex->decision[NEW_MODE][LT_CHAR] = (t_lex_proc){KEEP, TAKE, LT_MODE, LSS};
	lex->decision[NEW_MODE][GT_CHAR] = (t_lex_proc){KEEP, TAKE, GT_MODE, GRT};
	lex->decision[NEW_MODE][END_CHAR] = (t_lex_proc){END, SKIP, NEW_MODE, END_OF_INPUT};
	lex->decision[STD_MODE][SEP_CHAR] = (t_lex_proc){CATCH, SKIP, NEW_MODE, NEW};
	lex->decision[STD_MODE][STD_CHAR] = (t_lex_proc){KEEP, TAKE, STD_MODE, WORD};
	lex->decision[STD_MODE][SPL_CHAR] = (t_lex_proc){KEEP, TAKE, SPL_MODE, WORD};
	lex->decision[STD_MODE][DBL_CHAR] = (t_lex_proc){KEEP, TAKE, DBL_MODE, WORD};
	lex->decision[STD_MODE][ESCP_CHAR] = (t_lex_proc){KEEP, SKIP, ESCP_MODE, WORD};
	lex->decision[STD_MODE][PIPE_CHAR] = (t_lex_proc){CATCH, TAKE, PIPE_MODE, PIPE};
	lex->decision[STD_MODE][AMP_CHAR] = (t_lex_proc){CATCH, TAKE, AMP_MODE, AMP};
	lex->decision[STD_MODE][LT_CHAR] = (t_lex_proc){CATCH, TAKE, LT_MODE, LSS};
	lex->decision[STD_MODE][GT_CHAR] = (t_lex_proc){CATCH, TAKE, GT_MODE, GRT};
	lex->decision[STD_MODE][END_CHAR] = (t_lex_proc){CATCH, SKIP, NEW_MODE, NEW};
	return (0);
}

int	ft_init_decision_2(t_lex *lex)
{
	lex->decision[SPL_MODE][SEP_CHAR] = (t_lex_proc){KEEP, TAKE, SPL_MODE, WORD};
	lex->decision[SPL_MODE][STD_CHAR] = (t_lex_proc){KEEP, TAKE, SPL_MODE, SPL};
	lex->decision[SPL_MODE][SPL_CHAR] = (t_lex_proc){KEEP, TAKE, STD_MODE, NEW};
	lex->decision[SPL_MODE][DBL_CHAR] = (t_lex_proc){KEEP, TAKE, SPL_MODE, SPL};
	lex->decision[SPL_MODE][ESCP_CHAR] = (t_lex_proc){KEEP, SKIP, SPL_MODE, WORD};
	lex->decision[SPL_MODE][PIPE_CHAR] = (t_lex_proc){KEEP, TAKE, SPL_MODE, WORD};
	lex->decision[SPL_MODE][AMP_CHAR] = (t_lex_proc){KEEP, TAKE, SPL_MODE, WORD};
	lex->decision[SPL_MODE][LT_CHAR] = (t_lex_proc){KEEP, TAKE, SPL_MODE, WORD};
	lex->decision[SPL_MODE][GT_CHAR] = (t_lex_proc){KEEP, TAKE, SPL_MODE, WORD};
	lex->decision[SPL_MODE][END_CHAR] = (t_lex_proc){SYNT_ERR, DROP, SYNT_ERR_MODE, NEW};
	lex->decision[DBL_MODE][SEP_CHAR] = (t_lex_proc){KEEP, TAKE, DBL_MODE, WORD};
	lex->decision[DBL_MODE][STD_CHAR] = (t_lex_proc){KEEP, TAKE, DBL_MODE, DBL};
	lex->decision[DBL_MODE][SPL_CHAR] = (t_lex_proc){KEEP, TAKE, DBL_MODE, DBL};
	lex->decision[DBL_MODE][DBL_CHAR] = (t_lex_proc){KEEP, TAKE, STD_MODE, NEW};
	lex->decision[DBL_MODE][ESCP_CHAR] = (t_lex_proc){KEEP, SKIP, DBL_MODE, WORD};
	lex->decision[DBL_MODE][PIPE_CHAR] = (t_lex_proc){KEEP, TAKE, DBL_MODE, WORD};
	lex->decision[DBL_MODE][AMP_CHAR] = (t_lex_proc){KEEP, TAKE, DBL_MODE, WORD};
	lex->decision[DBL_MODE][LT_CHAR] = (t_lex_proc){KEEP, TAKE, DBL_MODE, WORD};
	lex->decision[DBL_MODE][GT_CHAR] = (t_lex_proc){KEEP, TAKE, DBL_MODE, WORD};
	lex->decision[DBL_MODE][END_CHAR] = (t_lex_proc){DROP, SKIP, SYNT_ERR_MODE, NEW};
	return (0);
}

int	ft_init_decision_3(t_lex *lex)
{
	lex->decision[ESCP_MODE][SEP_CHAR] = (t_lex_proc){KEEP, SKIP, NEW_MODE, NEW};
	lex->decision[ESCP_MODE][STD_CHAR] = (t_lex_proc){KEEP, TAKE, STD_MODE, WORD};
	lex->decision[ESCP_MODE][SPL_CHAR] = (t_lex_proc){CATCH, SKIP, SPL_MODE, WORD};
	lex->decision[ESCP_MODE][DBL_CHAR] = (t_lex_proc){CATCH, SKIP, DBL_MODE, WORD};
	lex->decision[ESCP_MODE][ESCP_CHAR] = (t_lex_proc){KEEP, SKIP, ESCP_MODE, NEW};
	lex->decision[ESCP_MODE][PIPE_CHAR] = (t_lex_proc){DROP, SKIP, SYNT_ERR_MODE, NEW};
	lex->decision[ESCP_MODE][AMP_CHAR] = (t_lex_proc){DROP, SKIP, SYNT_ERR_MODE, NEW};
	lex->decision[ESCP_MODE][LT_CHAR] = (t_lex_proc){DROP, TAKE, SYNT_ERR_MODE, NEW};
	lex->decision[ESCP_MODE][GT_CHAR] = (t_lex_proc){DROP, TAKE, SYNT_ERR_MODE, NEW};
	lex->decision[ESCP_MODE][END_CHAR] = (t_lex_proc){CATCH, SKIP, NEW_MODE, NEW};
	lex->decision[PIPE_MODE][SEP_CHAR] = (t_lex_proc){CATCH, SKIP, NEW_MODE, NEW};
	lex->decision[PIPE_MODE][STD_CHAR] = (t_lex_proc){CATCH, TAKE, STD_MODE, WORD};
	lex->decision[PIPE_MODE][SPL_CHAR] = (t_lex_proc){CATCH, SKIP, SPL_MODE, WORD};
	lex->decision[PIPE_MODE][DBL_CHAR] = (t_lex_proc){CATCH, SKIP, DBL_MODE, WORD};
	lex->decision[PIPE_MODE][ESCP_CHAR] = (t_lex_proc){CATCH, SKIP, ESCP_MODE, NEW};
	lex->decision[PIPE_MODE][PIPE_CHAR] = (t_lex_proc){KEEP, TAKE, OR_MODE, OP_OR};
//check following case
	lex->decision[PIPE_MODE][AMP_CHAR] = (t_lex_proc){CATCH, TAKE, AMP_MODE, AMP};
	lex->decision[PIPE_MODE][LT_CHAR] = (t_lex_proc){KEEP, TAKE, SYNT_ERR_MODE, NEW};
	lex->decision[PIPE_MODE][GT_CHAR] = (t_lex_proc){KEEP, TAKE, SYNT_ERR_MODE, NEW};
	lex->decision[PIPE_MODE][END_CHAR] = (t_lex_proc){DROP, SKIP, SYNT_ERR_MODE, NEW};
	return (0);
}

int	ft_init_decision_4(t_lex *lex)
{
	lex->decision[AMP_MODE][SEP_CHAR] = (t_lex_proc){CATCH, SKIP, NEW_MODE, NEW};
	lex->decision[AMP_MODE][STD_CHAR] = (t_lex_proc){CATCH, TAKE, STD_MODE, WORD};
	lex->decision[AMP_MODE][SPL_CHAR] = (t_lex_proc){CATCH, SKIP, SYNT_ERR_MODE, NEW};
	lex->decision[AMP_MODE][DBL_CHAR] = (t_lex_proc){DROP, SKIP, SYNT_ERR_MODE, NEW};
	lex->decision[AMP_MODE][ESCP_CHAR] = (t_lex_proc){CATCH, SKIP, ESCP_MODE, NEW};
	lex->decision[AMP_MODE][PIPE_CHAR] = (t_lex_proc){DROP, SKIP, SYNT_ERR_MODE, NEW};
	lex->decision[AMP_MODE][AMP_CHAR] = (t_lex_proc){KEEP, TAKE, AND_MODE, OP_AND};
	lex->decision[AMP_MODE][LT_CHAR] = (t_lex_proc){DROP, SKIP, SYNT_ERR_MODE, NEW};
	lex->decision[AMP_MODE][GT_CHAR] = (t_lex_proc){DROP, SKIP, SYNT_ERR_MODE, NEW};
	lex->decision[AMP_MODE][END_CHAR] = (t_lex_proc){DROP, SKIP, SYNT_ERR_MODE, NEW};
	lex->decision[LT_MODE][SEP_CHAR] = (t_lex_proc){CATCH, SKIP, NEW_MODE, NEW};
	lex->decision[LT_MODE][STD_CHAR] = (t_lex_proc){CATCH, TAKE, STD_MODE, WORD};
	lex->decision[LT_MODE][SPL_CHAR] = (t_lex_proc){CATCH, SKIP, SPL_MODE, WORD};
	lex->decision[LT_MODE][DBL_CHAR] = (t_lex_proc){CATCH, SKIP, DBL_MODE, WORD};
	lex->decision[LT_MODE][ESCP_CHAR] = (t_lex_proc){CATCH, SKIP, ESCP_MODE, NEW};
	lex->decision[LT_MODE][PIPE_CHAR] = (t_lex_proc){DROP, SKIP, SYNT_ERR_MODE, NEW};
	lex->decision[LT_MODE][AMP_CHAR] = (t_lex_proc){DROP, SKIP, SYNT_ERR_MODE, NEW};
	lex->decision[LT_MODE][LT_CHAR] = (t_lex_proc){KEEP, TAKE, HEREDOC_MODE, HEREDOC};
	lex->decision[LT_MODE][GT_CHAR] = (t_lex_proc){DROP, SKIP, SYNT_ERR_MODE, WORD};
	lex->decision[LT_MODE][END_CHAR] = (t_lex_proc){CATCH, SKIP, NEW_MODE, NEW};
	return (0);
	return (0);
}

int	ft_init_decision_5(t_lex *lex)
{
	lex->decision[GT_MODE][SEP_CHAR] = (t_lex_proc){CATCH, SKIP, NEW_MODE, NEW};
	lex->decision[GT_MODE][STD_CHAR] = (t_lex_proc){CATCH, TAKE, STD_MODE, WORD};
	lex->decision[GT_MODE][SPL_CHAR] = (t_lex_proc){CATCH, SKIP, SPL_MODE, WORD};
	lex->decision[GT_MODE][DBL_CHAR] = (t_lex_proc){CATCH, SKIP, SPL_MODE, WORD};
	lex->decision[GT_MODE][ESCP_CHAR] = (t_lex_proc){CATCH, SKIP, ESCP_MODE, NEW};
	lex->decision[GT_MODE][PIPE_CHAR] = (t_lex_proc){CATCH, SKIP, SYNT_ERR_MODE, NEW};
	lex->decision[GT_MODE][AMP_CHAR] = (t_lex_proc){CATCH, SKIP, SYNT_ERR_MODE, NEW};
	lex->decision[GT_MODE][LT_CHAR] = (t_lex_proc){CATCH, SKIP, SYNT_ERR_MODE, NEW};
	lex->decision[GT_MODE][GT_CHAR] = (t_lex_proc){KEEP, TAKE, GGRT_MODE, GGRT};
	lex->decision[GT_MODE][END_CHAR] = (t_lex_proc){CATCH, SKIP, NEW_MODE, NEW};
	lex->decision[OR_MODE][SEP_CHAR] = (t_lex_proc){CATCH, SKIP, NEW_MODE, NEW};
	lex->decision[OR_MODE][STD_CHAR] = (t_lex_proc){CATCH, TAKE, STD_MODE, WORD};
	lex->decision[OR_MODE][SPL_CHAR] = (t_lex_proc){CATCH, SKIP, SYNT_ERR_MODE, NEW};
	lex->decision[OR_MODE][DBL_CHAR] = (t_lex_proc){DROP, SKIP, SYNT_ERR_MODE, NEW};
	lex->decision[OR_MODE][ESCP_CHAR] = (t_lex_proc){CATCH, SKIP, ESCP_MODE, NEW};
	lex->decision[OR_MODE][PIPE_CHAR] = (t_lex_proc){DROP, SKIP, SYNT_ERR_MODE, NEW};
	lex->decision[OR_MODE][AMP_CHAR] = (t_lex_proc){CATCH, TAKE, AND_MODE, OP_AND};
	lex->decision[OR_MODE][LT_CHAR] = (t_lex_proc){DROP, SKIP, SYNT_ERR_MODE, NEW};
	lex->decision[OR_MODE][GT_CHAR] = (t_lex_proc){DROP, SKIP, SYNT_ERR_MODE, NEW};
	lex->decision[OR_MODE][END_CHAR] = (t_lex_proc){DROP, SKIP, SYNT_ERR_MODE, NEW};
	return (0);
}

int	ft_init_decision_6(t_lex *lex)
{
	lex->decision[AND_MODE][SEP_CHAR] = (t_lex_proc){CATCH, SKIP, NEW_MODE, NEW};
	lex->decision[AND_MODE][STD_CHAR] = (t_lex_proc){CATCH, TAKE, STD_MODE, WORD};
	lex->decision[AND_MODE][SPL_CHAR] = (t_lex_proc){CATCH, SKIP, SPL_MODE, WORD};
	lex->decision[AND_MODE][DBL_CHAR] = (t_lex_proc){CATCH, SKIP, DBL_MODE, WORD};
	lex->decision[AND_MODE][ESCP_CHAR] = (t_lex_proc){CATCH, SKIP, ESCP_MODE, NEW};
	lex->decision[AND_MODE][PIPE_CHAR] = (t_lex_proc){DROP, SKIP, SYNT_ERR_MODE, NEW};
	lex->decision[AND_MODE][AMP_CHAR] = (t_lex_proc){DROP, SKIP, SYNT_ERR_MODE, NEW};
	lex->decision[AND_MODE][LT_CHAR] = (t_lex_proc){KEEP, TAKE, HEREDOC_MODE, HEREDOC};
	lex->decision[AND_MODE][GT_CHAR] = (t_lex_proc){DROP, SKIP, SYNT_ERR_MODE, WORD};
	lex->decision[AND_MODE][END_CHAR] = (t_lex_proc){DROP, SKIP, SYNT_ERR_MODE, NEW};
	lex->decision[HEREDOC_MODE][SEP_CHAR] = (t_lex_proc){CATCH, SKIP, NEW_MODE, NEW};
	lex->decision[HEREDOC_MODE][STD_CHAR] = (t_lex_proc){CATCH, TAKE, STD_MODE, WORD};
	lex->decision[HEREDOC_MODE][SPL_CHAR] = (t_lex_proc){CATCH, SKIP, SPL_MODE, WORD};
	lex->decision[HEREDOC_MODE][DBL_CHAR] = (t_lex_proc){CATCH, SKIP, DBL_MODE, WORD};
	lex->decision[HEREDOC_MODE][ESCP_CHAR] = (t_lex_proc){KEEP, SKIP, ESCP_MODE, NEW};
	lex->decision[HEREDOC_MODE][PIPE_CHAR] = (t_lex_proc){DROP, SKIP, SYNT_ERR_MODE, NEW};
	lex->decision[HEREDOC_MODE][AMP_CHAR] = (t_lex_proc){DROP, SKIP, SYNT_ERR_MODE, NEW};
	lex->decision[HEREDOC_MODE][LT_CHAR] = (t_lex_proc){DROP, TAKE, SYNT_ERR_MODE, NEW};
	lex->decision[HEREDOC_MODE][GT_CHAR] = (t_lex_proc){DROP, TAKE, SYNT_ERR_MODE, NEW};
	lex->decision[HEREDOC_MODE][END_CHAR] = (t_lex_proc){CATCH, SKIP, NEW_MODE, NEW};
	return (0);
}

int	ft_init_decision_7(t_lex *lex)
{
	lex->decision[GGRT_MODE][SEP_CHAR] = (t_lex_proc){CATCH, SKIP, NEW_MODE, NEW};
	lex->decision[GGRT_MODE][STD_CHAR] = (t_lex_proc){CATCH, TAKE, STD_MODE, WORD};
	lex->decision[GGRT_MODE][SPL_CHAR] = (t_lex_proc){CATCH, SKIP, SPL_MODE, WORD};
	lex->decision[GGRT_MODE][DBL_CHAR] = (t_lex_proc){CATCH, SKIP, SPL_MODE, WORD};
	lex->decision[GGRT_MODE][ESCP_CHAR] = (t_lex_proc){CATCH, SKIP, ESCP_MODE, NEW};
	lex->decision[GGRT_MODE][PIPE_CHAR] = (t_lex_proc){CATCH, SKIP, SYNT_ERR_MODE, NEW};
	lex->decision[GGRT_MODE][AMP_CHAR] = (t_lex_proc){CATCH, SKIP, SYNT_ERR_MODE, NEW};
	lex->decision[GGRT_MODE][LT_CHAR] = (t_lex_proc){CATCH, SKIP, SYNT_ERR_MODE, NEW};
	lex->decision[GGRT_MODE][GT_CHAR] = (t_lex_proc){CATCH, SKIP, SPL_MODE, GGRT};
	lex->decision[GGRT_MODE][END_CHAR] = (t_lex_proc){CATCH, SKIP, NEW_MODE, NEW};
	return (0);
}
