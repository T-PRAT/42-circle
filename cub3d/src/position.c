/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tprat <tprat@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 18:47:52 by tprat             #+#    #+#             */
/*   Updated: 2021/03/02 16:24:44 by tprat            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

t_map	*get_dir(t_map *map, char c)
{

	map->dir_x = 0;
	map->dir_y = 0;
	if (c == 'N')
		map->dir_y = 1;
	if (c == 'S')
		map->dir_x = -1;
	if (c == 'E')
		map->dir_x = 1;
	if (c == 'W')
		map->dir_y = -1;
	return (map);
}

t_map	*get_pos(t_map *map)
{
	int		i;

	i = 0;
	map->pos_x = 0;
	map->pos_y = 0;
	while (map->map[++i]);
	i--;
	while (!(ft_strchr("EWSN", map->map[i])))
	{
		if (map->map[i] == '\n')
			map->pos_y++;
		i--;
	}
	map = get_dir(map, map->map[i]);
	while (map->map[i--] != '\n')
		map->pos_x++;
	map->pos_x--;
	map->pos_y++;
	return (map);
}