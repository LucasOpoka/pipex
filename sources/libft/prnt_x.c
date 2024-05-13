/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prnt_x.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopoka <lopoka@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 13:59:52 by lopoka            #+#    #+#             */
/*   Updated: 2024/05/13 17:35:07 by lopoka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	prnt_x(unsigned int n, int *len, int capital, int *err)
{
	char	c;
	char	*base;

	if (capital)
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	if (n / 16 > 0)
		prnt_x(n / 16, len, capital, err);
	c = base[n % 16];
	if (!*err)
		err_chck(write(1, &c, 1), len, err);
}
