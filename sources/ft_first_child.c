/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_first_child.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopoka <lopoka@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 22:01:14 by lopoka            #+#    #+#             */
/*   Updated: 2024/05/27 14:44:30 by lopoka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/pipex.h"

static inline void	ft_open_in(t_pipex *stc, int *fd)
{
	stc->fd_in = open(stc->av[1], O_RDONLY);
	if (stc->fd_in == -1)
	{
		ft_printf_fd(2, "%s: %s: %s\n", "pipex", stc->av[1], strerror(errno));
		close (fd[1]);
		exit (1);
	}
}

void	ft_first_pipe_fork(pid_t *pid, int *fd)
{
	if (pipe(fd) == -1)
	{
		ft_printf_fd(2, "Pipe failed");
		exit (1);
	}
	*pid = fork();
	if (*pid == -1)
	{
		close(fd[0]);
		close(fd[1]);
		ft_printf_fd(2, "Fork failed");
		exit (1);
	}
}

void	ft_first_child(t_pipex *stc, int i)
{
	pid_t	pid;
	int		fd[2];

	ft_first_pipe_fork(&pid, fd);
	if (pid == 0)
	{
		close (fd[0]);
		ft_open_in(stc, fd);
		ft_dup_close(stc->fd_in, 0, fd[1], 1);
		ft_exe(stc->av[2], stc->env);
	}
	else
	{
		close(fd[1]);
		ft_redirect_and_wait(stc, pid, i, fd);
	}
}
