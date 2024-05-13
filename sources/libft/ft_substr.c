/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopoka <lopoka@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 21:38:27 by lopoka            #+#    #+#             */
/*   Updated: 2024/04/18 22:43:35 by lopoka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t size)
{
	char			*new;
	size_t			avail_size;

	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	avail_size = ft_strlen(s + start);
	if (size > avail_size)
		size = avail_size;
	new = (char *) malloc((size + 1) * sizeof(char));
	if (!new)
		return (NULL);
	ft_strlcpy(new, s + start, size + 1);
	return (new);
}
/*
#include <stdio.h>
int main(void)
{
	char s[] = "Momina i Lukasz";
	printf("%s\n", ft_substr(s,3,3));
	return 0;
}
*/
