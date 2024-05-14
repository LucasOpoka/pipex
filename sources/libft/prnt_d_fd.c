/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prnt_d_fd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopoka <lopoka@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 13:28:55 by lopoka            #+#    #+#             */
/*   Updated: 2024/05/14 13:28:58 by lopoka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	prnt_d_fd(int fd, int nb, int *len, int *err)
{
	char	n;

	if (nb == -2147483648)
		err_chck(write(fd, "-2147483648", 11), len, err);
	else
	{
		if (nb < 0)
		{
			err_chck(write (fd, "-", 1), len, err);
			nb *= -1;
		}
		if (nb / 10 > 0 && !*err)
		{
			prnt_d_fd(fd, nb / 10, len, err);
		}
		n = (nb % 10) + 48;
		if (!*err)
			err_chck(write(fd, &n, 1), len, err);
	}
}
