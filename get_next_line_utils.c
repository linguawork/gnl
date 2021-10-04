/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areggie <areggie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 14:54:29 by areggie           #+#    #+#             */
/*   Updated: 2020/12/14 19:32:01 by areggie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t					ft_strlen(const char *s)
{
	const unsigned char	*string;
	int					b;

	if (!s)
		return (0);
	string = (const unsigned char *)s;
	b = 0;
	while (string[b] != '\0')
	{
		b++;
	}
	return (b);
}

char					*ft_strjoin(char *s1, char *s2)
{
	char				*s3;
	size_t				i;
	size_t				j;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	s3 = malloc((sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1)));
	if (!(s3))
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i] != '\0')
	{
		s3[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		s3[i] = s2[j];
		i++;
		j++;
	}
	s3[i] = '\0';
	free(s1);
	return (s3);
}

void					ft_bzero(void *s, size_t n)
{
	char				*result;
	size_t				i;

	result = (char *)s;
	i = 0;
	while (i < n)
	{
		result[i] = '\0';
		i++;
	}
}

void					*ft_calloc(size_t count, size_t size)
{
	char				*str;

	str = (char *)malloc(count * size);
	if (str == 0)
		return (0);
	ft_bzero(str, count * size);
	return (str);
}

char					*ft_strchr(const char *s, int c)
{
	const unsigned char *string;
	char				chr;
	int					i;

	string = (const unsigned char*)s;
	chr = (char)c;
	i = 0;
	while (string[i])
	{
		if (string[i] == chr)
			return ((char *)&string[i]);
		i++;
	}
	if (chr == '\0')
		return ((char *)&string[i]);
	return (0);
}
