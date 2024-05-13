/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_sub.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopoka <lopoka@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 11:06:16 by lopoka            #+#    #+#             */
/*   Updated: 2024/05/13 12:33:57 by lopoka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static inline t_token	found_substring(t_token	*tk, const char **sp, char *p)
{
	tk->start++;
	tk->end = p;
	*sp = p + 1;
	return (*tk);
}

static inline t_token	get_token(const char **sp, char sep)
{
	char		*p;
	t_token		token;

	token.start = NULL;
	token.end = NULL;
	while (**sp && **sp == sep)
		(*sp)++;
	if (!**sp)
		return (token);
	token.start = *sp;
	while (**sp && **sp != sep)
	{
		if (**sp == '\'' || **sp == '"')
		{
			p = strchr(*sp + 1, **sp);
			if (p)
				return (found_substring(&token, sp, p));
		}
		(*sp)++;
	}
	token.end = *sp;
	return (token);
}

static inline int	count_words(const char *s, char sep)
{
	int		count;
	t_token	token;

	token = get_token(&s, sep);
	count = 0;
	while (token.start != NULL)
	{
		token = get_token(&s, sep);
		count++;
	}
	return (count);
}

static inline char	*ft_strsubstring(t_token token)
{
	size_t	len;
	char	*substring;

	len = token.end - token.start;
	substring = (char *) malloc(len + 1);
	if (!substring)
		return (NULL);
	ft_memcpy(substring, token.start, len);
	substring[len] = 0;
	return (substring);
}

char	**ft_split_sub(const char *str, char sep)
{
	char	**res;
	int		words;
	t_token	token;
	int		i;

	words = count_words(str, sep);
	res = (char **) malloc((words + 1) * sizeof(char *));
	if (!res)
		return (NULL);
	i = 0;
	token = get_token(&str, sep);
	while (token.start != NULL)
	{
		res[i] = ft_strsubstring(token);
		if (!res[i])
			return (ft_free_split(res, i));
		token = get_token(&str, sep);
		i++;
	}
	res[i] = NULL;
	return (res);
}
/*
#include <stdio.h>
int main(int argc, char **argv)
{
	const char *text = "awk 'some thing' hello \"str 1\" 'str 2' wdcewvw";
	char **s = split2(text, ' ');
	int i = 0;
	
	while (s[i])
		printf("%s\n", s[i++]);
	return 0;
}
*/
