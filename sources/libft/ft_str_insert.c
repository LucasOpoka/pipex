/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_insert.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopoka <lopoka@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 11:09:24 by lopoka            #+#    #+#             */
/*   Updated: 2024/05/15 15:10:26 by lopoka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_str_insert(char *str1, char *str2, size_t ix, size_t skip)
{
	char	*res;
	size_t	len1;
	size_t	len2;

	len1 = ft_strlen(str1);
	if (ix > len1)
		return (ft_strjoin(str1, str2));
	len2 = ft_strlen(str2);
	res = (char *) malloc(len1 + len2 - skip + 1);
	if (!res)
		return (NULL);
	ft_strncpy(res, str1, ix);
	res[ix] = 0;
	ft_strcat(res, str2);
	ft_strcat(res, str1 + ix + skip);
	return (res);
}
/*
#include <stdio.h>
int main(void)
{
	char *strA = "Mon<3 Lukasz", *strB = "ika ", *res; 

	res = ft_str_insert(strA, strB, 100);
	printf("%s\n", res);
	return (0);
}
*/
