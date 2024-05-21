/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_last_child.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopoka <lopoka@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 17:28:10 by lopoka            #+#    #+#             */
/*   Updated: 2024/05/21 22:19:53 by lopoka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/pipex.h"

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
		ft_dup_close(prev_fd[0], 0, stc->fd_out, 1);
		ft_exe(stc->av[stc->ac - 2], stc->env, 1);
	}
	else
	{
		close(prev_fd[0]);
		close(stc->fd_out);
		waitpid(pid, &(stc->errarr[i - 2]), 0);
	}
}
