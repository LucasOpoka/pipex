/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopoka <lopoka@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 13:16:20 by lopoka            #+#    #+#             */
/*   Updated: 2024/04/20 15:13:33 by lopoka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*mem;

	mem = (void *) malloc(count * size);
	if (!mem)
		return (mem);
	ft_bzero(mem, count * size);
	return (mem);
}
/*
#include <stdio.h>
int main(void)
{
	char	*ptr = (char *) ft_calloc(10, sizeof(char));
	for (int i = 0; i<20; i++) printf("%d", ptr[i]);
	return 0;
}
*/
