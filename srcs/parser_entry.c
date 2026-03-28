/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_entry.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mawako <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 12:32:24 by mawako            #+#    #+#             */
/*   Updated: 2025/09/29 12:43:57 by mawako           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	drain_rest(int fd, char **carry)
{
	char	*tmp;

	if (*carry)
	{
		tmp = *carry;
		while (tmp)
		{
			free(tmp);
			*carry = get_next_line(fd);
			tmp = *carry;
		}
	}
	tmp = get_next_line(fd);
	while (tmp)
	{
		free(tmp);
		tmp = get_next_line(fd);
	}
}

static int	open_map_fd(const char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		perror("open");
		return (-1);
	}
	return (fd);
}

static int	load_sections(t_vars *v, int fd, char **carry)
{
	if (load_texture(v, fd, carry) < 0)
		return (-1);
	if (load_ceiling_floor(v, fd, carry) < 0)
		return (-1);
	return (0);
}

static int	finish_and_check(int fd, char **carry, int rows)
{
	drain_rest(fd, carry);
	close(fd);
	if (rows < 0)
		return (-1);
	if (rows == 0)
	{
		ft_printf("Error: empty map\n");
		return (-1);
	}
	return (0);
}

int	load_map(t_vars *v, const char *path)
{
	char	*carry;
	int		fd;
	int		rows;

	carry = NULL;
	fd = open_map_fd(path);
	if (fd < 0)
		return (-1);
	if (load_sections(v, fd, &carry) < 0)
	{
		if (carry)
			free(carry);
		close(fd);
		return (-1);
	}
	rows = read_map_rows(v, fd, &carry);
	return (finish_and_check(fd, &carry, rows));
}
