/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_first_child.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopoka <lopoka@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 22:01:14 by lopoka            #+#    #+#             */
/*   Updated: 2024/05/21 22:20:45 by lopoka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/pipex.h"

void	ft_first_pipe_fork(t_pipex *stc, pid_t *pid, int *fd)
{
	if (pipe(fd) == -1)
	{
		close(stc->fd_in);
		close(stc->fd_out);
		ft_printf_fd(2, "Pipe failed");
		exit (1);
	}
	*pid = fork();
	if (*pid == -1)
	{
		close(fd[0]);
		close(fd[1]);
		close(stc->fd_in);
		close(stc->fd_out);
		ft_printf_fd(2, "Fork failed");
		exit (1);
	}
}

void	ft_first_child(t_pipex *stc, int i)
{
	pid_t	pid;
	int		fd[2];

	ft_first_pipe_fork(stc, &pid, fd);
	if (pid == 0)
	{
		ft_free_close(stc, fd);
		if (stc->fd_in == -1)
		{
			close(fd[1]);
			exit (0);
		}
		else
		{
			ft_dup_close(stc->fd_in, 0, fd[1], 1);
			ft_exe(stc->av[2], stc->env, 0);
		}
	}
	else
	{
		close(fd[1]);
		close(stc->fd_in);
		ft_redirect_and_wait(stc, pid, i, fd);
	}
}
