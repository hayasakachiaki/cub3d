/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mawako <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 10:21:33 by mawako            #+#    #+#             */
/*   Updated: 2025/09/29 13:00:33 by mawako           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	destroy_textures(t_vars *v)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (v->tex[i].wall_img)
		{
			mlx_destroy_image(v->mlx, v->tex[i].wall_img);
			v->tex[i].wall_img = NULL;
		}
		i++;
	}
}

void	x_cleanup(t_vars *v)
{
	destroy_textures(v);
	if (v->img)
	{
		mlx_destroy_image(v->mlx, v->img);
		v->img = NULL;
	}
	if (v->win)
	{
		mlx_destroy_window(v->mlx, v->win);
		v->win = NULL;
	}
	if (v->mlx)
	{
		mlx_destroy_display(v->mlx);
		free(v->mlx);
		v->mlx = NULL;
	}
}
