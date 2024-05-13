/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prnt_u.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopoka <lopoka@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 13:59:25 by lopoka            #+#    #+#             */
/*   Updated: 2024/05/13 17:35:26 by lopoka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	prnt_u(unsigned int nb, int *len, int *err)
{
	char	n;

	if (nb / 10 > 0 && !*err)
	{
		prnt_u(nb / 10, len, err);
	}
	n = (nb % 10) + 48;
	if (!*err)
		err_chck(write (1, &n, 1), len, err);
}
