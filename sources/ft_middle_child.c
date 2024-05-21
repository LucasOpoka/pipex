/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_middle_child.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopoka <lopoka@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 22:03:43 by lopoka            #+#    #+#             */
/*   Updated: 2024/05/21 22:04:25 by lopoka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/pipex.h"

void	ft_middle_pipe_fork(t_pipex *stc, pid_t *pid, int *fd, int *prev_fd)
{
	if (pipe(fd) == -1)
	{
		close(prev_fd[0]);
		close(stc->fd_out);
		ft_printf_fd(2, "Pipe failed");
		exit (1);
	}
	*pid = fork();
	if (*pid == -1)
	{
		close(prev_fd[0]);
		close(stc->fd_out);
		ft_printf_fd(2, "Fork failed");
		exit (1);
	}
}

void	ft_middle_child(t_pipex *stc, int *prev_fd, int i)
{
	int		fd[2];
	pid_t	pid;

	ft_middle_pipe_fork(stc, &pid, fd, prev_fd);
	if (pid == 0)
	{
		ft_free_close(stc, fd);
		ft_dup_close(fd[1], 1, prev_fd[0], 0);
		ft_exe(stc->av[i], stc->env, 0);
	}
	else
	{
		close(prev_fd[0]);
		close(fd[1]);
		ft_redirect_and_wait(stc, pid, i, fd);
	}
}
