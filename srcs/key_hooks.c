/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumedai <sumedai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 17:03:00 by mawako            #+#    #+#             */
/*   Updated: 2025/09/28 22:44:48 by sumedai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	destory_textures(t_vars *vars)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (vars->tex[i].wall_img)
			mlx_destroy_image(vars->mlx, vars->tex[i].wall_img);
		i++;
	}
}

int	key_press(int keycode, t_vars *vars)
{
	if (keycode == 119 || keycode == 13)
		vars->keys.up = 1;
	if (keycode == 115 || keycode == 1)
		vars->keys.down = 1;
	if (keycode == 97 || keycode == 0)
		vars->keys.left = 1;
	if (keycode == 100 || keycode == 2)
		vars->keys.right = 1;
	if (keycode == 65361 || keycode == 123)
		vars->keys.rot_left = 1;
	if (keycode == 65363 || keycode == 124)
		vars->keys.rot_right = 1;
	if (keycode == 65307 || keycode == 53)
	{
		destory_textures(vars);
		if (vars->img)
			mlx_destroy_image(vars->mlx, vars->img);
		if (vars->win)
			mlx_destroy_window(vars->mlx, vars->win);
		if (vars->mlx)
			mlx_destroy_display(vars->mlx);
		free(vars->mlx);
		exit(0);
	}
	return (0);
}

int	key_release(int keycode, t_vars *vars)
{
	if (keycode == 119 || keycode == 13)
		vars->keys.up = 0;
	if (keycode == 115 || keycode == 1)
		vars->keys.down = 0;
	if (keycode == 97 || keycode == 0)
		vars->keys.left = 0;
	if (keycode == 100 || keycode == 2)
		vars->keys.right = 0;
	if (keycode == 65361 || keycode == 123)
		vars->keys.rot_left = 0;
	if (keycode == 65363 || keycode == 124)
		vars->keys.rot_right = 0;
	return (0);
}
