/* ***********ll*************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 15:22:22 by mbourgeo          #+#    #+#             */
/*   Updated: 2022/09/26 02:42:25 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_token	*ft_new_token(char *str)
{
	t_token	*new;

	if (ft_mallocator(&new, sizeof(t_token)))
		return (0);
	//if (ft_mallocator(&new->id, sizeof(str)))
	//	return (0);
	//if (ft_mallocator(&new, sizeof(t_token)) || ft_mallocator(&new->id, sizeof(str)))
	//	return (0);
	new->id = ft_strndup(str, 0);
	new->type = NEW;
	new->prev = new;
	new->next = new;
	//printf("ok\n");
	return (new);
}

t_token	*ft_token_addnext(t_token *current, t_token *next)
{
	if (!current)
		return (current = next, current);
	else if (!next)
		return(ft_msgerr(ERR_NULLELEM), NULL);
	else
	{
		next->prev = current;
		next->next = current->next;
		//if (current->next == current)
		//	current->prev = new;
		//else
			current->next->prev = next;
		current->next = next;
	}
	return (next);
}

t_token	*ft_token_jumpcurrent(t_token *prev, t_token *next)
{
	if (next->next != next)
	{
		prev->next = next;
		next->prev = prev;
	}
	return (next);
}

int	ft_free_tokenlist(t_lex *lex)
{
	t_token	*temp;
	t_token	*current;

	if (!lex->token)
		return (1);
	current = lex->token;
	while (1)
	{
		temp = current;
		current = ft_token_jumpcurrent(current->prev, current->next);
		free(temp->id);
		temp->id = NULL;
		free(temp);
		if (current == temp)
			break ;
		temp = NULL;
		//printf("cu : %p\n", current);
		//printf("cu>next : %p\n", current->next);
	}
	temp = NULL;
	lex->token = NULL;
	return (0);
}
