/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mawako <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 17:30:09 by mawako            #+#    #+#             */
/*   Updated: 2025/08/30 13:13:40 by mawako           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	handle_movement(t_vars *vars)
{
	double	move_speed;
	double	rot_speed;

	move_speed = 3.0 * vars->delta_time;
	rot_speed = 2.0 * vars->delta_time;
	if (vars->keys.up)
		move_forward(vars, move_speed);
	if (vars->keys.down)
		move_backward(vars, move_speed);
	if (vars->keys.left)
		move_left(vars, move_speed);
	if (vars->keys.right)
		move_right(vars, move_speed);
	if (vars->keys.rot_left)
		rotate_left(vars, rot_speed);
	if (vars->keys.rot_right)
		rotate_right(vars, rot_speed);
}

int	render(t_vars *vars)
{
	update_delta_time(vars);
	draw_background(vars);
	draw_walls(vars);
	handle_movement(vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 0, 0);
	return (0);
}
