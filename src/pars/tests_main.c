/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 00:47:14 by mbourgeo          #+#    #+#             */
/*   Updated: 2022/10/08 22:56:14 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(void)
{
	if (ft_tests())
		return (1);
	return (0);
}

int	ft_tests(void)
{
	int			fd;
	char		*user_input;
	char		*temp;

	fd = open("parser.test", O_RDONLY, 644);
	if (fd < 0)
		return (ft_msgerr(ERR_TESTFILE), 1);
	user_input = get_next_line(fd);
	temp = user_input;
	while (user_input)
	{
		ft_read_prompt(user_input);
		user_input = get_next_line(fd);
		temp = user_input;
	}
	if (temp)
	{
		free(temp);
		temp = NULL;
	}
	close(fd);
	return (0);
}
