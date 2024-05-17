/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prnt_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopoka <lopoka@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 13:59:25 by lopoka            #+#    #+#             */
/*   Updated: 2024/05/17 10:54:17 by lopoka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_prnt_u(t_printf *stc, unsigned int nb)
{
	if (nb / 10 > 0)
		ft_prnt_u(stc, nb / 10);
	ft_prnt_c(stc, (nb % 10) + 48);
}