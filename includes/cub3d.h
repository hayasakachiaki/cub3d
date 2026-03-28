/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumedai <sumedai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 17:00:11 by mawako            #+#    #+#             */
/*   Updated: 2025/09/29 15:35:45 by mawako           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <math.h>
# include <stdlib.h>
# include <mlx.h>
# include <fcntl.h>
# include <unistd.h>
# include <sys/time.h>
# include "../libft/libft.h"

# define SCREENWIDTH 640
# define SCREENHEIGHT 480
# define MAPWIDTH 60
# define MAPHEIGHT 60

typedef struct s_ray	t_ray;

typedef struct s_keys
{
	int	up;
	int	down;
	int	left;
	int	right;
	int	rot_left;
	int	rot_right;
}	t_keys;

typedef struct s_tex
{
	int		dir_id;
	void	*wall_img;
	char	*tex_addr;
	int		tex_width;
	int		tex_height;
	int		tex_bpp;
	int		tex_line_len;
	int		tex_endian;
}	t_tex;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	void	*wall_img;
	char	*tex_addr;
	int		bpp;
	int		line_len;
	int		endian;
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	int		world_map[MAPHEIGHT][MAPWIDTH];
	t_keys	keys;
	long	last_time;
	double	delta_time;
	t_tex	tex[4];
	int		ceiling_color;
	int		floor_color;
}	t_vars;

typedef struct s_bounds
{
	int		h;
	int		start;
	int		end;
	double	cut_top;
}	t_bounds;

typedef struct s_col
{
	int		x;
	int		tx;
	double	step;
	double	tpos;
}	t_col;

typedef struct s_stripe
{
	t_bounds	b;
	t_tex		*t;
	t_col		c;
}	t_stripe;

typedef struct s_bounds_i
{
	int	l;
	int	r;
}	t_bounds_i;

typedef struct s_mapread
{
	int			rows;
	int			pcnt;
	int			last_w;
	int			first;
	char		*prev;
	t_bounds_i	b;
}	t_mapread;

typedef struct s_scan
{
	const char	*cur;
	const char	*prev;
	t_bounds_i	cb;
	t_bounds_i	pb;
	int			row;
}	t_scan;

typedef struct s_fc
{
	int		fset;
	int		cset;
	char	**carry;
}	t_fc;

void	my_pixel_put(t_vars *vars, int x, int y, int color);
void	draw_background(t_vars *vars);
void	draw_walls(t_vars *vars);
void	set_player_start(t_vars *vars, char c, int x, int y);
void	move_forward(t_vars *vars, double move_speed);
void	move_backward(t_vars *vars, double move_speed);
void	move_left(t_vars *vars, double move_speed);
void	move_right(t_vars *vars, double move_speed);
void	rotate_right(t_vars *vars, double rot_speed);
void	rotate_left(t_vars *vars, double rot_speed);
int		render(t_vars *vars);
int		key_press(int keycode, t_vars *vars);
int		key_release(int keycode, t_vars *vars);
void	destory_textures(t_vars *vars);
int		load_map(t_vars *vars, const char *path);
int		create_trgb(char *line);
char	*texture_path(char *line);
int		read_map_rows(t_vars *v, int fd, char **line);
int		is_dirction(char *line, int *i, char **key);
int		is_map_line(const char *s);
void	parse_map_line(t_vars *v, char *line, int row);
double	get_wall_x(t_vars *v, t_ray *r, double dist);
int		get_tex_x(t_ray *r, t_tex *t, double wallx);
int		row_only_walls(const char *s);
int		left_right_closed(const char *s);
int		count_players_in_row(const char *s);
long	get_time_in_ms(void);
void	update_delta_time(t_vars *vars);
int		load_texture(t_vars *v, int fd, char **carry);
int		load_ceiling_floor(t_vars *v, int fd, char **carry);
int		get_color(const char *line);
int		check_row_enclosure(const char *s, int l, int r, int *code);
int		bounds_first_row(const char *s, int *l, int *r);
int		bounds_check_row(const char *s, int l, int r);
int		check_row_edges(const char *s, int *li, int *ri);
int		side_hole(const char *row, int i);
int		down_exposed(const char *prev, t_bounds_i *pb,
			const char *cur, t_bounds_i *cb);
int		skip_to_map(int fd, char **line);
int		final_checks(t_mapread *st);
int		consume_row(t_vars *v, char **line, t_mapread *st);
int		validate_first(const char *line, t_bounds_i *b, int *pcnt);
int		validate_middle(const char *cur, t_mapread *st, int row_idx);
void	destroy_textures(t_vars *v);
void	x_cleanup(t_vars *v);
int		apply_floor_color(t_vars *v, char *p, t_fc *st, char *line);
int		apply_ceiling_color(t_vars *v, char *p, t_fc *st, char *line);

#endif
