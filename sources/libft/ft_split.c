/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopoka <lopoka@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 16:14:23 by lopoka            #+#    #+#             */
/*   Updated: 2024/05/19 10:58:09 by lopoka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	is_sep(char curr, char c)
{
	if (curr == c)
		return (1);
	return (0);
}

static int	count_words(char const *str, char c)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (i == 0)
		{
			if (!is_sep(str[i], c))
				count++;
		}
		else if (is_sep(str[i - 1], c) && !is_sep(str[i], c))
			count++;
		i++;
	}
	return (count);
}

static char const	*skip_sep(char const *str, char c)
{
	while (is_sep(*str, c) && *str)
	{
		str++;
	}
	return (str);
}

static int	wrd_len(char const *str, char c)
{
	int	i;

	i = 0;
	while (!is_sep(str[i], c) && str[i])
		i++;
	return (i);
}

char	**ft_split(char const *str, char c)
{
	t_split	x;

	x.cw = count_words(str, c);
	x.res = (char **) malloc((x.cw + 1) * sizeof(char *));
	if (!x.res)
		return (0);
	x.i = 0;
	while (x.i < x.cw)
	{
		str = skip_sep(str, c);
		x.res[x.i] = (char *) malloc((wrd_len(str, c) + 1) * sizeof(char));
		x.j = 0;
		if (!x.res[x.i])
		{
			while (x.j < x.i)
				free(x.res[x.j++]);
			free(x.res);
			return (0);
		}
		while (!is_sep(*str, c) && *str)
			x.res[x.i][x.j++] = *str++;
		x.res[x.i++][x.j] = 0;
	}
	x.res[x.i] = 0;
	return (x.res);
}
/*
#include <stdio.h>
int main(void)
{
	char str[] = "Monika.Lukasz.Konstanty/Mama,Tata,Juho,Sami,Leon,Eetu";
	char sep = '.';
	char **res = ft_split(str, sep);
	while (*res)
	{
		printf("%s\n", *res);
		res++;
	}
	return 0;
}
*/
