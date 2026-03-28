/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mawako <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 17:39:20 by mawako            #+#    #+#             */
/*   Updated: 2025/09/29 13:00:00 by mawako           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H
# include "cub3d.h"

typedef struct s_ray
{
	double	camera_x;
	double	ray_dir_x;
	double	ray_dir_y;
	int		map_x;
	int		map_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	int		step_x;
	int		step_y;
	int		hit;
	int		side;
}	t_ray;

void	init_ray(t_vars *vars, int x, t_ray *ray);
void	perform_dda(t_vars *vars, t_ray *ray);
double	compute_perp_dist(t_vars *vars, t_ray *ray);
void	cast_single_ray(t_vars *vars, int x);
void	draw_stripe(t_vars *v, int x, t_ray *r);

#endif
