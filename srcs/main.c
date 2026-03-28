/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumedai <sumedai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 17:00:14 by mawako            #+#    #+#             */
/*   Updated: 2025/09/29 11:49:22 by mawako           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_vars(t_vars *vars)
{
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, SCREENWIDTH, SCREENHEIGHT, "cub3d");
	vars->img = mlx_new_image(vars->mlx, SCREENWIDTH, SCREENHEIGHT);
	vars->addr = mlx_get_data_addr(vars->img, &vars->bpp, &vars->line_len,
			&vars->endian);
	vars->keys.up = 0;
	vars->keys.down = 0;
	vars->keys.left = 0;
	vars->keys.right = 0;
	vars->keys.rot_left = 0;
	vars->keys.rot_right = 0;
	vars->last_time = get_time_in_ms();
}

static void	clear_map_to_walls(t_vars *vars)
{
	int	x;
	int	y;

	y = 0;
	while (y < MAPHEIGHT)
	{
		x = 0;
		while (x < MAPWIDTH)
		{
			vars->world_map[y][x] = 1;
			x++;
		}
		y++;
	}
}

int	x_bottom(t_vars *vars)
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

static int	validate_cub(const char *path)
{
	size_t	len;

	if (!path)
		return (-1);
	len = ft_strlen(path);
	if (len < 4)
		return (-1);
	if (ft_strncmp(path + (len - 4), ".cub", 4) != 0)
		return (-1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_vars	vars;

	if (argc != 2)
	{
		ft_printf("Usage: %s map.cub\n", argv[0]);
		return (1);
	}
	if (validate_cub(argv[1]) < 0)
	{
		ft_printf("Error: file must end with .cub\n");
		return (1);
	}
	ft_bzero(&vars, sizeof(vars));
	init_vars(&vars);
	clear_map_to_walls(&vars);
	if (load_map(&vars, argv[1]) < 0)
	{
		x_cleanup(&vars);
		return (1);
	}
	mlx_loop_hook(vars.mlx, render, &vars);
	mlx_hook(vars.win, 17, 1L << 17, x_bottom, &vars);
	mlx_hook(vars.win, 2, 1L << 0, key_press, &vars);
	mlx_hook(vars.win, 3, 1L << 1, key_release, &vars);
	mlx_loop(vars.mlx);
}
