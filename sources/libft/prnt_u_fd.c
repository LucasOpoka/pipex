/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prnt_u_fd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopoka <lopoka@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 13:28:16 by lopoka            #+#    #+#             */
/*   Updated: 2024/05/14 13:28:21 by lopoka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	prnt_u_fd(int fd, unsigned int nb, int *len, int *err)
{
	char	n;

	if (nb / 10 > 0 && !*err)
	{
		prnt_u_fd(fd, nb / 10, len, err);
	}
	n = (nb % 10) + 48;
	if (!*err)
		err_chck(write (fd, &n, 1), len, err);
}
