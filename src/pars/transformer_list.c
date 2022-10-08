/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformer_list.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 00:47:14 by mbourgeo          #+#    #+#             */
/*   Updated: 2022/10/08 06:16:39 by mbourgeo         ###   ########.fr       */
/*   Updated: 2022/09/30 16:01:12 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_cmd	*ft_new_cmd(char **token)
{
	t_cmd	*new;

	if (ft_mallocator(&new, sizeof(t_cmd)))
		return (0);
	new->token = token;
	new->prev = NULL;
	new->next = NULL;
	return (new);
}

t_cmd	*ft_cmd_addnext(t_cmd *current, t_cmd *next)
{
	if (!current)
		return (current = next, current);
	else if (!next)
		return(ft_msgerr(ERR_NULLCMD), NULL);
	else
	{
		next->prev = current;
		current->next = next;
	}
	return (next);
}

int	ft_free_cmdlist(t_cmd *cmd)
{
	t_cmd	*temp;
	t_cmd	*current;

	current = cmd;
	while (1)
	{
		temp = current;
		current = current->next;
		ft_free_token(temp->token, cmd->nb_of_tokens);
		free(temp);
		if (current == NULL)
			break ;
		temp = NULL;
	}
	cmd = NULL;
	return (0);
}

char	**ft_token_list_to_tab(t_command *command)
{
	int		i;
	char	**temp;

	i = 0;
	temp = malloc((command->nb_of_tokens + 1) * sizeof(char *));
	if (!temp)
		return (NULL);
	while (i++ < command->nb_of_tokens)
	{
		temp[i - 1] = ft_strndup(command->token->id, 0);
		command->token = command->token->next;
	}
	temp[i] = 0;
	return (temp);
}

int	ft_free_token(char **token, int len)
{
	int	i;

	i = 0;
	while (i++ < len)
	{
		free(token[i]);
		token[i] = NULL;
	}
	free(token);
	return (0);
}
