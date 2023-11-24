/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkartasl <tkartasl@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 14:15:20 by tkartasl          #+#    #+#             */
/*   Updated: 2023/11/24 15:33:43 by tkartasl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char	*ft_strndup(const char *s1, int len)
{
	int		n;
	char	*p;

	n = 0;
	p = malloc((len + 1) * sizeof(char));
	if (p == 0)
		return (0);
	while (n < len && s[n] != 0)
	{
		p[n] = s1[n];
		n++;
	}
	p[n] = 0;
	return (p);
}

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		(*(char *)s = 0);
		i++;
		s++;
	}
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s;
	int		n;

	if (!s1 || !s2)
		return (0);
	n = 0;
	s = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (s == NULL)
		return (NULL);
	while (s1[n] != 0)
	{
		s[n] = s1[n];
		n++;
	}
	while (*s2 != 0)
	{
		s[n] = *s2;
		n++;
		s2++;
	}
	s[n] = 0;
	return (s);
}

char	*ft_strchr(const char *s, int c)
{
	char	cc;

	cc = (char)c;
	while (*s != 0)
	{
		if (*s == cc)
			return ((char *)s);
		s++;
	}
	if (*s == cc)
		return ((char *)s);
	else
		return (NULL);
}

size_t	ft_strlen(const char *s)
{
	size_t	t;

	t = 0;
	while (s[t] != 0)
	{
		t++;
	}
	return (t);
}
