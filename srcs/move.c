/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mawako <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 17:30:23 by mawako            #+#    #+#             */
/*   Updated: 2025/08/30 13:31:19 by mawako           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_forward(t_vars *vars, double move_speed)
{
	if (vars->world_map[(int)vars->pos_y]
		[(int)(vars->pos_x + vars->dir_x * move_speed)] == 0)
		vars->pos_x += vars->dir_x * move_speed;
	if (vars->world_map[(int)(vars->pos_y + vars->dir_y * move_speed)]
		[(int)vars->pos_x] == 0)
		vars->pos_y += vars->dir_y * move_speed;
}

void	move_backward(t_vars *vars, double move_speed)
{
	if (vars->world_map[(int)vars->pos_y]
		[(int)(vars->pos_x - vars->dir_x * move_speed)] == 0)
		vars->pos_x -= vars->dir_x * move_speed;
	if (vars->world_map[(int)(vars->pos_y - vars->dir_y * move_speed)]
		[(int)vars->pos_x] == 0)
		vars->pos_y -= vars->dir_y * move_speed;
}

void	move_left(t_vars *vars, double move_speed)
{
	if (vars->world_map[(int)vars->pos_y]
		[(int)(vars->pos_x - vars->plane_x * move_speed)] == 0)
		vars->pos_x -= vars->plane_x * move_speed;
	if (vars->world_map[(int)(vars->pos_y - vars->plane_y * move_speed)]
		[(int)vars->pos_x] == 0)
		vars->pos_y -= vars->plane_y * move_speed;
}

void	move_right(t_vars *vars, double move_speed)
{
	if (vars->world_map[(int)vars->pos_y]
		[(int)(vars->pos_x + vars->plane_x * move_speed)] == 0)
		vars->pos_x += vars->plane_x * move_speed;
	if (vars->world_map[(int)(vars->pos_y + vars->plane_y * move_speed)]
		[(int)vars->pos_x] == 0)
		vars->pos_y += vars->plane_y * move_speed;
}
