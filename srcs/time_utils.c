/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mawako <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 13:42:29 by mawako            #+#    #+#             */
/*   Updated: 2025/08/28 13:55:45 by mawako           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

long	get_time_in_ms(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

void	update_delta_time(t_vars *vars)
{
	long	current_time;

	current_time = get_time_in_ms();
	vars->delta_time = (current_time - vars->last_time) / 1000.0;
	vars->last_time = current_time;
}
