
#include "get_next_line.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*sub;
	size_t	i;
	size_t	l;

	i = 0;
	if (!s1 || !s2)
		return (NULL);
	l = ft_strlen(s1) + ft_strlen(s2) + 1;
	if (!(sub = (char*)malloc(l * sizeof(char))))
		return (NULL);
	while (*s1)
		sub[i++] = *s1++;
	while (*s2)
		sub[i++] = *s2++;
	sub[i] = '\0';
	return (sub);
}

char	*ft_strchr(const char *str, int ch)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == ch)
			return ((char *)str + i);
		i++;
	}
	if (str[i] == ch)
		return ((char *)str + i);
	return (0);
}


char	*ft_strdup(const char *str)
{
	char *a;
	char *b;

	if (!(a = (char*)malloc((ft_strlen(str) + 1) * sizeof(char))))
		return (NULL);
	b = a;
	while (*str)
	{
		*a++ = *str++;
	}
	*a = '\0';
	return (b);
}


size_t	ft_strlen(const char *s)
{
	size_t len;

	len = 0;
	while (s && s[len])
		len++;
	return (len);
}

char	*ft_strcpy(char *dst, const char *src)
{
	int		i;

	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i += 1;
	}
	dst[i] = '\0';
	return (dst);
}
