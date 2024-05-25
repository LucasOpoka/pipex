/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_mandatory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopoka <lopoka@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 14:34:58 by lopoka            #+#    #+#             */
/*   Updated: 2024/05/25 15:59:32 by lopoka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/pipex.h"

static inline void	ft_ret_err(t_pipex *stc)
{
	int	error;

	error = (stc->err & 0xff00) >> 8;
	exit (error);
}

int	main(int ac, char **av, char **env)
{
	t_pipex	stc;

	stc.ac = ac;
	stc.av = av;
	stc.env = env;
	stc.err = 0;
	if (ac != 5)
	{
		ft_printf_fd(2, "usage:\nin_file1 cmnd_1 cmnd_2 out_file\n");
		exit (1);
	}
	ft_first_child(&stc, 2);
	ft_ret_err(&stc);
}
