/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mawako <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 18:24:31 by mawako            #+#    #+#             */
/*   Updated: 2025/09/24 19:38:10 by mawako           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ray.h"

static void	set_delta_dist(t_ray *ray)
{
	if (ray->ray_dir_x == 0)
		ray->delta_dist_x = 1e30;
	else
		ray->delta_dist_x = fabs(1 / ray->ray_dir_x);
	if (ray->ray_dir_y == 0)
		ray->delta_dist_y = 1e30;
	else
		ray->delta_dist_y = fabs(1 / ray->ray_dir_y);
}

static void	set_step_and_side_dist(t_vars *vars, t_ray *ray)
{
	if (ray->ray_dir_x < 0)
	{
		ray->step_x = -1;
		ray->side_dist_x = (vars->pos_x - ray->map_x) * ray->delta_dist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist_x = (ray->map_x + 1.0 - vars->pos_x) * ray->delta_dist_x;
	}
	if (ray->ray_dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (vars->pos_y - ray->map_y) * ray->delta_dist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y = (ray->map_y + 1.0 - vars->pos_y) * ray->delta_dist_y;
	}
}

void	init_ray(t_vars *vars, int x, t_ray *ray)
{
	ray->camera_x = 2 * x / (double)SCREENWIDTH - 1;
	ray->ray_dir_x = vars->dir_x + vars->plane_x * ray->camera_x;
	ray->ray_dir_y = vars->dir_y + vars->plane_y * ray->camera_x;
	ray->map_x = (int)vars->pos_x;
	ray->map_y = (int)vars->pos_y;
	ray->hit = 0;
	set_delta_dist(ray);
	set_step_and_side_dist(vars, ray);
}
