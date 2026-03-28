/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_texture.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mawako <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 12:31:03 by mawako            #+#    #+#             */
/*   Updated: 2025/09/29 13:02:56 by mawako           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	set_tex_image(t_vars *v, int id, char *path)
{
	v->tex[id].dir_id = id;
	v->tex[id].wall_img = mlx_xpm_file_to_image(
			v->mlx, path, &v->tex[id].tex_width, &v->tex[id].tex_height);
	if (!v->tex[id].wall_img)
		return (-1);
	v->tex[id].tex_addr = mlx_get_data_addr(
			v->tex[id].wall_img, &v->tex[id].tex_bpp,
			&v->tex[id].tex_line_len, &v->tex[id].tex_endian);
	return (0);
}

static int	load_one_texture(t_vars *v, char *line, int dir_id, char *key)
{
	char	*path;
	int		fd;

	line += ft_strlen(key);
	while (*line && (*line == '\t' || *line == ' '))
		line++;
	path = texture_path(line);
	if (!path)
		return (-1);
	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Error: texture not found: %s\n", path);
		free(path);
		return (-1);
	}
	close(fd);
	if (set_tex_image(v, dir_id, path) < 0)
	{
		free(path);
		return (-1);
	}
	free(path);
	return (0);
}

static int	tex_handle_line(t_vars *v, char *line, char **carry)
{
	char	*p;
	char	*key;
	int		dir_id;

	p = line;
	while (*p == ' ' || *p == '\t')
		p++;
	if (*p == '\0' || *p == '\n' || *p == '\r')
	{
		free(line);
		return (1);
	}
	if (is_dirction(p, &dir_id, &key))
	{
		if (load_one_texture(v, p, dir_id, key) < 0)
		{
			free(line);
			return (-1);
		}
		free(line);
		return (1);
	}
	*carry = line;
	return (0);
}

int	load_texture(t_vars *v, int fd, char **carry)
{
	char	*line;
	int		rc;

	line = get_next_line(fd);
	if (!line)
		return (-1);
	while (line)
	{
		rc = tex_handle_line(v, line, carry);
		if (rc <= 0)
		{
			if (rc < 0)
				return (-1);
			else
				return (0);
		}
		line = get_next_line(fd);
	}
	*carry = NULL;
	return (0);
}
