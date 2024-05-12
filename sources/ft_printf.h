/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopoka <lopoka@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 13:54:39 by lopoka            #+#    #+#             */
/*   Updated: 2024/05/03 17:13:47 by lopoka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *s, ...);
int		prnt_c(int c);
void	prnt_s(char *str, int *len, int *err);
void	prnt_p(unsigned long long pt, int *len, int *err);
void	prnt_d(int nb, int *len, int *err);
void	prnt_u(unsigned int nb, int *len, int *err);
void	prnt_x(unsigned int n, int *len, int capital, int *err);
void	err_chck(int write_res, int *len, int *err);

#endif
