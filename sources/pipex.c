/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopoka <lopoka@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 14:34:58 by lopoka            #+#    #+#             */
/*   Updated: 2024/05/20 16:03:47 by lopoka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/pipex.h"

char	*get_shell(char **env)
{
	int		i;
	char	**arr;
	char	*res;

	i = 0;
	while (env[i] && !ft_strstr(env[i], "SHELL"))
		i++;
	arr = ft_split(env[i], '/');
	if (!arr)
		return (NULL);
	i = 0;
	while (arr[i])
		i++;
	res = arr[i - 1];
	while (i - 2 >= 0)
		free(arr[i-- - 2]);
	free(arr);
	return (res);
}

int	main(int ac, char **av, char **env)
{
	t_pipex	stc;
	/*
	int		fd[2];
	pid_t	pid1;
	pid_t	pid2;
	int		fd_in;
	int		fd_out;
	int		ret1;
	int		ret2;
	*/

	if (ac != 5)
		return (1);
	stc.fd_in = open(av[1], O_RDONLY);
	stc.fd_out = open(av[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (stc.fd_in == -1)
		ft_printf_fd(2, "%s: %s: %s\n", "pipex", av[1], strerror(errno));
	if (stc.fd_out == -1)
	{
		if (stc.fd_in != -1)
			close(stc.fd_in);
		ft_printf_fd(2, "%s: %s: %s\n", "pipex", av[4], strerror(errno));
		return (1);
	}
	if (pipe(stc.fd) == -1)
	{
		ft_printf_fd(2, "Pipe failed");
		return (1);
	}
	stc.pid1 = fork();
	if (stc.pid1 == -1)
	{
		ft_printf_fd(2, "1st fork failed");
		return (1);
	}
	if (stc.pid1 == 0)
	{
		if (stc.fd_in == -1)
		{
			close(stc.fd[0]);
			close(stc.fd[1]);
			close(stc.fd_in);
			close(stc.fd_out);
			return (0);
		}
		else
		{
			dup2(stc.fd_in, 0);
			dup2(stc.fd[1], 1);
			close(stc.fd[0]);
			close(stc.fd[1]);
			close(stc.fd_in);
			close(stc.fd_out);
			ft_exe(av[2], env, 0);
		}
	}
	stc.pid2 = fork();
	if (stc.pid2 == -1)
	{
		ft_printf_fd(2, "2nd fork failed");
		exit (1);
	}
	if (stc.pid2 == 0)
	{
		dup2(stc.fd[0], 0);
		dup2(stc.fd_out, 1);
		close(stc.fd[0]);
		close(stc.fd[1]);
		close(stc.fd_in);
		close(stc.fd_out);
		ft_exe(av[3], env, 1);
	}
	close(stc.fd[0]);
	close(stc.fd[1]);
	waitpid(stc.pid1, &stc.ret1, 0);
	waitpid(stc.pid2, &stc.ret2, 0);
	close(stc.fd_in);
	close(stc.fd_out);
	if (stc.ret2)
		return (((stc.ret2) & 0xff00) >> 8);
	if (stc.ret1)
		return (((stc.ret1) & 0xff00) >> 8);
	return (0);
}
