/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopoka <lopoka@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 14:34:58 by lopoka            #+#    #+#             */
/*   Updated: 2024/05/09 20:31:16 by lopoka           ###   ########.fr       */
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
	int		i;

	cmnd = ft_split(cmnd_str, ' ');
	if (!cmnd)
		return ;
	pth = find_pth(cmnd[0], env);
	if (!pth)
	{
		free_char_arr(cmnd);
		return ;
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
	pid_t	id;
	int		fd_in;
	int		fd_out;

	if (pipe(fd) == -1)
		return (1);
	id = fork();
	if (id == -1)
		return (2);
	if (id == 0)
	{
		fd_in = open(av[1], O_RDONLY, 0444);
		if (fd_in == -1)
			return (3);
		dup2(fd_in, 0);
		dup2(fd[1], 1);
		exe(av[2], env);
	}
	if (id != 0)
	{
		waitpid(id, NULL, 0);
		fd_out = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0666);
		if (fd_out == -1)
			return (4);
		dup2(fd[0], 0);
		dup2(fd_out, 1);
		close(fd[1]);
		exe(av[3], env);
	}
	return (0);
}
