/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_pth.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopoka <lopoka@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 20:28:56 by lopoka            #+#    #+#             */
/*   Updated: 2024/05/22 13:35:52 by lopoka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/pipex.h"

static inline char	*ft_already_valid_pth(char **cmnd, int last)
{
	if (access(cmnd[0], F_OK) == 0)
		return (ft_strdup(cmnd[0]));
	else
	{
		ft_printf_fd(2, "%s: %s: No such file or directory\n",
			"pipex", cmnd[0]);
		ft_free_split_null(cmnd);
		if (last)
			exit (127);
		exit (0);
	}
}

static inline char	*ft_find_path_in_env(char **cmnd, char **env, int last)
{
	int	i;

	i = 0;
	while (env[i] && ft_strnstr(env[i], "PATH", 4) == 0)
		i++;
	if (!env[i])
	{
		ft_printf_fd(2, "%s: %s: No such file or directory\n",
			"pipex", cmnd[0]);
		ft_free_split_null(cmnd);
		if (last)
			exit (127);
		exit (0);
	}
	return (env[i]);
}

static inline char	*ft_join_path(char *dir, char *cmnd)
{
	char	*part;
	char	*final_cmnd;

	part = ft_strjoin(dir, "/");
	if (!part)
		return (0);
	final_cmnd = ft_strjoin(part, cmnd);
	free(part);
	if (!final_cmnd)
		return (0);
	return (final_cmnd);
}

static inline char	*ft_check_path(char **split, char **cmnd)
{
	int		i;
	char	*final_cmnd;

	i = 0;
	while (split[i])
	{
		final_cmnd = ft_join_path(split[i++], cmnd[0]);
		if (!final_cmnd)
			return (0);
		if (access(final_cmnd, F_OK) == 0)
		{
			ft_free_split_null(split);
			return (final_cmnd);
		}
		free(final_cmnd);
	}
	ft_free_split_null(split);
	return (0);
}

char	*ft_find_pth(char **cmnd, char **env, int last)
{
	char	**split;
	char	*path_in_env;

	if (cmnd[0][0] == '/' || cmnd[0][0] == '.')
		return (ft_already_valid_pth(cmnd, last));
	path_in_env = ft_find_path_in_env(cmnd, env, last);
	split = ft_split(path_in_env + 5, ':');
	if (!split)
		return (0);
	return (ft_check_path(split, cmnd));
}
