/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopoka <lopoka@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 10:34:15 by lopoka            #+#    #+#             */
/*   Updated: 2024/04/18 10:51:55 by lopoka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memchr(const void *mem, int c, size_t size)
{
	const char	*c_mem;
	char		cc;
	size_t		n;

	cc = (char) c;
	n = 0;
	c_mem = (const char *) mem;
	while (n < size)
	{
		if (c_mem[n] == cc)
			return ((void *)&c_mem[n]);
		n++;
	}
	return (0);
}
/*
#include <stdio.h>
int main(void)
{
	char s[] = "Monika i Konstanty na plazy";
	printf("%s\n", ft_memchr(s, 'a', 10));
	return 0;
}
*/
