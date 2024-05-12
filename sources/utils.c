/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopoka <lopoka@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 20:28:56 by lopoka            #+#    #+#             */
/*   Updated: 2024/05/11 13:27:36 by lopoka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "libft.h"

void	free_char_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

char	*find_pth(char *cmnd, char **env)
{
	int		i;
	char	**arr;
	char	*part;
	char	*final;

	i = 0;
	while (env[i] && ft_strnstr(env[i], "PATH", 4) == 0)
		i++;
	arr = ft_split(env[i] + 5, ':');
	if (!arr)
		return (0);
	i = 0;
	while (arr[i])
	{
		part = ft_strjoin(arr[i], "/");
		if (!part)
			return (0);
		final = ft_strjoin(part, cmnd);
		free(part);
		if (!final)
			return (0);
		if (access(final, F_OK) == 0)
		{
			free_char_arr(arr);
			return (final);
		}
		i++;
	}
	free_char_arr(arr);
	free(final);
	return (0);
}
