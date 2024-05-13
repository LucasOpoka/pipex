/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopoka <lopoka@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 09:34:08 by lopoka            #+#    #+#             */
/*   Updated: 2024/04/17 09:34:16 by lopoka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isdigit(int c)
{
	if (!('0' <= c && c <= '9'))
	{
		return (0);
	}
	return (1);
}
/*
#include <stdio.h>
int main(void)
{
	printf("%c %d\n", '0', ft_isdigit('0'));
	printf("%c %d\n", 'b', ft_isdigit('b'));
	printf("%c %d\n", '5', ft_isdigit('5'));
	printf("%c %d\n", '4', ft_isdigit('4'));
	printf("%c %d\n", ' ', ft_isdigit(' '));
	return 0;
}
*/
