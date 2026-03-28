/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shuu <shuu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 17:29:54 by mawako            #+#    #+#             */
/*   Updated: 2025/09/17 18:47:40 by shuu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "ray.h"

void	my_pixel_put(t_vars *vars, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= SCREENWIDTH || y < 0 || y >= SCREENHEIGHT)
		return ;
	dst = vars->addr + (y * vars->line_len + x * (vars->bpp / 8));
	*(unsigned int *)dst = color;
}

void	draw_background(t_vars *vars)
{
	int	x;
	int	y;

	y = 0;
	while (y < SCREENHEIGHT)
	{
		x = 0;
		while (x < SCREENWIDTH)
		{
			if (y < SCREENHEIGHT / 2)
				my_pixel_put(vars, x, y, vars->ceiling_color);
			else
				my_pixel_put(vars, x, y, vars->floor_color);
			x++;
		}
		y++;
	}
}

void	draw_walls(t_vars *vars)
{
	int	x;

	x = 0;
	while (x < SCREENWIDTH)
	{
		cast_single_ray(vars, x);
		x++;
	}
}
