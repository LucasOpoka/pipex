/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lxtoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopoka <lopoka@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 13:17:03 by lopoka            #+#    #+#             */
/*   Updated: 2024/05/15 13:19:24 by lopoka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static void	rec_core(unsigned int num, unsigned int len, t_itoa *x)
{
	long	indx;

	if (num / 16 > 0)
		rec_core(num / 10, len + 1, x);
	if (num / 16 == 0)
	{
		x->res = (char *) malloc((len + 1) * sizeof(char));
		if (!x->res)
			return ;
		x->tot_l = len;
		x->res[len] = 0;
	}
	indx = x->tot_l - len;
	if (x->res)
		x->res[indx] = "0123456789abcdef"[num % 16];
}

char	*ft_lxtoa(unsigned int num)
{
	unsigned int	len;
	t_itoa			*x;
	char			*res;

	len = 1;
	x = (t_itoa *) malloc(1 * sizeof(t_itoa));
	if (!x)
		return (NULL);
	rec_core(num, len, x);
	res = x->res;
	free(x);
	return (res);
}
