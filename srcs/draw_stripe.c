/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_stripe.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mawako <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 19:37:42 by mawako            #+#    #+#             */
/*   Updated: 2025/09/29 12:58:31 by mawako           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "ray.h"

static void	calc_bounds_ex(double dist, t_bounds *b)
{
	int	sh;
	int	h;
	int	s0;
	int	e0;

	sh = SCREENHEIGHT;
	h = (int)(sh / dist);
	s0 = -h / 2 + sh / 2;
	e0 = s0 + h - 1;
	b->start = s0;
	if (b->start < 0)
		b->start = 0;
	b->end = e0;
	if (b->end >= sh)
		b->end = sh - 1;
	b->h = h;
	b->cut_top = (double)(b->start - s0);
}

static t_tex	*choose_tex(t_vars *v, t_ray *ray)
{
	if (ray->side == 0)
	{
		if (ray->ray_dir_x > 0)
			return (&v->tex[3]);
		return (&v->tex[2]);
	}
	if (ray->ray_dir_y > 0)
		return (&v->tex[1]);
	return (&v->tex[0]);
}

static void	draw_tex_column(t_vars *v, t_tex *t, t_bounds *b, t_col *c)
{
	int		y;
	int		ty;
	char	*src;
	int		color;

	y = b->start;
	while (y <= b->end)
	{
		ty = (int)c->tpos;
		if (ty < 0)
			ty = 0;
		if (ty >= t->tex_height)
			ty = t->tex_height - 1;
		src = t->tex_addr + ty * t->tex_line_len + c->tx * (t->tex_bpp / 8);
		color = *(int *)src;
		my_pixel_put(v, c->x, y, color);
		c->tpos += c->step;
		y++;
	}
}

static int	prep_stripe(t_vars *v, int x, t_ray *r, t_stripe *s)
{
	double	dist;
	double	wallx;
	int		tex_x;
	int		draw_len;

	dist = compute_perp_dist(v, r);
	calc_bounds_ex(dist, &s->b);
	s->t = choose_tex(v, r);
	wallx = get_wall_x(v, r, dist);
	tex_x = get_tex_x(r, s->t, wallx);
	s->c.x = x;
	s->c.tx = tex_x;
	draw_len = s->b.end - s->b.start + 1;
	if (draw_len <= 0)
		return (-1);
	s->c.step = (double)s->t->tex_height / (double)s->b.h;
	s->c.tpos = s->b.cut_top * s->c.step;
	return (0);
}

void	draw_stripe(t_vars *v, int x, t_ray *r)
{
	t_stripe	s;

	if (prep_stripe(v, x, r, &s) < 0)
		return ;
	draw_tex_column(v, s.t, &s.b, &s.c);
}
