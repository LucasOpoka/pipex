/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopoka <lopoka@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 10:56:34 by lopoka            #+#    #+#             */
/*   Updated: 2024/04/18 11:17:52 by lopoka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_memcmp(const void *mem1, const void *mem2, size_t size)
{
	const unsigned char	*c_mem1;
	const unsigned char	*c_mem2;

	c_mem1 = (const unsigned char *) mem1;
	c_mem2 = (const unsigned char *) mem2;
	while (size && *c_mem1 == *c_mem2)
	{
		c_mem1++;
		c_mem2++;
		size--;
	}
	if (size)
		return (*c_mem1 - *c_mem2);
	else
		return (0);
}
/*
#include <stdio.h>
int main(void)
{
	char s[] = "Monika i Konstanty w kosmosie";
	char s2[] = "Monika i Konstanty na plazy";

	printf("%d", ft_memcmp(s, s2, 19));
	return 0;
}
*/
