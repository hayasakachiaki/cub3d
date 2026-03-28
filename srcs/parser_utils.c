/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumedai <sumedai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 16:07:22 by shuu              #+#    #+#             */
/*   Updated: 2025/09/29 18:30:33 by mawako           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	get_color(const char *line)
{
	const char	*start;

	start = line + 1;
	while (*start && (*start == '\t' || *start == ' '))
		start++;
	return (create_trgb((char *)start));
}

char	*texture_path(char *line)
{
	char	*path;
	int		i;

	i = 0;
	while (line[i] && (line[i] != '\t' && line[i] != ' ' && line[i] != '\n'))
		i++;
	path = malloc(sizeof(char) * (i + 1));
	if (!path)
		return (NULL);
	i = 0;
	while (line[i] && (line[i] != '\t' && line[i] != ' ' && line[i] != '\n'))
	{
		path[i] = line[i];
		i++;
	}
	path[i] = '\0';
	return (path);
}

int	is_dirction(char *line, int *i, char **key)
{
	const char	*dir[] = {"NO", "SO", "WE", "EA", NULL};

	*i = 0;
	while (dir[*i])
	{
		if (!ft_strncmp(line, dir[*i], 2))
		{
			*key = (char *)dir[*i];
			return (1);
		}
		(*i)++;
	}
	return (0);
}
