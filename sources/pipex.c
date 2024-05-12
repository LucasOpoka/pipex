/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopoka <lopoka@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 14:34:58 by lopoka            #+#    #+#             */
/*   Updated: 2024/05/12 18:36:53 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include "libft.h"


char	**split2(const char *s, char sep);

char	*find_pth(char *cmnd, char **env);
void	free_char_arr(char **arr);

int	exe(char *cmnd_str, char **env)
{
	char	**cmnd;
	char	*pth;

	cmnd = split2(cmnd_str, ' ');
	if (!cmnd)
		return (1);
	pth = find_pth(cmnd[0], env);
	if (!pth)
	{
		free_char_arr(cmnd);
		perror("Command not found");
		return (127);
	}
	if (execve(pth, cmnd, env) == -1)
	{
		perror("Execve failed\n");
		return (1);
	}
	return (0);
}

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
	int		err;

	printf("%s\n", get_shell(env));

	if (ac != 5)
		exit(1);
	if (pipe(fd) == -1)
	{
		perror("Pipe failed");
		exit (EXIT_FAILURE);
	}

	pid1 = fork();
	if (pid1 == -1)
	{
		perror("1st fork failed");
		exit (EXIT_FAILURE);
	}
	if (pid1 == 0)
	{
		fd_in = open(av[1], O_RDONLY);
		if (fd_in == -1)
		{
			//perror("Opening 1st file failed");
			return (3);
		}

		dup2(fd_in, 0);
		dup2(fd[1], 1);
		close(fd[0]);
		close(fd[1]);
		err = exe(av[2], env);
		if (err)
			return (err);
	}


	pid2 = fork();
	if (pid2 == -1)
	{
		perror("2nd fork failed");
		exit (EXIT_FAILURE);
	}
	if (pid2 == 0)
	{
		fd_out = open(av[4], O_WRONLY | O_CREAT | O_TRUNC , 0644);
		if (fd_out == -1)	
		{
			//perror("Opening 2nd file failed");
			return (3);
		}
		dup2(fd[0], 0);
		dup2(fd_out, 1);
		close(fd[0]);
		close(fd[1]);
		err = exe(av[3], env);
		if (err)
			return (err);
	}


	close(fd[0]);
	close(fd[1]);


	int ret1, ret2;

	waitpid(pid1, &ret1, 0);
	waitpid(pid2, &ret2, 0);

	if (ret1)
		return (((ret1) & 0xff00) >> 8);
	if (ret2)
		return (((ret2) & 0xff00) >> 8);	
	return (0);
}
