/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_last_child.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopoka <lopoka@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 17:28:10 by lopoka            #+#    #+#             */
/*   Updated: 2024/05/23 15:17:46 by lopoka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/pipex.h"

void	ft_last_child(t_pipex *stc, int *prev_fd)
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
		ft_dup_close(prev_fd[0], 0, stc->fd_out, 1);
		ft_exe(stc->av[stc->ac - 2], stc->env);
	}
	else
	{
		close(prev_fd[0]);
		close(stc->fd_out);
		waitpid(pid, &(stc->err), 0);
	}
}
