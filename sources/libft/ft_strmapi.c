/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopoka <lopoka@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 10:46:46 by lopoka            #+#    #+#             */
/*   Updated: 2024/04/20 11:05:56 by lopoka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*res;

	res = ft_strdup(s);
	i = 0;
	while (res && res[i])
	{
		res[i] = f(i, res[i]);
		i++;
	}
	return (res);
}
/*
#include <stdio.h>
char f(unsigned int i, char c)
{
    if (i % 2 == 0)
        return ft_toupper(c);
    else
        return ft_tolower(c);
}

int main(void)
{
	char *s = "monika i konstanty na plazy";
	printf("%s\n", ft_strmapi(s, f));
	return 0;
}
*/
