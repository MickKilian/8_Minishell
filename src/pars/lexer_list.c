/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 15:22:22 by mbourgeo          #+#    #+#             */
/*   Updated: 2022/10/07 18:28:43 by mbourgeo         ###   ########.fr       */
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
	new->type = TOK_WORD;
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
		return(ft_msgerr(ERR_NULLTKN), NULL);
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

int	ft_free_tokenlist(t_token *token)
{
	t_token	*temp;
	t_token	*current;

	if (!token)
		return (1);
	current = token;
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
	token = NULL;
	return (0);
}

t_token *ft_free_one_token(t_token *token)
{
	t_token	*temp;
	t_token	*current;

	if (!token)
		return (NULL);
	current = token;
	//while (1)
	//{
	temp = current;
	current = ft_token_jumpcurrent(current->prev, current->next);
	//printf("\033[37;1mHello World!\033[0m\n");
	free(temp->id);
	temp->id = NULL;
	free(temp);
	//if (current == temp)
	//	break ;
	temp = NULL;
	//}
	//temp = NULL;
	//token = NULL;
	return (current);
}
