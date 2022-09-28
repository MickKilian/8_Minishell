/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 15:22:22 by mbourgeo          #+#    #+#             */
/*   Updated: 2022/09/28 15:42:15 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_command	*ft_new_command(t_token *token)
{
	t_command	*new;

	if (ft_mallocator(&new, sizeof(t_command)))
		return (0);
	//if (ft_mallocator(&new->id, sizeof(str)))
	//	return (0);
	//if (ft_mallocator(&new, sizeof(t_token)) || ft_mallocator(&new->id, sizeof(str)))
	//	return (0);
	new->token = token;
	new->prev = new;
	new->next = new;
	//printf("ok\n");
	return (new);
}

t_command	*ft_command_addnext(t_command *current, t_command *next)
{
	if (!current)
		return (current = next, current);
	else if (!next)
		return(ft_msgerr(ERR_NULLCMD), NULL);
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

/*t_token	*ft_token_jumpcurrent(t_token *prev, t_token *next)
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
}*/
