/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_child_processes.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopoka <lopoka@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 17:28:10 by lopoka            #+#    #+#             */
/*   Updated: 2024/05/20 17:29:12 by lopoka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/pipex.h"

void	ft_first_child(t_pipex *stc, char **av, char **env)
{
	stc->pid1 = fork();
	if (stc->pid1 == -1)
	{
		ft_printf_fd(2, "1st fork failed");
		exit (1);
	}
	if (stc->pid1 == 0)
	{
		if (stc->fd_in == -1)
		{
			ft_close_in_out_pipe(stc);
			exit (0);
		}
		else
		{
			dup2(stc->fd_in, 0);
			dup2(stc->fd[1], 1);
			ft_close_in_out_pipe(stc);
			ft_exe(av[2], env, 0);
		}
	}
}

void	ft_last_child(t_pipex *stc, char **av, char **env)
{
	stc->pid2 = fork();
	if (stc->pid2 == -1)
	{
		ft_printf_fd(2, "2nd fork failed");
		exit (1);
	}
	if (stc->pid2 == 0)
	{
		dup2(stc->fd[0], 0);
		dup2(stc->fd_out, 1);
		ft_close_in_out_pipe(stc);
		ft_exe(av[3], env, 1);
	}
}
