/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirector_file_manager.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 00:47:14 by mbourgeo          #+#    #+#             */
/*   Updated: 2022/10/08 00:16:41 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_open_infile(t_pars *pars, char *file)
{
	if (pars->hdoc)
	{
	//	ft_heredoc(file);
	//	pars->fd_in = open(".heredoc_tmp", O_RDWR);
	//	if (pars->fd_in < 0)
	//	{
	//		unlink(".heredoc_tmp");
	//		return (ft_msgerr(ERR_FILEHEREDOC));
	//	}
	}
	else
	{
		pars->fd_in = open(file, O_RDWR);
	}
	if (pars->fd_in < 0)
	{
		//perror(file);
		//return (1);
		return (ft_msgerr(ERR_FILEIN));
	}
	//printf("fd_in = %d\n", pars->fd_in);
	return (0);
}

int	ft_open_outfile(t_pars *pars, char *file)
{
	pars->fd_out = open(file, O_RDWR | O_CREAT | O_TRUNC, 0664);
	if (pars->fd_out < 0)
	{
		ft_msgerr(ERR_FILEOUT);
		//perror(file);
		//return (1);
		return (ft_msgerr(ERR_FILEOUT));
	}
	//printf("fd_out = %d\n", pars->fd_out);
	return (0);
}

int	ft_open_append_outfile(t_pars *pars, char *file)
{
	pars->fd_out = open(file, O_WRONLY | O_CREAT | O_APPEND, 0664);
	if (pars->fd_out < 0)
	{
		ft_msgerr(ERR_FILEOUT);
		//perror(file);
		//return (1);
		return (ft_msgerr(ERR_FILEOUT));
	}
	//printf("fd_out = %d\n", pars->fd_out);
	return (0);
}
