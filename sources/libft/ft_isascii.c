/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopoka <lopoka@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 09:45:30 by lopoka            #+#    #+#             */
/*   Updated: 2024/04/17 09:50:22 by lopoka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isascii(int c)
{
	if (0 <= c && c <= 127)
	{
		return (1);
	}
	return (0);
}
/*
#include <stdio.h>
int main(void)
{
	printf("%c %d\n", 'a', ft_isascii('a'));
	printf("%c %d\n", 'b', ft_isascii('b'));
	printf("%d %d\n", 4, ft_isascii(4));
	printf("%d %d\n", -44, ft_isascii(-444));
	printf("%d %d\n", 1000, ft_isascii(1000));
	return 0;
}
*/
