/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_fc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mawako <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 12:31:22 by mawako            #+#    #+#             */
/*   Updated: 2025/09/29 13:02:36 by mawako           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	is_blank_or_eol(char c)
{
	if (c == ' ' || c == '\t' || c == '\0' || c == '\n' || c == '\r')
		return (1);
	return (0);
}

static int	fc_apply(t_vars *v, char *p, t_fc *st, char *line)
{
	if (*p == 'F')
		return (apply_floor_color(v, p, st, line));
	if (*p == 'C')
		return (apply_ceiling_color(v, p, st, line));
	return (0);
}

static char	*fc_first_line(int fd, char **carry)
{
	char	*line;

	if (*carry != NULL)
	{
		line = *carry;
		*carry = NULL;
		return (line);
	}
	return (get_next_line(fd));
}

static int	fc_line(t_vars *v, char *line, t_fc *st)
{
	char	*p;

	p = line;
	while (*p == ' ' || *p == '\t')
		p++;
	if (is_blank_or_eol(*p))
	{
		free(line);
		return (1);
	}
	if (*p == 'F' || *p == 'C')
		return (fc_apply(v, p, st, line));
	*(st->carry) = line;
	return (0);
}

int	load_ceiling_floor(t_vars *v, int fd, char **carry)
{
	t_fc	st;
	char	*line;
	int		rc;

	st.fset = 0;
	st.cset = 0;
	st.carry = carry;
	line = fc_first_line(fd, carry);
	if (!line)
		return (-1);
	while (line)
	{
		rc = fc_line(v, line, &st);
		if (rc <= 0)
			break ;
		line = get_next_line(fd);
	}
	if (!st.fset || !st.cset)
	{
		ft_printf("Error: missing F or C\n");
		return (-1);
	}
	return (0);
}
