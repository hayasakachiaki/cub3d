/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_bounds.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mawako <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 09:48:47 by mawako            #+#    #+#             */
/*   Updated: 2025/09/29 15:25:52 by mawako           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	is_space(char c)
{
	if (c == ' ' || c == '\t')
		return (1);
	return (0);
}

int	bounds_first_row(const char *s, int *l, int *r)
{
	int	i;
	int	j;

	i = 0;
	while (s[i] && s[i] != '\n' && s[i] != '\r' && is_space(s[i]))
		i++;
	j = i;
	while (s[j] && s[j] != '\n' && s[j] != '\r')
		j++;
	j--;
	while (j >= i && is_space(s[j]))
		j--;
	if (j < i)
		return (-1);
	*l = i;
	*r = j;
	return (0);
}

int	check_row_edges(const char *s, int *li, int *ri)
{
	if (bounds_first_row(s, li, ri) < 0)
		return (-1);
	if (s[*li] != '1')
		return (-1);
	if (s[*ri] != '1')
		return (-1);
	return (0);
}

int	side_hole(const char *row, int i)
{
	if (i > 0)
	{
		if (row[i - 1] == ' ' || row[i - 1] == '\t'
			|| row[i - 1] == '\0' || row[i - 1] == '\n'
			|| row[i - 1] == '\r')
			return (1);
	}
	if (row[i + 1] == ' ' || row[i + 1] == '\t'
		|| row[i + 1] == '\0' || row[i + 1] == '\n'
		|| row[i + 1] == '\r')
		return (1);
	return (0);
}
