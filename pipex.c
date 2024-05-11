/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopoka <lopoka@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 14:34:58 by lopoka            #+#    #+#             */
/*   Updated: 2024/05/11 13:44:00 by lopoka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include "libft.h"

char	*find_pth(char *cmnd, char **env);
void	free_char_arr(char **arr);

void	exe(char *cmnd_str, char **env)
{
	char	**cmnd;
	char	*pth;

	cmnd = ft_split(cmnd_str, ' ');
	if (!cmnd)
		exit (1);
	pth = find_pth(cmnd[0], env);
	if (!pth)
	{
		free_char_arr(cmnd);
		perror("Command not found");
		exit (EXIT_FAILURE);
	}
	if (execve(pth, cmnd, env) == -1)
	{
		perror("Execve failed\n");
		exit(EXIT_FAILURE);
	}
}

int	main(int ac, char **av, char **env)
{
	int		fd[2];
	pid_t	pid1;
	pid_t	pid2;
	int		fd_in;
	int		fd_out;

	if (ac != 5)
		exit(0);
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
			perror("Opening 1st file failed");
			exit (EXIT_FAILURE);
		}

		dup2(fd_in, 0);
		dup2(fd[1], 1);
		close(fd[0]);
		close(fd[1]);
		exe(av[2], env);
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
			perror("Opening 2nd file failed");
			exit (EXIT_FAILURE);
		}
		dup2(fd[0], 0);
		dup2(fd_out, 1);
		close(fd[0]);
		close(fd[1]);
		exe(av[3], env);
	}


	close(fd[0]);
	close(fd[1]);

	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);

	return (0);
}
