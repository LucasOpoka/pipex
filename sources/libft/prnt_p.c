/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prnt_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopoka <lopoka@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 13:58:37 by lopoka            #+#    #+#             */
/*   Updated: 2024/05/13 17:34:52 by lopoka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	prnt_p(unsigned long long pt, int *len, int *err)
{
	char	c;

	if (*len == 0)
		err_chck(write(1, "0x", 2), len, err);
	if (pt / 16 > 0 && !*err)
		prnt_p(pt / 16, len, err);
	if (pt % 16 <= 9)
		c = pt % 16 + 48;
	else
		c = pt % 16 + 87;
	if (!*err)
		err_chck(write(1, &c, 1), len, err);
}
