/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopoka <lopoka@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 14:34:58 by lopoka            #+#    #+#             */
/*   Updated: 2024/05/22 19:06:30 by lopoka           ###   ########.fr       */
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

static inline void	ft_open_in_out(t_pipex *stc, int here_doc)
{
	if (!here_doc)
		stc->fd_in = open(stc->av[1], O_RDONLY);
	stc->fd_out = open(stc->av[stc->ac - 1], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (!here_doc && stc->fd_in == -1)
		ft_printf_fd(2, "%s: %s: %s\n", "pipex", stc->av[1], strerror(errno));
	if (stc->fd_out == -1)
	{
		if (!here_doc && stc->fd_in != -1)
			close(stc->fd_in);
		ft_printf_fd(2, "%s: %s: %s\n", "pipex", stc->av[stc->ac - 1],
			strerror(errno));
		exit (1);
	}
}

static inline void	ft_ret_err(t_pipex *stc, int i)
{
	while (i >= 0)
	{
		if (stc->errarr[i])
		{
			i = (stc->errarr[i] & 0xff00) >> 8;
			free(stc->errarr);
			exit (i);
		}
		i--;
	}
	free(stc->errarr);
	exit (0);
}

int	main(int ac, char **av, char **env)
{
	t_pipex	stc;
	int		i;

	stc.ac = ac;
	stc.av = av;
	stc.env = env;
	if (ac < 5)
		exit (1);
	i = ac - 3;
	stc.errarr = (int *) malloc(i * sizeof(int));
	if (!stc.errarr)
		return (1);
	if (!ft_strncmp(av[1], "here_doc", 8))
	{
		ft_open_in_out(&stc, 1);
		//Check if 2 or 3
		ft_here_doc(&stc, 2);
	}
	else
	{
		ft_open_in_out(&stc, 0);
		ft_first_child(&stc, 2);
	}
	ft_ret_err(&stc, i - 1);
}
