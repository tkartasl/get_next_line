/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkartasl <tkartasl@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 14:15:19 by tkartasl          #+#    #+#             */
/*   Updated: 2023/11/24 15:32:38 by tkartasl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

static char	*ft_get_line(int fd, char *buffer, size_t bcount)
{
	char	*temp;
	char	*str;
	size_t	len;

	temp = 0;
	str = 0;
	len = 0;
	while (ft_strchr(buffer, '\n') == 0 && bcount != 0)
		bcount = read(fd, buffer, BUFFER_SIZE);
	while (buffer[len] != '\n' && buffer[len] != 0)
		len++;
	str = ft_strndup(buffer, len);
	if (str == 0)
		return (0);
	if (len < ft_strlen(buffer))
		temp = ft_strndup(&buffer[len + 1], ft_strlen(buffer) - len);
	if (temp == 0)
		return (0);
	buffer = temp;
	return (str);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];	
	char		*str;
	
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	str = ft_get_line(fd, buffer, 1);
	return (str);
}
