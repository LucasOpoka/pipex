/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopoka <lopoka@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 17:22:03 by lopoka            #+#    #+#             */
/*   Updated: 2024/04/20 13:28:34 by lopoka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static void	rec_core(long num, long neg, long len, t_itoa *x)
{
	long	indx;

	if (num / 10 > 0)
		rec_core(num / 10, neg, len + 1, x);
	if (num / 10 == 0)
	{
		x->res = (char *) malloc((len + 1) * sizeof(char));
		if (!x->res)
			return ;
		x->tot_l = len;
		x->res[len] = 0;
	}
	if (neg && x->res)
	{
		indx = x->tot_l - len + 1;
		x->res[0] = '-';
	}
	else
		indx = x->tot_l - len;
	if (x->res)
		x->res[indx] = num % 10 + 48;
}

char	*ft_itoa(int nbr)
{
	long		len;
	long		num;
	long		neg;
	t_itoa		*x;
	char		*res;

	num = (long) nbr;
	neg = 0;
	len = 1;
	if (num < 0)
	{
		neg = 1;
		len += 1;
		num *= -1;
	}
	x = (t_itoa *) malloc(1 * sizeof(t_itoa));
	if (!x)
		return (NULL);
	rec_core(num, neg, len, x);
	res = x->res;
	free(x);
	return (res);
}
/*
#include <stdio.h>
int main(void)
{
	char *s = ft_itoa(-1234);
	printf("%s\n", s);
	free(s);
	return 0;
}
*/
