/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tprat <tprat@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 16:21:22 by tprat             #+#    #+#             */
/*   Updated: 2021/05/05 15:29:05 by tprat            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

t_map *get_line_info2(t_map *map, char **parts)
{
	if (!(ft_strncmp(parts[0], "NO", 3)))
		map->texts[0].path = ft_strdup(parts[1]);
	else if (!(ft_strncmp(parts[0], "SO", 3)))
		map->texts[1].path = ft_strdup(parts[1]);
	else if (!(ft_strncmp(parts[0], "WE", 3)))
		map->texts[2].path = ft_strdup(parts[1]);
	else if (!(ft_strncmp(parts[0], "EA", 3)))
		map->texts[3].path = ft_strdup(parts[1]);
	else if (!(ft_strncmp(parts[0], "S", 2)))
		map->texts[4].path = ft_strdup(parts[1]);
	else if (!(ft_strncmp(parts[0], "F", 2)))
		map->color_f = get_color(parts[1]);
	else if (!(ft_strncmp(parts[0], "C", 2)))
		map->color_c = get_color(parts[1]);
	else
		return (0);
	return (map);
}

void free_2d_str(char **str)
{
	int i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

t_map *get_line_info(t_map *map, char *line)
{
	char **parts;
	int i;

	i = 0;
	parts = ft_split(line, ' ');
	while (parts[i] != 0)
		i++;
	if (i == 3)
	{
		if (parts[0][0] != 'R' || parts[0][1] != 0)
			return (0);
		map->res_w = ft_atoi(parts[1]);
		map->res_h = ft_atoi(parts[2]);
	}
	else if (i == 2)
	{
		if (!(map = get_line_info2(map, parts)))
			return (0);
	}
	else
		return (0);
	free_2d_str(parts);
	return (map);
}

t_map	*get_map(t_map *map, char *line, int fd)
{
	int c;
	char *tmp;

	c = 1;
	map->map = ft_strdup("");
	while (c)
	{
		tmp = map->map;
		map->map = ft_strjoin(map->map, line);
		map->map = ft_strjoin(map->map, "\n");
		free(tmp);
		c = get_next_line(fd, &line);
	}
	map->map = ft_strjoin(map->map, line);
	if (!(map->map = clean_map(map->map)))
		return (0);
	return (map);
}

t_map	*parse_map(t_map *map, char *map_path)
{
	int fd;
	char *line;
	int c;

	c = 1;
	fd = open(map_path, O_RDONLY);
	while (c)
	{
		c = get_next_line(fd, &line);
		if (line[0] && line[0] != '1')
			map = get_line_info(map, line);
		else if (line[0] == '1')
		{
			if (!(map = get_map(map, line, fd)))
				return (0);
			c = 0;
		}
	}
	return (map);
}
