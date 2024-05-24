/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_mandatory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopoka <lopoka@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 14:34:58 by lopoka            #+#    #+#             */
/*   Updated: 2024/05/24 16:09:17 by lopoka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/pipex.h"

static inline void	ft_open_in_out(t_pipex *stc, int here_doc)
{
	if (!here_doc)
		stc->fd_in = open(stc->av[1], O_RDONLY);
	stc->fd_out = open(stc->av[stc->ac - 1], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (!here_doc && stc->fd_in == -1)
		ft_printf_fd(2, "%s: %s: %s\n", "pipex", stc->av[1], strerror(errno));
	if (stc->fd_out == -1)
	{
		if (!here_doc && stc->fd_in != -1)
			close(stc->fd_in);
		ft_printf_fd(2, "%s: %s: %s\n", "pipex", stc->av[stc->ac - 1],
			strerror(errno));
		exit (1);
	}
}

static inline void	ft_ret_err(t_pipex *stc)
{
	int	error;

	error = (stc->err & 0xff00) >> 8;
	exit (error);
}

int	main(int ac, char **av, char **env)
{
	t_pipex	stc;

	stc.ac = ac;
	stc.av = av;
	stc.env = env;
	stc.err = 0;
	if (ac != 5)
	{
		ft_printf_fd(2, "Usage: file1 cmnd1 cmnd2 file2\n");
		exit (1);
	}
	ft_open_in_out(&stc, 0);
	ft_first_child(&stc, 2);
	ft_ret_err(&stc);
}
