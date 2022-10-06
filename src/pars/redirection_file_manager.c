/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection_file_manager.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 00:47:14 by mbourgeo          #+#    #+#             */
/*   Updated: 2022/10/06 22:13:42 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_openinfile(t_pars *pars, char *file)
{
	if (pars->hdoc)
	{
		ft_heredoc(file);
		pars>fd_in = open(".heredoc_tmp", O_RDWR);
		if (pars->fd_in < 0)
		{
			unlink(".heredoc_tmp");
			return (ft_msgerr(ERR_FILEHEREDOC));
		}
	}
	else
	{
		pars->fd_in = open(file, O_RDWR);
	}
	if (pars->fd_in < 0)
	{
		perror(file);
		return (1);
	}
	return (0);
}

int	ft_openoutfile(t_pars *pars, char *file)
{
	if (pars->hdoc)
		pars->fd_out = open(file, O_WRONLY | O_CREAT | O_APPEND, 0664);
	else
		pars->fd_out = open(file, O_RDWR | O_CREAT | O_TRUNC, 0664);
	if (pars->fd_out < 0)
	{
		ft_printerr(ERR_FILEOUT);
		perror(file);
		return (1);
	}
	return (0);
}
