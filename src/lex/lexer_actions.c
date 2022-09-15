/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 00:47:14 by mbourgeo          #+#    #+#             */
/*   Updated: 2022/09/14 16:30:26 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	*ft_init_lex_actions(t_lex *lex)
{
	ft_mallocator(&lex->actions, sizeof(int));
	lex->ft[IGNORE] = ft_lex_ignore();
	lex->ft[TAKE] = ft_lex_take();
	lex->ft[CATCH] = ft_lex_catch();
	lex->ft[SYNT_ERR] = ft_lex_synt_err();
	lex->ft[MODE_QT] = ft_lex_qt();
	lex->ft[MODE_RED] = ft_lex_spc();
	lex->ft[MODE_RED] = ft_lex_next();
	return (0);
}

int	ft_lex_ignore(t_lex *lex)
{
	lex->user_input++;
	return (0);
}

int	ft_lex_take(t_lex *lex)
{
	lex->temp[ft_strlen(lex->temp)] = lex->user_input;
	lex->temp[ft_strlen(lex->temp) + 1] = '\0';
	lex->user_input++;
	return (0);
}

int	ft_lex_catch(t_lex *lex)
{
	lex->lexer[lex->group][lex->rank] = ft_strdup(lex->temp);
	lex->rank++;
	return (0);
}

int	ft_lex_synt_err(t_lex *lex)
{
	return (ft_msgerr(ERR_SYNTAX), 0);
}

int	ft_lex_qt(t_lex *lex)
{
	if (lex->temp)
		ft_lex_catch(lex);
	lex->rec_mode = NEW_REC;
	lex->read_mode = (lex->char_type == SPLQ_CHAR) * SPL_MODE
		+ (lex->char_type == DBLQ_CHAR) * DBL_MODE;
	return (0);
}

int	ft_lex_spc(t_lex *lex)
{
	if (lex->temp)
		ft_lex_catch(lex);
	lex->rec_mode = NEW_REC;
	lex->read_mode = SPC_MODE;
	return (0);
}

int	ft_lex_next(t_lex *lex)
{
	ft_lex_take(lex);
	lex->rec_mode = CONT_REC;
	lex->group++;
	ft_lex_catch(lex);
	lex->rank++;
	return (0);
}
