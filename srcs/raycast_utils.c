/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuu <shuu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 17:39:48 by mawako            #+#    #+#             */
/*   Updated: 2025/09/14 14:57:19 by shuu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3d.h"
#include "ray.h"

void	perform_dda(t_vars *vars, t_ray *ray)
{
	while (!ray->hit)
	{
		if (ray->side_dist_x < ray->side_dist_y)
		{
			ray->side_dist_x += ray->delta_dist_x;
			ray->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->side_dist_y += ray->delta_dist_y;
			ray->map_y += ray->step_y;
			ray->side = 1;
		}
		if (ray->map_x < 0 || ray->map_x >= MAPWIDTH
			|| ray->map_y < 0 || ray->map_y >= MAPHEIGHT)
		{
			ray->hit = 1;
			break ;
		}
		if (vars->world_map[ray->map_y][ray->map_x] > 0)
			ray->hit = 1;
	}
}

double	compute_perp_dist(t_vars *vars, t_ray *ray)
{
	double	d;

	if (ray->side == 0)
		d = (ray->map_x - vars->pos_x + (1 - ray->step_x) * 0.5)
			/ ray->ray_dir_x;
	else
		d = (ray->map_y - vars->pos_y + (1 - ray->step_y) * 0.5)
			/ ray->ray_dir_y;
	if (d < 1e-4)
		d = 1e-4;
	return (d);
}

void	cast_single_ray(t_vars *vars, int x)
{
	t_ray	ray;

	init_ray(vars, x, &ray);
	perform_dda(vars, &ray);
	draw_stripe(vars, x, &ray);
}
