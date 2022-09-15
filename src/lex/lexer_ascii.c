/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_ascii.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 00:47:14 by mbourgeo          #+#    #+#             */
/*   Updated: 2022/09/14 18:29:30 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_ascii_type(char c)
{
	int	type;

	if (c == SP || (c >= HTAB && c <= CRET))
		type = SEP_CHAR;
	if (c == QUOT)
		type = DBL_CHAR;
	if (c == APOS)
		type = SPL_CHAR;
	if (c == VERBAR)
		type = PIPE_CHAR;
	if (c == COMAND)
		type = AMP_CHAR;
	if (c == LT)
		type = LT_CHAR;
	if (c == GT)
		type = GT_CHAR;
	else
		type = STD_CHAR;
	return (type);
}
