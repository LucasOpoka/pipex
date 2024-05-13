/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopoka <lopoka@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 12:38:17 by lopoka            #+#    #+#             */
/*   Updated: 2024/04/18 14:48:23 by lopoka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t size)
{
	char	*c_dest;
	char	*c_src;

	if (size == 0 || dest == src)
		return (dest);
	c_dest = (char *) dest;
	c_src = (char *) src;
	if ((c_src < c_dest) && (c_src + size > c_dest))
	{
		c_src += size;
		c_dest += size;
		while (size-- > 0)
		{
			*--c_dest = *--c_src;
		}
	}
	else
	{
		while (size-- > 0)
		{
			*c_dest++ = *c_src++;
		}
	}
	return (dest);
}
/*
#include <stdio.h>
int main(void)
{
	char s1[] = "Momina";
	char s3[] = "Momina";
	char *s2 = (char*) calloc(7, sizeof(char));
	printf("%s\n", ft_memmove(s1+1, s1, 3)-1);
	printf("%s\n", ft_memcpy(s3+1, s3, 3));
	return 0;
}
*/
