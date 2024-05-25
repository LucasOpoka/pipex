/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_child_processes_utils.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopoka <lopoka@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 22:06:08 by lopoka            #+#    #+#             */
/*   Updated: 2024/05/25 16:17:24 by lopoka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/pipex.h"

void	ft_redirect_and_wait(t_pipex *stc, pid_t pid, int i, int *fd)
{
	if (i + 1 < stc->ac - 2)
		ft_middle_child(stc, fd, i + 1);
	if (i + 1 == stc->ac - 2)
		ft_last_child(stc, fd);
	close (fd[0]);
	waitpid(pid, NULL, 0);
}

void	ft_dup_close(int a, int to_a, int b, int to_b)
{
	dup2(a, to_a);
	close(a);
	dup2(b, to_b);
	close(b);
}
