/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopoka <lopoka@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 14:34:58 by lopoka            #+#    #+#             */
/*   Updated: 2024/05/20 15:24:32 by lopoka           ###   ########.fr       */
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
	int		fd[2];
	pid_t	pid1;
	pid_t	pid2;
	int		fd_in;
	int		fd_out;
	int		ret1;
	int		ret2;

	fd_in = open(av[1], O_RDONLY);
	fd_out = open(av[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (fd_in == -1)
		ft_printf_fd(2, "%s: %s: %s\n", "pipex", av[1], strerror(errno));
	if (fd_out == -1)
	{
		if (fd_in != -1)
			close(fd_in);
		ft_printf_fd(2, "%s: %s: %s\n", "pipex", av[4], strerror(errno));
		return (1);
	}
	if (ac != 5)
		return (1);
	if (pipe(fd) == -1)
	{
		ft_printf_fd(2, "Pipe failed");
		return (1);
	}
	pid1 = fork();
	if (pid1 == -1)
	{
		ft_printf_fd(2, "1st fork failed");
		return (1);
	}
	if (pid1 == 0)
	{
		if (fd_in == -1)
		{
			close(fd[0]);
			close(fd[1]);
			close(fd_in);
			close(fd_out);
			return (0);
		}
		else
		{
			dup2(fd_in, 0);
			dup2(fd[1], 1);
			close(fd[0]);
			close(fd[1]);
			close(fd_in);
			close(fd_out);
			ft_exe(av[2], env, 0);
		}
	}
	pid2 = fork();
	if (pid2 == -1)
	{
		ft_printf_fd(2, "2nd fork failed");
		exit (1);
	}
	if (pid2 == 0)
	{
		dup2(fd[0], 0);
		dup2(fd_out, 1);
		close(fd[0]);
		close(fd[1]);
		close(fd_in);
		close(fd_out);
		ft_exe(av[3], env, 1);
	}
	close(fd[0]);
	close(fd[1]);
	waitpid(pid1, &ret1, 0);
	waitpid(pid2, &ret2, 0);
	close(fd_in);
	close(fd_out);
	if (ret2)
		return (((ret2) & 0xff00) >> 8);
	if (ret1)
		return (((ret1) & 0xff00) >> 8);
	return (0);
}
