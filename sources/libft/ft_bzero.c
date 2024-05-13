/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopoka <lopoka@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 10:50:14 by lopoka            #+#    #+#             */
/*   Updated: 2024/04/17 10:58:26 by lopoka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_bzero(void *mem, size_t size)
{
	ft_memset(mem, 0, size);
}
/*
#include <stdio.h>
int main(void)
{
	int *arr = (int*) malloc(10 * sizeof(int));
	for (int i=0; i<10; i++) printf("%d", arr[i]);
	printf("\n");
	ft_bzero(arr, 10 * sizeof(int));
	for (int i=0; i<10; i++) printf("%d", arr[i]);
	printf("\n");
	return 0;
}
*/
