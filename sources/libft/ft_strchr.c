/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopoka <lopoka@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 09:15:01 by lopoka            #+#    #+#             */
/*   Updated: 2024/04/18 14:53:28 by lopoka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	cc;

	cc = (char) c;
	while (1)
	{
		if (*s == cc)
			return ((char *)s);
		if (*s == 0)
			return (NULL);
		s++;
	}
}
/*
#include <stdio.h>
int main(void)
{
	char s[] = "Monika i Konstanty";
	printf("%s\n", ft_strchr(s, 'a'));
	return 0;
}
*/
