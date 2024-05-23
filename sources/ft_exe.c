/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exe.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopoka <lopoka@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 15:17:31 by lopoka            #+#    #+#             */
/*   Updated: 2024/05/23 19:58:27 by lopoka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/pipex.h"

static inline void	ft_empty_cmnd(char **cmnd, char *cmnd_str)
{
	ft_free_split_null(cmnd);
	if (cmnd_str[0] == ' ' || !cmnd_str[0])
		ft_printf_fd(2, "%s: %s: command not found\n", "pipex", cmnd_str);
	else
		ft_printf_fd(2, "%s: permission denied:\n", "pipex");
	exit (127);
}

static inline void	ft_no_pth(char **cmnd)
{
	ft_printf_fd(2, "%s: %s: command not found\n", "pipex", cmnd[0]);
	ft_free_split_null(cmnd);
	exit (127);
}

static inline void	ft_execve_failed(char **cmnd, char *pth)
{
	if (!access(cmnd[0], F_OK))
		ft_printf_fd(2, "%s: %s: is a directory\n", "pipex", cmnd[0]);
	else
		ft_printf_fd(2, "%s: %s: %s\n", "pipex", pth, strerror(errno));
	ft_free_split_null(cmnd);
	if (pth)
		free(pth);
	exit (126);
}

void	ft_exe(char *cmnd_str, char **env)
{
	char	**cmnd;
	char	*pth;

	cmnd = ft_split_sub(cmnd_str, ' ', 1);
	if (!cmnd)
		exit (1);
	if (!cmnd[0] || !cmnd_str[0])
		ft_empty_cmnd(cmnd, cmnd_str);
	pth = ft_find_pth(cmnd, env);
	if (!pth)
		ft_no_pth(cmnd);
	execve(pth, cmnd, env);
	ft_execve_failed(cmnd, pth);
}
