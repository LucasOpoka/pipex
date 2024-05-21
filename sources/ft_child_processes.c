/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_child_processes.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopoka <lopoka@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 17:28:10 by lopoka            #+#    #+#             */
/*   Updated: 2024/05/21 17:16:39 by lopoka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/pipex.h"

void	ft_first_child(t_pipex *stc, int fd_in, int i)
{
	pid_t	pid;
	int		fd[2];

	if (pipe(fd) == -1)
	{
		ft_printf_fd(2, "Pipe failed");
		exit (1);
	}
	pid = fork();
	if (pid == -1)
	{
		//
		close(fd[0]);
		close(fd[1]);
		close(stc->fd_out);
		ft_printf_fd(2, "Fork failed");
		exit (1);
	}
	if (pid == 0)
	{
		free(stc->errarr);
		close(stc->fd_out);
		if (fd_in == -1)
		{
			close(fd[0]);
			close(fd[1]);
			exit (0);
		}
		else
		{
			close(fd[0]);
			dup2(stc->fd_in, 0);
			close(stc->fd_in);
			dup2(fd[1], 1);
			close(fd[1]);
			ft_exe(stc->av[2], stc->env, 0);
		}
	}
	else
	{
		close(fd[1]);
		close(stc->fd_in);
		if (i + 1 < stc->ac - 2)
			ft_middle_child(stc, fd, i + 1);
		if (i + 1 == stc->ac - 2)
			ft_last_child(stc, fd, i + 1);
		close (fd[0]);
		waitpid(pid, &(stc->errarr[i - 2]), 0);
	}
}

void	ft_last_child(t_pipex *stc, int *prev_fd, int i)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
	{
		close(stc->fd_out);
		ft_printf_fd(2, "Fork failed");
		exit (1);
	}
	if (pid == 0)
	{
		free(stc->errarr);
		dup2(prev_fd[0], 0);
		close(prev_fd[0]);
		dup2(stc->fd_out, 1);
		close(stc->fd_out);
		ft_exe(stc->av[stc->ac - 2], stc->env, 1);
	}
	else
	{
		close(prev_fd[0]);
		close(stc->fd_out);
		waitpid(pid, &(stc->errarr[i - 2]), 0);
	}
}

void	ft_middle_child(t_pipex *stc, int *prev_fd, int i)
{
	int		fd[2];
	pid_t	pid;
	
	if (pipe(fd) == -1)
	{
		close(prev_fd[0]);
		close(stc->fd_out);
		ft_printf_fd(2, "Pipe failed");
		exit (1);
	}
	pid = fork();
	if (pid == -1)
	{
		close(prev_fd[0]);
		close(stc->fd_out);
		ft_printf_fd(2, "Fork failed");
		exit (1);
	}
	if (pid == 0)
	{
		free(stc->errarr);
		close(stc->fd_out);
		close (fd[0]);
		dup2(fd[1], 1);
		close(fd[1]);
		dup2(prev_fd[0], 0);
		close(prev_fd[0]);
		ft_exe(stc->av[i], stc->env, 0);
	}
	else
	{
		close(prev_fd[0]);
		close(fd[1]);
		if (i + 1 < stc->ac - 2)
			ft_middle_child(stc, fd, i + 1);
		if (i + 1 == stc->ac - 2)
			ft_last_child(stc, fd, i + 1);
		close (fd[0]);
		waitpid(pid, &(stc->errarr[i - 2]), 0);
	}
}

