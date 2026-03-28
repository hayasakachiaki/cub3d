/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mawako <maedayukimi@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 14:48:26 by mawako            #+#    #+#             */
/*   Updated: 2024/11/01 12:06:27 by mawako           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*gnl_join_free(char *buffer, char *next)
{
	char	*temp;

	temp = gnl_strjoin(buffer, next);
	free(buffer);
	return (temp);
}

char	*read_file(int fd, char *buffer)
{
	char	*next;
	int		read_err;

	if (!buffer)
		buffer = gnl_calloc(1, 1);
	if (!buffer)
		return (NULL);
	next = gnl_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!next)
		return (free(buffer), NULL);
	read_err = 1;
	while (read_err > 0)
	{
		read_err = read(fd, next, BUFFER_SIZE);
		if (read_err == -1)
			return (free(next), free(buffer), NULL);
		next[read_err] = '\0';
		buffer = gnl_join_free(buffer, next);
		if (!buffer)
			return (free(next), NULL);
		if (gnl_strchr(next, '\n'))
			break ;
	}
	free(next);
	return (buffer);
}

char	*current_line(char *buffer)
{
	size_t	i;
	char	*line;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	line = gnl_calloc(i + 2, sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] && buffer[i] == '\n')
		line[i] = '\n';
	return (line);
}

char	*next_line(char *buffer)
{
	size_t	i;
	size_t	j;
	char	*line;

	i = 0;
	j = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
		return (free(buffer), NULL);
	line = gnl_calloc(gnl_strlen(buffer) - i + 1, sizeof(char));
	if (!line)
		return (NULL);
	i++;
	while (buffer[i])
		line[j++] = buffer[i++];
	free(buffer);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	buffer = read_file(fd, buffer);
	if (!buffer)
		return (NULL);
	line = current_line(buffer);
	buffer = next_line(buffer);
	return (line);
}
