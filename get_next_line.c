/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areggie <areggie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 12:26:03 by areggie           #+#    #+#             */
/*   Updated: 2020/12/14 22:49:07 by areggie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t			ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	char		*d;
	const char	*s;
	int			i;
	int			j;

	d = (char *)dst;
	s = (const char *)src;
	i = 0;
	j = 0;
	if (s == NULL && d == NULL)
		return (0);
	if ((!(dstsize)))
		return (ft_strlen(s));
	while (dstsize != 0 && s[i] != 0)
	{
		d[j] = s[i];
		i++;
		j++;
		dstsize--;
	}
	if (dstsize > 0)
		d[j] = '\0';
	else
		d[j - 1] = '\0';
	return (ft_strlen(s));
}

char			*ft_strdup(const char *s1)
{
	int			i;
	int			j;
	char		*result;

	result = malloc(ft_strlen(s1) + 1);
	if (result == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i] != '\0')
	{
		result[j] = s1[i];
		i++;
		j++;
	}
	result[j] = '\0';
	return (result);
}

int				see_remnants(char *rem, char **line)
{
	char		*ptr;

	ptr = NULL;
	if (rem[0] != '\0')
	{
		if ((ptr = ft_strchr(rem, '\n')))
		{
			*ptr = '\0';
			if (!(*line = ft_strdup(rem)))
				return (-1);
			ptr++;
			ft_strlcpy(rem, ptr, BUFFER_SIZE + 1);
			return (1);
		}
		else
		{
			if (!(*line = ft_strdup(rem)))
				return (-1);
			ft_bzero(rem, ft_strlen(rem));
		}
	}
	else if (!(*line = ft_calloc(1, 1)))
		return (-1);
	return (0);
}

int				get_next_line(int fd, char **line)
{
	static char	remnants[BUFFER_SIZE + 1];
	int			whatwasread;
	char		buffer[BUFFER_SIZE + 1];
	char		*ptr;
	int			flag;

	if (!line || ((read(fd, (ptr = NULL), 0)) < 0) || BUFFER_SIZE < 1)
		return (-1);
	if (((flag = see_remnants(remnants, line)) == 1) || (flag == -1))
		return (flag);
	buffer[0] = 0;
	whatwasread = 1;
	while ((!(ptr = ft_strchr(buffer, '\n')) && whatwasread != 0))
	{
		if (!(*line = ft_strjoin(*line, buffer)))
			return (-1);
		if (!(whatwasread = read(fd, buffer, BUFFER_SIZE)))
			return (0);
		buffer[whatwasread] = '\0';
	}
	ft_strlcpy(remnants, ft_strchr(buffer, '\n') + 1, (BUFFER_SIZE + 1));
	*ptr = '\0';
	if (!(*line = ft_strjoin(*line, buffer)))
		return (-1);
	return (1);
}
