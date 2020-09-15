/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tprat <tprat@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 16:21:22 by tprat             #+#    #+#             */
/*   Updated: 2020/09/15 17:52:17 by tprat            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

t_map	*get_line_info2(t_map *map, char **parts)
{
	if (parts[0] == "NO")
		map->text_N = ft_strdup(parts[1]);
}

t_map	*get_line_info(t_map *map, char *line)
{
	char	**parts;
	int		i;

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
	if (i == 2)
	{
		map = get_line_info2(map, parts);
	}
	printf("width:%d\nheight:%d\ntext_N:%s\n", map->res_w, map->res_h, map->text_N);
}

t_map	*parse_map(char *map_path)
{
	t_map	*map;
	int		fd;
	char	*line;
	int		c;

	c = 1;
	fd = open(map_path, O_RDONLY);
	if (!(map = (t_map *)malloc(sizeof(t_map))))
		return (0);
	while (c)
	{
		c = get_next_line(fd, &line);
		printf("%s\n", line);
		map = get_line_info(map, line);
	}
}