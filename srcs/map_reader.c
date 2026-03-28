/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mawako <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 09:41:00 by mawako            #+#    #+#             */
/*   Updated: 2025/09/29 17:40:09 by mawako           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	cell_exposed(const char *cur, const char *prev,
			int i, t_bounds_i *pb)
{
	if (i < pb->l || i > pb->r)
		return (1);
	if (prev[i] == ' ' || prev[i] == '\t')
		return (1);
	if (prev[i] == '\0' || prev[i] == '\n' || prev[i] == '\r')
		return (1);
	(void)cur;
	return (0);
}

static int	scan_exposure(t_scan *s)
{
	int		i;
	char	c;

	i = s->cb.l;
	while (s->cur[i] && i <= s->cb.r && s->cur[i] != '\n' && s->cur[i] != '\r')
	{
		c = s->cur[i];
		if (c != '0' && c != '1' && c != 'N' && c != 'S'
			&& c != 'E' && c != 'W' && c != ' ' && c != '\t')
			return (ft_printf("Error: unknown map char '%c' (row %d, col %d)\n",
					c, s->row + 1, i + 1), -1);
		if (c == '0' || c == 'N' || c == 'S' || c == 'E' || c == 'W')
		{
			if (side_hole(s->cur, i))
				return (ft_printf("Error: map not closed by walls (row %d)\n",
						s->row + 1), -1);
			if (cell_exposed(s->cur, s->prev, i, &s->pb))
				return (ft_printf("Error: map not closed by walls (row %d)\n",
						s->row + 1), -1);
		}
		i++;
	}
	return (0);
}

int	validate_first(const char *line, t_bounds_i *b, int *pcnt)
{
	int	li;
	int	ri;

	if (bounds_first_row(line, &b->l, &b->r) < 0)
		return (ft_printf("Error: map should closed by walls\n"), -1);
	if (!row_only_walls(line))
		return (ft_printf("Error: map should closed by walls\n"), -1);
	if (check_row_edges(line, &li, &ri) < 0)
	{
		ft_printf("Error: map should closed by walls (row 1)\n");
		return (-1);
	}
	*pcnt += count_players_in_row(line);
	return (0);
}

int	validate_middle(const char *cur, t_mapread *st, int row_idx)
{
	t_scan	s;

	if (check_row_edges(cur, &s.cb.l, &s.cb.r) < 0)
		return (ft_printf("Error: map not closed by walls (row %d)\n",
				row_idx + 1), -1);
	s.cur = cur;
	s.prev = st->prev;
	if (check_row_edges(s.prev, &s.pb.l, &s.pb.r) < 0)
		return (ft_printf("Error: internal error: prev row invalid\n"), -1);
	s.row = row_idx;
	if (down_exposed(s.prev, &s.pb, s.cur, &s.cb))
		return (ft_printf("Error: map not closed by walls (row %d)\n",
				row_idx + 1), -1);
	if (scan_exposure(&s) < 0)
		return (-1);
	st->pcnt += count_players_in_row(cur);
	st->last_w = row_only_walls(cur);
	return (0);
}

int	read_map_rows(t_vars *v, int fd, char **line)
{
	t_mapread	st;
	int			rc;
	int			ok;

	ft_bzero(&st, sizeof(st));
	st.first = 1;
	ok = skip_to_map(fd, line);
	if (ok == 0)
		return (0);
	else if (ok < 0)
		return (-1);
	rc = 1;
	while (*line)
	{
		rc = consume_row(v, line, &st);
		if (rc <= 0)
			break ;
		*line = get_next_line(fd);
	}
	if (st.prev)
		free(st.prev);
	if (rc < 0)
		return (-1);
	return (final_checks(&st));
}
