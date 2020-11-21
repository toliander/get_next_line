/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchristi <jchristi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 19:25:51 by jchristi          #+#    #+#             */
/*   Updated: 2020/11/21 21:21:40 by jchristi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

//#include "libft/libft.h"
char *check_part_of_buf(char *part_of_buf, char **line);
void	ft_strclr(char *s);
char	*ft_strdup(const char *str);

char	*ft_strchr(const char *str, int ch);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strcpy(char *dst, const char *src);
void	*ft_calloc(size_t number, size_t size);
void	ft_bzero(void *s, size_t n);
size_t	ft_strlen(const char *s);
int	get_next_line(int fd, char **line);

#endif