/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuu <shuu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 14:42:25 by shuu              #+#    #+#             */
/*   Updated: 2025/09/29 12:18:39 by mawako           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_map_line(const char *s)
{
	int	i;
	int	has_tile;

	if (!s)
		return (0);
	i = 0;
	has_tile = 0;
	while (s[i] && s[i] != '\n')
	{
		if (s[i] != '0' && s[i] != '1' && s[i] != 'N' && s[i] != 'S'
			&& s[i] != 'E' && s[i] != 'W' && s[i] != ' ' && s[i] != '\t')
			return (0);
		if (s[i] == '0' || s[i] == '1' || s[i] == 'N'
			|| s[i] == 'S' || s[i] == 'E' || s[i] == 'W')
			has_tile = 1;
		i++;
	}
	return (has_tile);
}

void	parse_map_line(t_vars *v, char *line, int row)
{
	int		x;
	char	c;

	x = 0;
	while (line[x] && line[x] != '\n' && x < MAPWIDTH)
	{
		c = line[x];
		if (c == '1' || c == ' ' || c == '\t')
			v->world_map[row][x] = 1;
		else if (c == '0')
			v->world_map[row][x] = 0;
		else if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		{
			set_player_start(v, c, x, row);
			v->world_map[row][x] = 0;
		}
		else
			v->world_map[row][x] = 1;
		x++;
	}
	while (x < MAPWIDTH)
		v->world_map[row][x++] = 1;
}
