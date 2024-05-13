/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopoka <lopoka@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 14:15:54 by lopoka            #+#    #+#             */
/*   Updated: 2024/04/19 16:11:38 by lopoka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	is_in_set(char const *set, char c)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*res;
	size_t	i;
	size_t	j;
	size_t	k;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	j = ft_strlen(s1);
	while (s1[i] && is_in_set(set, s1[i]))
		i++;
	while (j > i && is_in_set(set, s1[j - 1]))
		j--;
	res = (char *) malloc((j - i + 1) * sizeof(char));
	if (!res)
		return (NULL);
	k = 0;
	while (k + i < j)
	{
		res[k] = s1[k + i];
		k++;
	}
	res[k] = 0;
	return (res);
}
/*
#include "stdio.h"
int main(void)
{
	char s1[] = "MobananaoM";
	char s2[] = "Mo";
	printf("%s\n", ft_strtrim(s1, s2));
	return 0;
}
*/
