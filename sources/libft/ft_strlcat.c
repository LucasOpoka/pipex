/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopoka <lopoka@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 19:50:45 by lopoka            #+#    #+#             */
/*   Updated: 2024/04/17 14:12:32 by lopoka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	d_len;
	size_t	s_len;
	size_t	i;

	d_len = ft_strlen(dest);
	s_len = ft_strlen(src);
	if (size == 0 || size <= d_len)
		return (s_len + size);
	i = d_len;
	while (i < (size - 1) && *src)
	{
		dest[i] = *src;
		src++;
		i++;
	}
	dest[i] = 0;
	return (d_len + s_len);
}
/*
#include <stdio.h>
#include <string.h>
int main(void)
{
    char str1[20] = "Momina"; 
    char str3[20] = "Momina";
    char str2[20] = "Lukasz";
    char str4[20] = "Lukasz";
	size_t i = 8;
    
	size_t a = ft_strlcat(str1, str2, i);
	printf("my %zu %s\n", a, str1);

	size_t b = strlcat(str3, str4, i);
	printf("og %zu %s\n", b, str3);
    return 0;
}
*/
