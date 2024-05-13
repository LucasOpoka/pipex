/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopoka <lopoka@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 12:05:51 by lopoka            #+#    #+#             */
/*   Updated: 2024/04/20 12:10:26 by lopoka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	char	endl;

	write(fd, s, ft_strlen(s));
	endl = '\n';
	write(fd, &endl, 1);
}
/*
#include <fcntl.h>
int main(void)
{
	int fd = open("file.txt", O_RDWR);
	ft_putendl_fd("Mominka i Lukasz", fd);
	return 0;
}
*/
