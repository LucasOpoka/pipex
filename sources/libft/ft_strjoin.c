/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopoka <lopoka@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 12:42:47 by lopoka            #+#    #+#             */
/*   Updated: 2024/04/19 14:14:17 by lopoka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	while (src[i] && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	return (dest + i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	char	*temp;
	size_t	len1;
	size_t	len2;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	res = (char *) malloc((len1 + len2 + 1) * sizeof(char));
	if (!res)
		return (NULL);
	temp = res;
	res = ft_strncpy(res, s1, len1);
	res = ft_strncpy(res, s2, len2);
	*res = '\0';
	return (temp);
}
/*
#include <stdio.h>
int main(void)
{
	char s1[] = "Monikaaaaaaaaa";
	char s2[] = "Lukaszzzzzzz";
	
	printf("%s\n", ft_strjoin(s1, s2));
	return 0;
}
*/
