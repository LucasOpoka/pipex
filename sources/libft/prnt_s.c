/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prnt_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopoka <lopoka@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 13:58:19 by lopoka            #+#    #+#             */
/*   Updated: 2024/05/13 17:34:21 by lopoka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	prnt_s(char *str, int *len, int *err)
{
	int	i;

	if (!str)
		err_chck(write(1, "(null)", 6), len, err);
	else
	{
		i = 0;
		while (str[i] && !*err)
			err_chck(write(1, &str[i++], 1), len, err);
	}
}
