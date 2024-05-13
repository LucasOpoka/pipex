/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopoka <lopoka@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 09:28:17 by lopoka            #+#    #+#             */
/*   Updated: 2024/04/18 10:11:58 by lopoka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*tmp;
	char	cc;

	cc = (char) c;
	tmp = NULL;
	while (1)
	{
		if (*s == cc)
			tmp = (char *)s;
		if (*s == 0)
			return (tmp);
		s++;
	}
}
/*
#include <stdio.h>
int main(void)
{
	char s[] = "Monika i Konstanty";
	printf("%s\n", ft_strrchr(s, 'x'));
	return 0;
}
*/
