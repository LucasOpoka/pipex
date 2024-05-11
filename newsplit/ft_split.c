/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopoka <lopoka@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 14:16:39 by lopoka            #+#    #+#             */
/*   Updated: 2024/05/11 15:54:14 by lopoka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <stdio.h>

int	is_sep(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
		{
			if (c == '\"')
			{
				if (charset[0] == '0' && charset[1] == '\"' && charset[2] == 0)
				{	
					charset[0] = '\"';
					charset[1] = 0;
				}
				else
				{
					charset[0] = '0';
					charset[1] = '\"';
					charset[2] = 0;
				}
			}
			return (1);
		}
		i++;
	}
	return (0);
}

int	count_words(char *str, char *charset)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (i == 0)
		{
			if (!is_sep(str[i], charset))
				count++;
		}
		else if (is_sep(str[i - 1], charset) && !is_sep(str[i], charset))
			count++;
		i++;
	}
	return (count);
}

char	*skip_sep(char *str, char *charset)
{
	while (is_sep(*str, charset) && *str)
	{
		str++;
	}
	return (str);
}

int	wrd_len(char *str, char *charset)
{
	int	i;

	i = 0;
	while (!is_sep(str[i], charset) && str[i])
		i++;
	return (i);
}

char	**ft_split(char *str, char *charset)
{
	char	**res;
	int		i;
	int		j;
	int		cw;

	cw = count_words(str, charset);
	res = (char **) malloc((cw + 1) * sizeof(char *));
	if (!res)
		return (0);
	i = 0;
	while (i < cw)
	{
		str = skip_sep(str, charset);
		res[i] = (char *) malloc((wrd_len(str, charset) + 1) * sizeof(char));
		if (!res[i])
			return (0);
		j = 0;
		while (!is_sep(*str, charset) && *str)
		{
			res[i][j++] = *str++;
		}
		res[i++][j] = 0;
	}
	res[cw] = 0;
	return (res);
}


int main(void)
{
	char str[] = "Monika Lukasz \"this is a string\" Konstanty \"Mama Tata\" Juho Sami Leon Eetu";
	char sep[] = " \"";
	char **res = ft_split(str, sep);
	while (*res)
	{
		printf("%s\n", *res);
		res++;
	}
	return 0;
}
