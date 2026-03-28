/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_trgb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mawako <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 18:30:01 by mawako            #+#    #+#             */
/*   Updated: 2025/09/29 18:33:36 by mawako           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	is_digits(const char *s, int len)
{
	int	i;

	i = 0;
	if (len <= 0)
		return (0);
	while (i < len)
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

static void	skip_spaces(char **p)
{
	while (**p == ' ' || **p == '\t')
		(*p)++;
}

static int	tok_len(const char *p)
{
	int	len;

	len = 0;
	while (p[len] && p[len] != ',' && p[len] != ' '
		&& p[len] != '\t' && p[len] != '\n' && p[len] != '\r')
		len++;
	return (len);
}

static int	parse_comp(char **pp, int *out)
{
	int	len;
	int	val;

	skip_spaces(pp);
	len = tok_len(*pp);
	if (len <= 0 || len > 3 || !is_digits(*pp, len))
		return (-1);
	val = ft_atoi(*pp);
	if (val < 0 || val > 255)
		return (-1);
	*out = val;
	*pp += len;
	skip_spaces(pp);
	return (0);
}

int	create_trgb(char *line)
{
	char	*p;
	int		r;
	int		g;
	int		b;

	p = line;
	skip_spaces(&p);
	if (parse_comp(&p, &r) < 0)
		return (-1);
	if (*p != ',')
		return (-1);
	p++;
	if (parse_comp(&p, &g) < 0)
		return (-1);
	if (*p != ',')
		return (-1);
	p++;
	if (parse_comp(&p, &b) < 0)
		return (-1);
	skip_spaces(&p);
	if (*p && *p != '\n' && *p != '\r')
		return (-1);
	return ((0 << 24) | (r << 16) | (g << 8) | b);
}
