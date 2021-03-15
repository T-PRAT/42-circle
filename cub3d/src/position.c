/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tprat <tprat@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 18:47:52 by tprat             #+#    #+#             */
/*   Updated: 2021/03/15 16:36:12 by tprat            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

t_map	*get_dir(t_map *map, char c)
{
	map->dir_x = 0;
	map->dir_y = 0;
	map->pla_x = 0;
	map->pla_y = 0;
	if (c == 'N')
	{
		map->dir_y = 1;
		map->pla_x = (double)POV / 100;
	}
	if (c == 'S')
	{
		map->dir_y = -1;
		map->pla_x = (double)(POV / 100) * -1;
	}
	if (c == 'E')
	{
		map->dir_x = 1;
		map->pla_y = (double)(POV / 100) * -1;
	}
	if (c == 'W')
	{
		map->dir_x = -1;
		map->pla_y = (double)POV / 100;
	}
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
	while (map->map[i - 1] != '\n' && i > 1)
	{
		map->pos_x++;
		i--;
	}
	map = get_dir(map, map->map[i]);
	return (map);
}