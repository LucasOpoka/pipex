/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopoka <lopoka@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 09:17:15 by lopoka            #+#    #+#             */
/*   Updated: 2024/04/17 09:25:28 by lopoka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(int c)
{
	if (!((65 <= c && c <= 90)
			|| (97 <= c && c <= 122)))
	{
		return (0);
	}
	return (1);
}
/*
#include <stdio.h>
int main(void)
{
	printf("%c %d\n", 'a', ft_isalpha('a'));
	printf("%c %d\n", 'b', ft_isalpha('b'));
	printf("%c %d\n", 'z', ft_isalpha('z'));
	printf("%c %d\n", '4', ft_isalpha('4'));
	printf("%c %d\n", ' ', ft_isalpha(' '));
	return 0;
}
*/
