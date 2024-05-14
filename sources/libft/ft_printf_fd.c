/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopoka <lopoka@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 13:28:36 by lopoka            #+#    #+#             */
/*   Updated: 2024/05/14 13:36:46 by lopoka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	prnt_f_fd(int fd, char f, va_list arg)
{
	int	len;
	int	err;

	err = 0;
	len = 0;
	if (f == 'c')
		len += prnt_c_fd(fd, va_arg(arg, int));
	if (f == 's')
		prnt_s_fd(fd, va_arg(arg, char *), &len, &err);
	if (f == 'p')
		prnt_p_fd(fd, va_arg(arg, unsigned long long), &len, &err);
	if (f == 'd')
		prnt_d_fd(fd, va_arg(arg, int), &len, &err);
	if (f == 'i')
		prnt_d_fd(fd, va_arg(arg, int), &len, &err);
	if (f == 'u')
		prnt_u_fd(fd, va_arg(arg, unsigned int), &len, &err);
	if (f == 'x')
		prnt_lw_x_fd(fd, va_arg(arg, unsigned int), &len, &err);
	if (f == 'X')
		prnt_up_x_fd(fd, va_arg(arg, unsigned int), &len, &err);
	if (f == '%')
		len += prnt_c_fd(fd, '%');
	return (len);
}

int	ft_printf_fd(int fd, const char *s, ...)
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
			err = prnt_f_fd(fd, s[i + 1], arg);
			i++;
		}
		else
			err = prnt_c_fd(fd, s[i]);
		if (err < 0)
			return (-1);
		res += err;
		i++;
	}
	va_end(arg);
	return (res);
}
