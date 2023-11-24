/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkartasl <tkartasl@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 12:00:59 by tkartasl          #+#    #+#             */
/*   Updated: 2023/11/24 14:33:17 by tkartasl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"
#include <stdio.h>

char	*ft_get_extra(char *buffer)
{
	char	*temp;
	int		i;

	temp = 0;
	i = 0;
	while (buffer[i] != '\n' && buffer[i] != 0)
		i++;
	if (buffer[i] == '\n')
		temp = ft_strdup(&buffer[i + 1]);
	if (temp == 0)
		return (0);
	ft_bzero(buffer, BUFFER_SIZE + 1);
	return (temp);
}

char	*ft_clean_end(char *str)
{
	int		i;
	char	*retstr;
	int		j;

	//printf("%s", str);
	j = 0;
	i = 0;
	while (str[i] != '\n' && str[i] != 0)
		i++;
	if (str[i] == 0)
		return (str);
	str[i + 2] = 0;
	retstr = ft_strdup(str);
	free (str);
	return (retstr);
}

static char	*ft_get_line(int fd, char* buffer)
{
	char	*str;
	size_t	bcount;

	bcount = BUFFER_SIZE;
	str = ft_strdup(buffer);
	if (str == 0)
		return (0);
	while (ft_strchr(buffer, '\n') == 0 && bcount == BUFFER_SIZE)
	{
		bcount = read(fd, buffer, BUFFER_SIZE);
		if (bcount < 0)
			return (0);
		buffer[bcount] = 0;
		str = ft_strjoin(str, buffer);
		//printf("%s\n", buffer);
		if (str == 0)
		{
			free (str);
			return (0);
		}
	}
	//printf("%s", str);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*str;
	char		*temp;
	int			i;

	i = 0;
	temp = 0;
	str = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	str = ft_get_line(fd, buffer);
	if (str == 0)
		return (0);
	str = ft_clean_end(str);
	temp = ft_get_extra(buffer);
	while (temp[i] != 0)
	{
		buffer[i] = temp[i];
		i++;
	}
	free (temp);
	return (str);
}
