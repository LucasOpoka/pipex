#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct token
{
    const char	*start;
    const char	*end;
} Token;

Token getToken(const char **sp, char sep)
{
    const char *s = *sp;
    Token token;

	token.start = NULL;
	token.end = NULL;

    while(*s && *s == sep)//skip start separators
        s++;
    if(!*s)
	{
        *sp = s;
        return (token);//return null token
    }
    token.start = s;
    while(*s && *s != sep)
	{
        if(*s == '\'')
		{
			char *p = strchr(s + 1, '\'');//search end '"'
            if(p)
			{
                s = p;//skip to '"'
				token.start++;
				token.end = s;
				*sp = s + 1;
				return (token);
			}
        }

        if(*s == '"')
		{
			char *p = strchr(s + 1, '"');//search end '"'
            if(p)
			{
                s = p;//skip to '"'
				token.start++;
				token.end = s;
				*sp = s + 1;
				return (token);
			}
        }
        s++;
    }
    token.end = s;
    *sp = s;
    return (token);
}

int count_words(const char *s, char sep)
{
    int		count;
    Token	token;

	token = getToken(&s, sep);
	count = 0;
    while(token.start != NULL)
	{
        token = getToken(&s, sep);
		count++;
    }
    return (count);
}

char *ft_strsub(Token token)
{
    size_t len = token.end - token.start;
    char *sub = malloc(len + 1);
    if (sub)
	{
        memcpy(sub, token.start, len);
        sub[len] = 0;
    }
    return (sub);
}

char **split2(const char *s, char sep)
{
	char	**res;
    int		words;
	Token	token;
	int		i;

	words = count_words(s, sep);
    if (!s || !sep || !words)
        return (NULL);
    res = malloc(sizeof(char *) * (words + 1));
    if (!res)
    {
	    return (NULL);
	}
	i = 0;
	token = getToken(&s, sep);
    while(token.start != NULL)
	{
        res[i++] = ft_strsub(token);
        token = getToken(&s, sep);
    }
    res[i] = NULL;
    return (res);
}
/*
int main(int argc, char **argv){
    const char *text = "awk '{res+= $2} END {print res}' hello \"xx xx\" 'yy yy' \"wdcwd\" wdcewvw";
    char **s = split2(text, ' ');
    int i = 0;
    
	while (s[i])
        printf("%s\n", s[i++]);
    return 0;
}*/
