/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mawako <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 15:36:40 by mawako            #+#    #+#             */
/*   Updated: 2025/09/29 15:37:00 by mawako           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	down_exposed(const char *prev, t_bounds_i *pb,
			const char *cur, t_bounds_i *cb)
{
	int		i;
	char	c;

	i = pb->l;
	while (prev[i] && i <= pb->r && prev[i] != '\n' && prev[i] != '\r')
	{
		c = prev[i];
		if (c == '0' || c == 'N' || c == 'S' || c == 'E' || c == 'W')
		{
			if (i < cb->l || i > cb->r
				|| cur[i] == ' ' || cur[i] == '\t'
				|| cur[i] == '\0' || cur[i] == '\n' || cur[i] == '\r')
				return (1);
		}
		i++;
	}
	return (0);
}
