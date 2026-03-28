/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mawako <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 12:10:53 by mawako            #+#    #+#             */
/*   Updated: 2025/09/29 18:48:18 by mawako           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	skip_to_map(int fd, char **line)
{
	char	*p;

	if (*line == NULL)
		*line = get_next_line(fd);
	while (*line && !is_map_line(*line))
	{
		p = *line;
		while (*p == ' ' || *p == '\t')
			p++;
		if (*p != '\0' && *p != '\n' && *p != '\r')
		{
			ft_printf("Error: unknown key found\n");
			free(*line);
			*line = NULL;
			return (-1);
		}
		free(*line);
		*line = get_next_line(fd);
	}
	if (*line == NULL)
		return (0);
	return (1);
}

int	final_checks(t_mapread *st)
{
	if (st->rows == 0)
		return (0);
	if (!st->last_w)
		return (ft_printf("Error: map should closed by walls\n"), -1);
	if (st->pcnt != 1)
		return (ft_printf("Error: player should be one\n"), -1);
	return (st->rows);
}

static int	commit_row(t_vars *v, char *line, t_mapread *st)
{
	if (st->prev)
		free(st->prev);
	st->prev = ft_strdup(line);
	if (st->prev == NULL)
		return (-1);
	parse_map_line(v, line, st->rows);
	st->rows++;
	return (1);
}

static int	process_first_row(t_vars *v, char *line, t_mapread *st)
{
	if (validate_first(line, &st->b, &st->pcnt) < 0)
		return (-1);
	st->last_w = 1;
	st->first = 0;
	return (commit_row(v, line, st));
}

int	consume_row(t_vars *v, char **line, t_mapread *st)
{
	int	ok;

	ok = 1;
	if (!is_map_line(*line))
	{
		if (st->rows > 0)
		{
			if (**line == '\0' || **line == '\n' || **line == '\r')
				ok = 0;
			else
				ok = -1;
		}
		else
			ok = 0;
	}
	else if (st->first)
		ok = process_first_row(v, *line, st);
	else if (validate_middle(*line, st, st->rows) < 0)
		ok = -1;
	else
		ok = commit_row(v, *line, st);
	free(*line);
	*line = NULL;
	return (ok);
}
