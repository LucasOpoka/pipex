/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prnt_d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopoka <lopoka@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 13:59:00 by lopoka            #+#    #+#             */
/*   Updated: 2024/05/13 17:34:07 by lopoka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	prnt_d(int nb, int *len, int *err)
{
	char	n;

	if (nb == -2147483648)
		err_chck(write(1, "-2147483648", 11), len, err);
	else
	{
		if (nb < 0)
		{
			err_chck(write (1, "-", 1), len, err);
			nb *= -1;
		}
		if (nb / 10 > 0 && !*err)
		{
			prnt_d(nb / 10, len, err);
		}
		n = (nb % 10) + 48;
		if (!*err)
			err_chck(write(1, &n, 1), len, err);
	}
}
