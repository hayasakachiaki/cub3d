/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mawako <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 13:09:05 by mawako            #+#    #+#             */
/*   Updated: 2025/08/30 13:12:23 by mawako           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	rotate_right(t_vars *vars, double rot_speed)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = vars->dir_x;
	old_plane_x = vars->plane_x;
	vars->dir_x = vars->dir_x * cos(rot_speed) - vars->dir_y * sin(rot_speed);
	vars->dir_y = old_dir_x * sin(rot_speed) + vars->dir_y * cos(rot_speed);
	vars->plane_x = vars->plane_x * cos(rot_speed)
		- vars->plane_y * sin(rot_speed);
	vars->plane_y = old_plane_x * sin(rot_speed)
		+ vars->plane_y * cos(rot_speed);
}

void	rotate_left(t_vars *vars, double rot_speed)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = vars->dir_x;
	old_plane_x = vars->plane_x;
	vars->dir_x = vars->dir_x * cos(-rot_speed) - vars->dir_y * sin(-rot_speed);
	vars->dir_y = old_dir_x * sin(-rot_speed) + vars->dir_y * cos(-rot_speed);
	vars->plane_x = vars->plane_x * cos(-rot_speed)
		- vars->plane_y * sin(-rot_speed);
	vars->plane_y = old_plane_x * sin(-rot_speed)
		+ vars->plane_y * cos(-rot_speed);
}
