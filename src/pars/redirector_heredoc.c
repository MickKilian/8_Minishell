/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirector_heredoc.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 18:18:49 by mbourgeo          #+#    #+#             */
/*   Updated: 2022/10/08 02:48:08 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_open_heredoc(t_pars *pars, char *delim)
{
	char	*str_gnl;
	char	*file_name;
	char	*temp1;
	char	*temp2;

	temp1 = ft_itoa(pars->hdoc_i);
	temp2 = ft_strjoin(".heredoc_", temp1);
	free(temp1);
	temp1 = NULL;
	file_name = ft_strjoin(temp2, "_tmp");
	free(temp2);
	temp2 = NULL;
	pars->fd_in = open(file_name, O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (pars->fd_in < 0)
		return (ft_msgerr(ERR_FILEHDOC));
	while (1)
	{
		write(1, ">", 1);
		str_gnl = get_next_line(0);
		if (str_gnl)
		{
			if (!ft_strncmp(str_gnl, delim, ft_strlen(delim))
				&& ft_strlen(delim) == ft_strlen(str_gnl) - 1)
				break ;
			else
			{
				write(pars->fd_in, str_gnl, ft_strlen(str_gnl));
				free(str_gnl);
			}
		}
	}
	free(str_gnl);
	pars->hdoc_list = ft_hdoc_addnext(pars->hdoc_list, ft_new_hdoc(file_name, pars->fd_in));
	//printf("***** <%s> created!\n", file_name);
	//printf("elems of hdoclist are : %s, %d", pars->hdoc_list->file_name, pars->hdoc_list->fd);
	free(file_name);
	return (0);
}

int	ft_heredoc_append(t_pars *pars, char *delim)
{
	char	*str_gnl;

	while (1)
	{
		write(1, ">", 1);
		str_gnl = get_next_line(0);
		if (str_gnl)
		{
			if (!ft_strncmp(str_gnl, delim, ft_strlen(delim))
				&& ft_strlen(delim) == ft_strlen(str_gnl) - 1)
				break ;
			else
			{
				write(pars->fd_in, str_gnl, ft_strlen(str_gnl));
				free(str_gnl);
			}
		}
	}
	free(str_gnl);
	//printf("***** <%s> appended!\n", pars->hdoc_list->file_name);
	return (0);
}

t_hdoc	*ft_new_hdoc(char *str, int fd)
{
	t_hdoc	*new;

	if (ft_mallocator(&new, sizeof(t_hdoc)))
		return (0);
	new->file_name = ft_strndup(str, 0);
	new->fd = fd;
	new->prev = new;
	new->next = new;
	return (new);
}

t_hdoc	*ft_hdoc_addnext(t_hdoc *current, t_hdoc *next)
{
	if (!current)
		return (current = next, current);
	else if (!next)
		return(ft_msgerr(ERR_NULLHDOC), NULL);
	else
	{
		next->prev = current;
		next->next = current->next;
		current->next->prev = next;
		current->next = next;
	}
	return (next);
}

t_hdoc	*ft_hdoc_jumpcurrent(t_hdoc *prev, t_hdoc *next)
{
	if (next->next != next)
	{
		prev->next = next;
		next->prev = prev;
	}
	return (next);
}

int	ft_free_hdoclist(t_hdoc *hdoc)
{
	t_hdoc	*temp;
	t_hdoc	*current;

	if (!hdoc)
		return (1);
	current = hdoc;
	while (1)
	{
		temp = current;
		current = ft_hdoc_jumpcurrent(current->prev, current->next);
		free(temp->file_name);
		temp->file_name = NULL;
		temp->fd = 0;
		free(temp);
		if (current == temp)
			break ;
		temp = NULL;
	}
	temp = NULL;
	hdoc = NULL;
	return (0);
}
