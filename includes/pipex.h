/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopoka <lopoka@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 13:25:53 by lopoka            #+#    #+#             */
/*   Updated: 2024/05/20 17:32:51 by lopoka           ###   ########.fr       */
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
	int		fd[2];
	int		fd_in;
	int		fd_out;
	pid_t	pid1;
	pid_t	pid2;
	int		ret1;
	int		ret2;
}	t_pipex;

char	*ft_find_pth(char **cmnd, char **env, int last);
void	ft_exe(char *cmnd_str, char **env, int last);
void	ft_first_child(t_pipex *stc, char **av, char **env);
void	ft_last_child(t_pipex *stc, char **av, char **env);
void	ft_close_in_out_pipe(t_pipex *stc);

#endif
