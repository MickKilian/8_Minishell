/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_memory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 00:47:14 by mbourgeo          #+#    #+#             */
/*   Updated: 2022/09/26 02:35:10 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_bzero(void *s, size_t n)
{
	while (n--)
		*(char *)s++ = '\0';
}

int	ft_mallocator(void *ptr, size_t size)
{
	*(void **)ptr = malloc(size);
	if (!*(void **)ptr)
		return (ft_msgerr(ERR_MALLOC), 1);
	ft_bzero(*(void **)ptr, size);
	return (0);
}

int	ft_freeall(t_lex *lex)
{
	//free(lex->temp);
	//printf("in freeall\n");
	//lex->prev_decision = NUL;
	//lex->new_decision = NUL;
	ft_free_tokenlist(lex);
	*(&(lex->token)) = NULL;
	return (0);
}
