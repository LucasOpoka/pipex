/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopoka <lopoka@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 14:46:31 by lopoka            #+#    #+#             */
/*   Updated: 2024/04/17 14:56:34 by lopoka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_tolower(int c)
{
	if ('A' <= c && c <= 'Z')
		return (c + 32);
	else
		return (c);
}
/*
#include <stdio.h>
int main(void)
{
	char s[] = "MONIKAAZ 324 fewf.;[;. cewwwr5425";
	for (int i=0; s[i]; i++) printf("%c", ft_tolower(s[i]));
	return 0;
}
*/
