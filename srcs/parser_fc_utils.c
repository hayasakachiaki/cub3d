/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_fc_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuu <shuu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 15:30:00 by sumedai           #+#    #+#             */
/*   Updated: 2025/09/29 18:27:25 by mawako           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	apply_floor_color(t_vars *v, char *p, t_fc *st, char *line)
{
	char	*line_copy;
	int		col;

	line_copy = ft_strdup(p);
	if (!line_copy)
	{
		free(line);
		return (-1);
	}
	col = get_color(line_copy);
	free(line_copy);
	if (col < 0)
	{
		ft_printf("Error: invalid floor color (must be 0-255,0-255,0-255)\n");
		free(line);
		return (-1);
	}
	v->floor_color = col;
	st->fset = 1;
	free(line);
	return (1);
}

int	apply_ceiling_color(t_vars *v, char *p, t_fc *st, char *line)
{
	char	*line_copy;
	int		col;

	line_copy = ft_strdup(p);
	if (!line_copy)
	{
		free(line);
		return (-1);
	}
	col = get_color(line_copy);
	free(line_copy);
	if (col < 0)
	{
		ft_printf("Error: invalid ceiling color (must be 0-255,0-255,0-255)\n");
		free(line);
		return (-1);
	}
	v->ceiling_color = col;
	st->cset = 1;
	free(line);
	return (1);
}
