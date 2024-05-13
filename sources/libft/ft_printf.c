/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopoka <lopoka@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 18:27:13 by lopoka            #+#    #+#             */
/*   Updated: 2024/05/13 17:32:12 by lopoka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	prnt_f(char f, va_list arg)
{
	int	len;
	int	err;

	err = 0;
	len = 0;
	if (f == 'c')
		len += prnt_c(va_arg(arg, int));
	if (f == 's')
		prnt_s(va_arg(arg, char *), &len, &err);
	if (f == 'p')
		prnt_p(va_arg(arg, unsigned long long), &len, &err);
	if (f == 'd')
		prnt_d(va_arg(arg, int), &len, &err);
	if (f == 'i')
		prnt_d(va_arg(arg, int), &len, &err);
	if (f == 'u')
		prnt_u(va_arg(arg, unsigned int), &len, &err);
	if (f == 'x')
		prnt_x(va_arg(arg, unsigned int), &len, 0, &err);
	if (f == 'X')
		prnt_x(va_arg(arg, unsigned int), &len, 1, &err);
	if (f == '%')
		len += prnt_c('%');
	return (len);
}

int	ft_printf(const char *s, ...)
{
	int			i;
	int			res;
	va_list		arg;
	int			err;

	i = 0;
	res = 0;
	va_start(arg, s);
	while (s[i])
	{
		if (s[i] == '%')
		{
			err = prnt_f(s[i + 1], arg);
			i++;
		}
		else
			err = prnt_c(s[i]);
		if (err < 0)
			return (-1);
		res += err;
		i++;
	}
	va_end(arg);
	return (res);
}
