/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopoka <lopoka@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 09:43:26 by lopoka            #+#    #+#             */
/*   Updated: 2024/04/17 09:43:43 by lopoka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalnum(int c)
{
	if (!((65 <= c && c <= 90)
			|| (97 <= c && c <= 122)
			|| (48 <= c && c <= 57)))
	{
		return (0);
	}
	return (1);
}
/*
#include <stdio.h>
int main(void)
{
	printf("%c %d\n", 'a', ft_isalnum('a'));
	printf("%c %d\n", 'b', ft_isalnum('b'));
	printf("%c %d\n", 'z', ft_isalnum('z'));
	printf("%c %d\n", '4', ft_isalnum('4'));
	printf("%c %d\n", ' ', ft_isalnum(' '));
	return 0;
}
*/
