
#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

void	ft_bzero(void *s, size_t n)
{
	unsigned char *des;

	des = (unsigned char*)s;
	while (n != 0)
	{
		*des = '\0';
		des++;
		n--;
	}
}


void	*ft_calloc(size_t number, size_t size)
{
	void *des;

	des = malloc(number * (size));
	if (des != NULL)
		ft_bzero(des, size * number);
	return (des);
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