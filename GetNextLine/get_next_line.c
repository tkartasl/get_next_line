/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkartasl <tkartasl@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 09:43:07 by tkartasl          #+#    #+#             */
/*   Updated: 2023/11/21 15:31:27 by tkartasl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

static char	*ft_get_extra(char *str, char *buffer)
{
	int i;

	i = 0;
	while (*str != '\n' && *str != 0)
		str++;
	str++;
	while (*str != 0)
	{
		buffer[i] = *str;
		i++;
		str++;
	}
	return (buffer);
}

static char	*ft_clean_end(char *str)
{
	unsigned int	i;
	size_t			len;

	len = 0;
	i = 0;
	while (str[len] != '\n' && str[len] != 0)
		len++;
	if (str[len] == 0)
		return (str);
	str = ft_substr(str, i, len);
	if (str == 0)
	{
		free(str);
		return (0);
	}
	return (str);
}

static char	*ft_cpy_line(int fd, char *buffer)
{
	char	*str;
	size_t	bcount;

	bcount = 1;
	str = buffer;
	while (ft_strchr(buffer, '\n') == 0 && bcount != 0)
	{
		bcount = read(fd, buffer, BUFFER_SIZE);
		if (bcount < 0)
			return (0);
		buffer[BUFFER_SIZE] = 0;
		str = ft_strjoin(str, buffer);
		if (str == 0)
		{
			free(str);
			return (0);
		}
	}
	return (str);
}

char	*get_next_line(int fd)
{
	char			*str;
	static char		buffer[BUFFER_SIZE + 1];

	str = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	str = ft_cpy_line(fd, buffer);
	*buffer = ft_get_extra(str, buffer);
	str = ft_clean_end(str);
	return (str);
}
