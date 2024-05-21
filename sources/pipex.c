/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopoka <lopoka@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 14:34:58 by lopoka            #+#    #+#             */
/*   Updated: 2024/05/21 16:55:25 by lopoka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/pipex.h"

/*
static inline char	*get_shell(char **env)
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
*/

static inline void	ft_open_in_out(t_pipex *stc, char **av)
{
	stc->fd_in = open(av[1], O_RDONLY);
	stc->fd_out = open(av[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (stc->fd_in == -1)
		ft_printf_fd(2, "%s: %s: %s\n", "pipex", av[1], strerror(errno));
	if (stc->fd_out == -1)
	{
		if (stc->fd_in != -1)
			close(stc->fd_in);
		ft_printf_fd(2, "%s: %s: %s\n", "pipex", av[4], strerror(errno));
		exit (1);
	}
}

void	ft_close_in_out_pipe(t_pipex *stc)
{
	close(stc->fd[0]);
	close(stc->fd[1]);
	close(stc->fd_in);
	close(stc->fd_out);
}

/*
static inline void	ft_wait_and_exit(t_pipex *stc)
{
	ft_close_in_out_pipe(stc);
	waitpid(stc->pid1, &(stc->ret1), 0);
	waitpid(stc->pid2, &(stc->ret2), 0);
	if (stc->ret2)
		exit ((stc->ret2 & 0xff00) >> 8);
	if (stc->ret1)
		exit ((stc->ret1 & 0xff00) >> 8);
	exit (0);
}
*/

int	main(int ac, char **av, char **env)
{
	t_pipex	stc;
	int		i;

	if (ac != 5)
		exit (1);
	ft_open_in_out(&stc, av);
	i = ac - 3;
	stc.errarr = (int *) malloc(i * sizeof(int));
	if (!stc.errarr)
		return (1);
	ft_first_child(&stc, av, env, stc.fd_in, ac, 2);
	i--;
	while (i >= 0)
	{
		if (stc.errarr[i])
		{
			i = (stc.errarr[i] & 0xff00) >> 8;
			free(stc.errarr);
			exit (i);
		}
		i--;
	}
	free(stc.errarr);
	return (0);
}
