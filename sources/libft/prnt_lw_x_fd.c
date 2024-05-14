/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prnt_lw_x_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopoka <lopoka@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 13:32:44 by lopoka            #+#    #+#             */
/*   Updated: 2024/05/14 13:33:33 by lopoka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	prnt_lw_x_fd(int fd, unsigned int n, int *len, int *err)
{
	char	c;
	char	*base;

	base = "0123456789abcdef";
	if (n / 16 > 0)
		prnt_lw_x_fd(fd, n / 16, len, err);
	c = base[n % 16];
	if (!*err)
		err_chck(write(fd, &c, 1), len, err);
}
