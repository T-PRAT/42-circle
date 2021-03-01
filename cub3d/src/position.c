/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tprat <tprat@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 18:47:52 by tprat             #+#    #+#             */
/*   Updated: 2021/01/12 15:49:37 by tprat            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

t_map	*get_pos(t_map *map)
{
	int		i;
	int		x;
	int		y;

	i = 0;
	map->pos_x = 0;
	map->pos_y = 0;
	while (!(ft_strchr("EWSN", map->map[i])))
	{
		if (map->map[i] == '\n')
			map->pos_y++;
		i++;
	}
	while (map->map[i--] != '\n')
		map->pos_x++;
	map->pos_x--;
	map->pos_y++;
	return (map);
}