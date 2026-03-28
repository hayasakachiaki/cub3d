/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_player_start.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mawako <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 14:15:08 by mawako            #+#    #+#             */
/*   Updated: 2025/08/30 14:15:26 by mawako           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	pattern_ns(t_vars *vars, char c)
{
	if (c == 'N')
	{
		vars->dir_x = 0;
		vars->dir_y = -1;
		vars->plane_x = 0.66;
		vars->plane_y = 0;
	}
	else
	{
		vars->dir_x = 0;
		vars->dir_y = 1;
		vars->plane_x = -0.66;
		vars->plane_y = 0;
	}
}

static void	pattern_we(t_vars *vars, char c)
{
	if (c == 'W')
	{
		vars->dir_x = -1;
		vars->dir_y = 0;
		vars->plane_x = 0;
		vars->plane_y = -0.66;
	}
	else
	{
		vars->dir_x = 1;
		vars->dir_y = 0;
		vars->plane_x = 0;
		vars->plane_y = 0.66;
	}
}

void	set_player_start(t_vars *vars, char c, int x, int y)
{
	vars->pos_x = x + 0.5;
	vars->pos_y = y + 0.5;
	if (c == 'N' || c == 'S')
		pattern_ns(vars, c);
	else if (c == 'W' || c == 'E')
		pattern_we(vars, c);
}
