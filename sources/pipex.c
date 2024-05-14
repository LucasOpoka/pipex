/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopoka <lopoka@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 14:34:58 by lopoka            #+#    #+#             */
/*   Updated: 2024/05/14 16:59:22 by lopoka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <libft.h>
#include <stdio.h>


char	*find_pth(char *cmnd, char **env);
void	free_char_arr(char **arr);

int	exe(char *cmnd_str, char **env, int last)
{
	char	**cmnd;
	char	*pth;

	cmnd = ft_split_sub(cmnd_str, ' ');
	if (!cmnd)
		exit (1);
	if (!cmnd[0] || !cmnd_str[0])
	{
		free_char_arr(cmnd);
		if (cmnd_str[0] == ' ')
			ft_printf_fd(2, "%s: command not found: %s\n", "pipex", cmnd_str);
		else
			ft_printf_fd(2, "%s: permission denied:\n", "pipex");
		exit (7);
	}
	pth = find_pth(cmnd[0], env);
	//issues here
	if (!pth || !cmnd_str[0] || env == NULL)
	{
		if (!last)
		{
			ft_printf_fd(2, "%s: %s: command not found\n", "pipex", cmnd[0]);
			free_char_arr(cmnd);
			exit(0);
		}
		else
		{
			ft_printf_fd(2, "%s: %s: command not found\n", "pipex", cmnd[0]);
			free_char_arr(cmnd);
			exit (126);
		}
	}
	if (execve(pth, cmnd, env) == -1)
	{
		ft_printf_fd(2, "%s: %s\n", "pipex", strerror(errno));
		if (last)
			exit (126);
		exit (0);
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
	//char	*shell;

	//shell = get_shell(env);

	fd_in = open(av[1], O_RDONLY);
	fd_out = open(av[4], O_WRONLY | O_CREAT | O_TRUNC , 0644);
	if (fd_in == -1)
	{
		ft_printf_fd(2, "%s: %s: %s\n", "pipex", av[1], strerror(errno));
		//return (1);
	}
	if (fd_out == -1)	
	{
		close(fd_in);
		ft_printf_fd(2, "%s: %s: %s\n", "pipex", av[4], strerror(errno));
		return (1);
	}

	if (ac != 5)
		return (1);
	if (pipe(fd) == -1)
	{
		perror("Pipe failed");
		return (1);
	}

	pid1 = fork();
	if (pid1 == -1)
	{
		perror("1st fork failed");
		return (1);
	}
	if (pid1 == 0)
	{
		if (fd_in == -1)
		{
			close(fd[0]);
			//write(fd[1], "\0", 1);
			close(fd[1]);
			return (0);
		}
		else
		{
			dup2(fd_in, 0);
			dup2(fd[1], 1);
			close(fd[0]);
			close(fd[1]);
			err = exe(av[2], env, 0);
		}
	}


	pid2 = fork();
	if (pid2 == -1)
	{
		perror("2nd fork failed");
		exit (1);
	}
	if (pid2 == 0)
	{
		dup2(fd[0], 0);
		dup2(fd_out, 1);
		close(fd[0]);
		close(fd[1]);
		err = exe(av[3], env, 1);
	}


	close(fd[0]);
	close(fd[1]);


	int ret1, ret2;

	waitpid(pid1, &ret1, 0);
	waitpid(pid2, &ret2, 0);

	if (ret2)
		return (((ret2) & 0xff00) >> 8);
	if (ret1)
		return (((ret1) & 0xff00) >> 8);	
	return (0);
}
