/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopoka <lopoka@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 12:15:33 by lopoka            #+#    #+#             */
/*   Updated: 2024/04/20 12:29:20 by lopoka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_putnbr_fd(int nb, int fd)
{
	char	n;

	if (nb == -2147483648)
		write(fd, "-2147483648", 11);
	else
	{
		if (nb < 0)
		{
			write (fd, "-", 1);
			nb *= -1;
		}
		if (nb / 10 > 0)
		{
			ft_putnbr_fd(nb / 10, fd);
		}
		n = (nb % 10) + 48;
		write (fd, &n, 1);
	}
}
/*
#include <fcntl.h>
int main(void)
{
	int fd = open("file.txt", O_RDWR);
	ft_putnbr_fd(-0, fd);
	return 0;
}
*/
