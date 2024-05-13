/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopoka <lopoka@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 10:11:27 by lopoka            #+#    #+#             */
/*   Updated: 2024/04/17 10:47:31 by lopoka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memset(void *mem, int val, size_t size)
{
	unsigned char	*uns_chr_mem;
	unsigned char	uns_chr_val;

	uns_chr_mem = (unsigned char *) mem;
	uns_chr_val = (unsigned char) val;
	while (size > 0)
	{
		*uns_chr_mem = uns_chr_val;
		uns_chr_mem++;
		size--;
	}
	return (mem);
}
/*
#include <stdio.h>
int main(void)
{
	int *arr = (int*) malloc(10 * sizeof(int));
	for (int i=0; i<10; i++) printf("%d", arr[i]);
	printf("\n");
	ft_memset(arr,0, 10 * sizeof(int));
	for (int i=0; i<10; i++) printf("%d", arr[i]);
	printf("\n");
	return 0;
}
*/
