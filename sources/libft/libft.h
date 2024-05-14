/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopoka <lopoka@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 10:34:58 by lopoka            #+#    #+#             */
/*   Updated: 2024/05/14 14:01:17 by lopoka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

typedef struct s_token
{
	const char	*start;
	const char	*end;
}	t_token;

typedef struct s_split
{
	char	**res;
	int		i;
	int		j;
	int		cw;
}	t_split;

typedef struct s_itoa
{
	long	tot_l;
	char	*res;
}	t_itoa;

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

int		ft_isalpha(int c);

int		ft_isdigit(int c);

int		ft_isalnum(int c);

int		ft_isascii(int c);

int		ft_isprint(int c);

size_t	ft_strlen(const char *str);

void	*ft_memset(void *mem, int val, size_t size);

void	ft_bzero(void *mem, size_t size);

void	*ft_memcpy(void *dest, const void *src, size_t size);

void	*ft_memmove(void *dest, const void *src, size_t size);

size_t	ft_strlcpy(char *dest, const char *src, size_t size);

size_t	ft_strlcat(char *dest, const char *src, size_t size);

int		ft_toupper(int c);

int		ft_tolower(int c);

char	*ft_strchr(const char *s, int c);

char	*ft_strchr(const char *s, int c);

char	*ft_strrchr(const char *s, int c);

int		ft_strncmp(const char *s1, const char *s2, size_t n);

void	*ft_memchr(const void *mem, int c, size_t size);

int		ft_memcmp(const void *mem1, const void *mem2, size_t size);

char	*ft_strnstr(const char *str, const char *to_find, size_t size);

char	*ft_strstr(const char *str, const char *to_find);

int		ft_atoi(const char *str);

void	*ft_calloc(size_t count, size_t size);

char	*ft_strdup(const char *src);

char	*ft_substr(char const *s, unsigned int start, size_t size);

char	*ft_strjoin(char const *s1, char const *s2);

char	*ft_strtrim(char const *s1, char const *set);

char	**ft_split(char const *str, char c);

char	**ft_split_sub(char const *str, char c);

char	**ft_free_split(char **arr, int i);

char	*ft_itoa(int nbr);

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));

void	ft_striteri(char *s, void (*f)(unsigned int, char*));

void	ft_putchar_fd(char c, int fd);

void	ft_putstr_fd(char *s, int fd);

void	ft_putendl_fd(char *s, int fd);

void	ft_putnbr_fd(int n, int fd);

t_list	*ft_lstnew(void *content);

void	ft_lstadd_front(t_list **lst, t_list *new);

int		ft_lstsize(t_list *lst);

t_list	*ft_lstlast(t_list *lst);

void	ft_lstadd_back(t_list **lst, t_list *new);

void	ft_lstdelone(t_list *lst, void (*del)(void*));

void	ft_lstclear(t_list **lst, void (*del)(void*));

void	ft_lstiter(t_list *lst, void (*f)(void *));

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

/* - - - - - ft_printf - - - - -*/

int		ft_printf(const char *s, ...);

int		prnt_c(int c);

void	prnt_s(char *str, int *len, int *err);

void	prnt_p(unsigned long long pt, int *len, int *err);

void	prnt_d(int nb, int *len, int *err);

void	prnt_u(unsigned int nb, int *len, int *err);

void	prnt_x(unsigned int n, int *len, int capital, int *err);

void	err_chck(int write_res, int *len, int *err);

/* - - - - - ft_printf_fd - - - - -*/

int		ft_printf_fd(int fd, const char *s, ...);

int		prnt_c_fd(int fd, int c);

void	prnt_s_fd(int fd, char *str, int *len, int *err);

void	prnt_p_fd(int fd, unsigned long long pt, int *len, int *err);

void	prnt_d_fd(int fd, int nb, int *len, int *err);

void	prnt_u_fd(int fd, unsigned int nb, int *len, int *err);

void	prnt_lw_x_fd(int fd, unsigned int n, int *len, int *err);

void	prnt_up_x_fd(int fd, unsigned int n, int *len, int *err);

#endif