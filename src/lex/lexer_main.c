/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 00:47:14 by mbourgeo          #+#    #+#             */
/*   Updated: 2022/09/14 18:22:57 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(void)
{
	if (!ft_read_prompt())
		return (1);
	return (0);
}

char	*ft_read_prompt(void)
{
	t_lex	*lex;

	if (ft_mallocator(&lex, sizeof(t_lex)))
		return (ft_msgerr(ERR_MALLOC), NULL);
	ft_init_lex_actions(lex);
	lex->user_input = readline("$>");
	ft_lexer(lex);
	free(lex->user_input);
	free(lex);
	return (NULL);
}

int	ft_lexer(t_lex *lex)
{
	//int	i;

	//i = 0;
	//while (lex->user_input[i])
		//(lex->ft[lex->decision[lex->read_mode][(int)lex->user_input[i++]]])();
	//	*(lex->ft[1])(lex);
	ft_lex_ignore(lex);
	return (0);
}
