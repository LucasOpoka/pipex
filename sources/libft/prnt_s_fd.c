/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prnt_s_fd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopoka <lopoka@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 13:29:12 by lopoka            #+#    #+#             */
/*   Updated: 2024/05/14 13:29:21 by lopoka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	prnt_s_fd(int fd, char *str, int *len, int *err)
{
	int	i;

	if (!str)
		err_chck(write(fd, "(null)", 6), len, err);
	else
	{
		i = 0;
		while (str[i] && !*err)
			err_chck(write(fd, &str[i++], 1), len, err);
	}
}
