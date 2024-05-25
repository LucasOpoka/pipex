/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_here_doc_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopoka <lopoka@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 22:01:14 by lopoka            #+#    #+#             */
/*   Updated: 2024/05/25 16:04:11 by lopoka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/pipex.h"

static inline void	ft_here_doc_pipe_fork(t_pipex *stc, pid_t *pid, int *fd)
{
	//
	(void) stc;
	if (pipe(fd) == -1)
	{
		ft_printf_fd(2, "Pipe failed");
		exit (1);
	}
	*pid = fork();
	if (*pid == -1)
	{
		close(fd[0]);
		close(fd[1]);
		ft_printf_fd(2, "Fork failed");
		exit (1);
	}
}

static inline void	ft_read_doc(t_pipex *stc, int *fd)
{
	int		i;
	int		ret;
	char	c;
	char	*line;

	i = 0;
	line = (char *) malloc(10000);
	if (!line)
		exit (1);
	ret = read(0, &c, 1);
	while (ret && c && c != 10)
	{
		line[i++] = c;
		ret = read(0, &c, 1);
	}
	line[i] = 0;
	if (ft_strcmp(line, stc->av[2]))
	{
		ft_printf_fd(fd[1], "%s", line);
		ft_printf_fd(fd[1], "%c", 10);
		ft_read_doc(stc, fd);
	}
	else
		close(fd[1]);
	free(line);
}

void	ft_here_doc(t_pipex *stc, int i)
{
	pid_t	pid;
	int		fd[2];

	if (stc->ac < 6)
	{
		ft_printf_fd(2, "here_doc usage:\nhere_doc LIMITER ");
		ft_printf_fd(2, "cmnd_1 | ... | cmnd_n out_file\n");
		exit (1);
	}
	ft_here_doc_pipe_fork(stc, &pid, fd);
	if (pid == 0)
	{
		//ft_close(stc, fd);
		close(fd[0]);
		ft_read_doc(stc, fd);
		exit (0);
	}
	else
	{
		close(fd[1]);
		ft_redirect_and_wait(stc, pid, i, fd);
	}
}
