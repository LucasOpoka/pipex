/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_last_child.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopoka <lopoka@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 17:28:10 by lopoka            #+#    #+#             */
/*   Updated: 2024/05/25 19:16:09 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/pipex.h"

static inline void	ft_open_out(t_pipex *stc, int *prev_fd)
{
	stc->fd_out = open(stc->av[stc->ac - 1], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (stc->fd_out == -1)
	{
		ft_printf_fd(2, "%s: %s: %s\n", "pipex", stc->av[stc->ac - 1],
			strerror(errno));
		close(prev_fd[0]);
		exit (1);
	}
}

void	ft_last_child(t_pipex *stc, int *prev_fd)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
	{
		close(prev_fd[0]);
		ft_printf_fd(2, "Fork failed");
		exit (1);
	}
	if (pid == 0)
	{
		ft_open_out(stc, prev_fd);
		ft_dup_close(prev_fd[0], 0, stc->fd_out, 1);
		ft_exe(stc->av[stc->ac - 2], stc->env);
	}
	else
		waitpid(pid, &(stc->err), 0);
}
