/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopoka <lopoka@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 11:10:52 by lopoka            #+#    #+#             */
/*   Updated: 2024/04/20 11:29:21 by lopoka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	while (s && s[i])
	{
		f(i, &s[i]);
		i++;
	}
}
/*
#include <stdio.h>
void f(unsigned int i, char *c)
{
    if (i % 2 == 0)
        *c = ft_toupper(*c);
    else
        *c = ft_tolower(*c);
}

int main(void)
{
	char *s = ft_strdup("monika i konstanty na plazy");
	ft_striteri(s, f);
	printf("%s\n", s);
	return 0;
}
*/
