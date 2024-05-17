/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopoka <lopoka@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 12:19:01 by lopoka            #+#    #+#             */
/*   Updated: 2024/05/15 12:41:29 by lopoka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static void	rec_core(unsigned long long pt, long len, t_itoa *x)
{
	long	indx;

	if (pt / 16 > 0)
		rec_core(pt / 16, len + 1, x);
	if (pt / 16 == 0)
	{
		x->res = (char *) malloc((len + 1) * sizeof(char));
		if (!x->res)
			return ;
		x->tot_l = len;
		x->res[0] = '0';
		x->res[1] = 'x';
		x->res[len] = 0;
	}
	indx = x->tot_l - len + 2;
	if (x->res)
		x->res[indx] = "0123456789abcdef"[pt % 16];
}

char	*ft_ptoa(unsigned long long pt)
{
	long		len;
	t_itoa		*x;
	char		*res;

	len = 1;
	len += 1;
	x = (t_itoa *) malloc(1 * sizeof(t_itoa));
	if (!x)
		return (NULL);
	rec_core(pt, len, x);
	res = x->res;
	free(x);
	return (res);
}
