/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stripe_math.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mawako <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 12:53:50 by mawako            #+#    #+#             */
/*   Updated: 2025/09/29 12:53:56 by mawako           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "ray.h"

double	get_wall_x(t_vars *v, t_ray *r, double dist)
{
	double	wallx;

	if (r->side == 0)
		wallx = v->pos_y + dist * r->ray_dir_y;
	else
		wallx = v->pos_x + dist * r->ray_dir_x;
	wallx -= floor(wallx);
	return (wallx);
}

int	get_tex_x(t_ray *r, t_tex *t, double wallx)
{
	int	tx;

	tx = (int)(wallx * (double)t->tex_width);
	if (r->side == 0 && r->ray_dir_x > 0)
		tx = t->tex_width - tx - 1;
	else if (r->side == 1 && r->ray_dir_y < 0)
		tx = t->tex_width - tx - 1;
	return (tx);
}
