/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopoka <lopoka@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 13:41:26 by lopoka            #+#    #+#             */
/*   Updated: 2024/04/22 15:12:09 by lopoka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h" 

static char	*ft_strcpy(char *dest, const char *src)
{
	size_t	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strdup(const char *src)
{
	char	*new;

	new = (char *) malloc((ft_strlen(src) + 1) * sizeof(char));
	if (!new)
		return (0);
	ft_strcpy(new, src);
	return (new);
}
/*
#include <stdio.h>
int main(void)
{
	char str[] = "lalalalalala";
	char *new = ft_strdup(str);
	printf("%p %s\n%p %s", str, str, new, new);
	return 0;
}
*/
