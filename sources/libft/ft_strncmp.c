/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strncmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopoka <lopoka@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 09:41:09 by lopoka            #+#    #+#             */
/*   Updated: 2024/04/18 15:07:38 by lopoka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	uc1;
	unsigned char	uc2;

	i = 0;
	while (i < n)
	{
		uc1 = (unsigned char)s1[i];
		uc2 = (unsigned char) s2[i];
		if (uc1 != uc2)
			return (uc1 - uc2);
		if (!uc1)
			return (0);
		i++;
	}
	return (0);
}
/*
#include <stdio.h>
#include <string.h>
int main(void)
{
	char str1[] = "abceeee";
	char str2[] = "abceeee";
	unsigned int i = 6;

	printf("my %d og %d", ft_strncmp(str1, str2, i), strncmp(str1, str2, i));
	return 0;
}
*/
