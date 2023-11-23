/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkartasl <tkartasl@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 09:43:07 by tkartasl          #+#    #+#             */
/*   Updated: 2023/11/23 14:32:24 by tkartasl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"
#include <stdio.h>

/*static void	ft_get_extra(char *buffer)
{
	int 	i;
	int		j;
	char	tempbuffer[BUFFER_SIZE + 1];

	//printf("buffer before get extra: %s\n", buffer);
	j = 0;
	i = 0;
	while (buffer[j] != '\n' && buffer[j] != 0)
		j++;
	j++;
	if (ft_strchr(buffer, '\n') == 0)
		j = 0;
	while (buffer[j] != 0)
	{
		tempbuffer[i] = buffer[j];
		i++;
		j++;
	}
	i = 0;
	while (i < j)
	{
		buffer[i] = tempbuffer[i];
		i++;
	}
	buffer[i] = 0;
	//printf("buffer after get extra: %s\n", buffer);
}*/

static char	*ft_clean_end(char *str, char *buffer)
{
	unsigned int	i;
	size_t			len;
	int				j;
	char			*temp;

	temp = str;
	j = 0;
	len = 0;
	i = 0;
	while (temp[len] != '\n' && temp[len] != 0)
		len++;
	ft_bzero(buffer, BUFFER_SIZE + 1);
	if (temp[len] == 0)
		return (temp);
    ft_bzero(buffer, BUFFER_SIZE + 1);
	j = len + 1;
    while (temp[j] != 0)
		buffer[i++] = temp[j++];
	//free (temp);
	temp = ft_substr(str, 0, len + 1);
	if (*temp == 0)
	{
		free(temp);
		return (0);
	}
	free (str);
	return (temp);
}

static char	*ft_cpy_line(int fd, char *buffer)
{
	char	*str;
	size_t	bcount;

	bcount = 1;
	str = ft_substr(buffer, 0, ft_strlen(buffer));
	if (str == 0)
		return (0);
	while (ft_strchr(buffer, '\n') == 0 && bcount != 0)
	{
		//ft_bzero(buffer, BUFFER_SIZE + 1);
		bcount = read(fd, buffer, BUFFER_SIZE); 
		if (bcount < 0)
			return (0);
		//if (bcount != 0 && ft_strchr(buffer, '\n') == 0)
		buffer[bcount] = 0;
		str = ft_strjoin(str, buffer);
		if (str == 0)
		{
			free(str);
			return (0);
		}
	}
	//printf("%s", buffer);
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
	if (*str == 0)
    {
		free(str);
		return (0);
    }
//	printf("str after copy line: %s\n", str);
	str = ft_clean_end(str, buffer);
	//printf("str after clean end: %s\n", str);
	//ft_get_extra(buffer);
	return (str);
}
