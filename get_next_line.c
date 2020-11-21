/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchristi <jchristi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 15:05:44 by jchristi          #+#    #+#             */
/*   Updated: 2020/11/21 19:41:59 by jchristi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

static char	*ft_strnew(size_t size)
{
	char *name;

	name = (char*)malloc(sizeof(char) * (size + 1));
	return (name);
}

void	ft_strclr(char *s)
{
	int k;

	k = 0;
	while (s[k] != '\0')
	{
		s[k] = '\0';
	}
}

char *check_part_of_buf(char *part_of_buf, char **line)
{
	char *p_to_n;
	
	p_to_n = NULL;
	if (part_of_buf)
	{
		if ((p_to_n = ft_strchr(part_of_buf, '\n')))
		{
			*p_to_n = '\0';
			*line = ft_strdup(part_of_buf);
			ft_strcpy(part_of_buf, ++p_to_n);
		}
		else
		{
			*line = ft_strdup(part_of_buf);
			ft_strclr(part_of_buf);
		}
	}
	else
	{
		*line = ft_strnew(1);
	}
	return (p_to_n);
}

int	get_next_line(int fd, char **line)
{
	char		buf[BUFFER_SIZE+1];
	int			num_of_read;
	char		*p_to_n;
	static char	*part_of_buf;
	char		*tmp_for_leaks;

	p_to_n = check_part_of_buf(part_of_buf, line);
	while (!p_to_n && (num_of_read = read(fd, buf, BUFFER_SIZE)))
	{
		buf[num_of_read] = '\0';
		if ((p_to_n = ft_strchr(buf, '\n')))
		{
			*p_to_n = '\0';
			p_to_n++;
			part_of_buf = ft_strdup(p_to_n);
		}
		tmp_for_leaks = *line;
		*line = ft_strjoin(*line, buf);
		free(tmp_for_leaks);
	}
	return(num_of_read || ft_strlen(part_of_buf) || ft_strlen(*line)) ? 1 : 0;
}

int	main(void)
{
	char *line;
	int fd;

	fd = open("text.txt", O_RDONLY);
	while(get_next_line(fd, &line))
		printf("%s\n", line);
	
	//get_next_line(fd, &line);
	//printf("%s\n", line);

	//get_next_line(fd, &line);
	//printf("%s\n", line);
}