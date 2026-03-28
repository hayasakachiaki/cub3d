/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mawako <maedayukimi@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 14:56:38 by mawako            #+#    #+#             */
/*   Updated: 2024/11/01 12:05:52 by mawako           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	gnl_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

char	*gnl_strjoin(const char *buf, const char *dst)
{
	char	*res;
	char	*s;

	res = malloc(sizeof(char) *(gnl_strlen(buf) + gnl_strlen(dst) + 1));
	if (!res || !buf || !dst)
		return (NULL);
	s = res;
	while (*buf)
		*res++ = *buf++;
	while (*dst)
		*res++ = *dst++;
	*res = 0;
	return (s);
}

char	*gnl_strchr(const char *s, int c)
{
	int	i;

	i = gnl_strlen(s) + 1;
	while (i--)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	return (NULL);
}

void	*gnl_calloc(size_t nmemb, size_t size)
{
	void	*mem;

	if (nmemb && size > SIZE_MAX / nmemb)
		return (NULL);
	mem = malloc(nmemb * size);
	if (mem == NULL)
		return (NULL);
	gnl_bzero(mem, nmemb * size);
	return (mem);
}

void	*gnl_bzero(void *s, size_t n)
{
	unsigned char	*src;

	src = (unsigned char *)s;
	while (n--)
	{
		*src = 0;
		src++;
	}
	return (s);
}
