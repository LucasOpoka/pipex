/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prnt_p_fd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopoka <lopoka@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 13:28:00 by lopoka            #+#    #+#             */
/*   Updated: 2024/05/14 13:28:06 by lopoka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	prnt_p_fd(int fd, unsigned long long pt, int *len, int *err)
{
	char	c;

	if (*len == 0)
		err_chck(write(fd, "0x", 2), len, err);
	if (pt / 16 > 0 && !*err)
		prnt_p_fd(fd, pt / 16, len, err);
	if (pt % 16 <= 9)
		c = pt % 16 + 48;
	else
		c = pt % 16 + 87;
	if (!*err)
		err_chck(write(fd, &c, 1), len, err);
}
