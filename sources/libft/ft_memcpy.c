/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopoka <lopoka@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 12:20:13 by lopoka            #+#    #+#             */
/*   Updated: 2024/04/18 15:27:53 by lopoka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t size)
{
	char	*c_dest;
	char	*c_src;
	size_t	i;

	c_dest = (char *) dest;
	c_src = (char *) src;
	if (size == 0 || dest == src)
		return (dest);
	i = 0;
	while (i < size)
	{
		c_dest[i] = c_src[i];
		i++;
	}
	return (dest);
}
/*
#include <stdio.h>
int main(void)
{
	char s1[] = "Momina";
	char *s2 = (char*) calloc(7, sizeof(char));
	printf("%s\n", ft_memcpy(s2, s1, 3));
	return 0;
	}
*/	
