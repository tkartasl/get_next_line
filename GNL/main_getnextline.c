/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_getnextline.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkartasl <tkartasl@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 14:49:08 by tkartasl          #+#    #+#             */
/*   Updated: 2023/11/24 13:23:02 by tkartasl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int main()
{
	char	*str;
	int		fd;
	
	str = "m";
	fd = open ("../textfiles/jee.txt", O_RDONLY);
/*	while (*str != 0)
	{
		str = get_next_line(fd);
		//printf("%s", str);
		//fflush(stdout);
		}*/
	str = get_next_line(fd);
	printf("%s", str);
	fflush(stdout);
	str = get_next_line(fd);
    printf("%s", str);
	fflush(stdout);
	str = get_next_line(fd);
	fflush(stdout);
    printf("%s", str);
	str = get_next_line(fd);
	fflush(stdout);
	printf("%s", str);
	str = get_next_line(fd);
    fflush(stdout);
	printf("%s", str);
	/*str = get_next_line(fd);
    fflush(stdout);
	printf("%s", str);*/
	/*str = get_next_line(fd);
    printf("%s", str);
	str = get_next_line(fd);
    printf("%s", str);
	str = get_next_line(fd);
    printf("%s", str);
	str = get_next_line(fd);
    printf("%s", str);
	str = get_next_line(fd);
    printf("%s", str);
	str = get_next_line(fd);
    printf("%s", str);*/
	if (close(fd) < 0)
		return (-1);
	else
		return (0);
}