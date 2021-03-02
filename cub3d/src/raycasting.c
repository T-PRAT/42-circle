/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tprat <tprat@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 00:28:07 by tprat             #+#    #+#             */
/*   Updated: 2021/03/02 15:21:58 by tprat            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	*raycasting(t_map *map, t_loop *loop)
{
	void	*frame;
	int		a;
	int		b;

	a = 0;
	b = 0;
	while (a < map->res_w)
	{
		while (b < map->res_h)
		{
			//check_pixel(map, a, b);
			b++;
		}
		a++;
	}
	return (frame);
}