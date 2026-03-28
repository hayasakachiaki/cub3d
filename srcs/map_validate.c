/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mawako <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 09:37:21 by mawako            #+#    #+#             */
/*   Updated: 2025/09/29 13:01:55 by mawako           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	is_player(char c)
{
	if (c == 'N' || c == 'S')
		return (1);
	if (c == 'E' || c == 'W')
		return (1);
	return (0);
}

static int	is_space(char c)
{
	if (c == ' ' || c == '\t')
		return (1);
	return (0);
}

int	row_only_walls(const char *s)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != '\n' && s[i] != '\r')
	{
		if (s[i] != '1' && !is_space(s[i]))
			return (0);
		i++;
	}
	return (1);
}

int	count_players_in_row(const char *s)
{
	int	i;
	int	c;

	i = 0;
	c = 0;
	while (s[i] && s[i] != '\n' && s[i] != '\r')
	{
		if (is_player(s[i]))
			c++;
		i++;
	}
	return (c);
}
