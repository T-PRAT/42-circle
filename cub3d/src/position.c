/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tprat <tprat@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 18:47:52 by tprat             #+#    #+#             */
/*   Updated: 2020/10/23 01:11:45 by tprat            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

t_map	*get_pos(t_map *map)
{
	int		i;
	int		x;
	int		y;

	i = 0;
	map->x = 0;
	map->y = 0;
	while (!(ft_strchr("EWSN", map->map[i])))
	{
		if (map->map[i] == '\n')
			map->y++;
		i++;
	}
	while (map->map[i--] != '\n')
		map->x++;
	map->x--;
	map->y++;
	return (map);
}