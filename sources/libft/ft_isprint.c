/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopoka <lopoka@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 09:51:11 by lopoka            #+#    #+#             */
/*   Updated: 2024/04/17 09:57:57 by lopoka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isprint(int c)
{
	if (32 <= c && c <= 126)
	{
		return (1);
	}
	return (0);
}
/*
#include <stdio.h>
int main(void)
{
	printf("%d %d\n", -5, ft_isprint(-5));
	printf("%d %d\n", 54, ft_isprint(54));
	printf("%d %d\n", 40, ft_isprint(40));
	printf("%d %d\n", 32, ft_isprint(32));
	printf("%d %d\n", 126, ft_isprint(126));
	return 0;
}
*/
