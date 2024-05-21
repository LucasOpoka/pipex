/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopoka <lopoka@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 13:25:53 by lopoka            #+#    #+#             */
/*   Updated: 2024/05/21 17:14:15 by lopoka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <sys/types.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <errno.h>
# include "../sources/libft/libft.h"

typedef struct s_pipex
{
	int		ac;
	char	**av;
	char	**env;
	int		fd_in;
	int		fd_out;
	int		*errarr;
}	t_pipex;

char	*ft_find_pth(char **cmnd, char **env, int last);
void	ft_exe(char *cmnd_str, char **env, int last);
void	ft_first_child(t_pipex *stc, int fd_int, int i);
void	ft_last_child(t_pipex *stc, int *prev_fd, int i);
void	ft_middle_child(t_pipex *stc, int *prev_fd, int i);
void	ft_close_in_out_pipe(t_pipex *stc);

#endif
