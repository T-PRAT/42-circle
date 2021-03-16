/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tprat <tprat@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 14:43:32 by tprat             #+#    #+#             */
/*   Updated: 2021/03/16 15:16:31 by tprat            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

char	*draw_pixel(char *img_addr, int	x, int y, char *color)
{
	int i;
	char	color_1;
	char	color_2;
	char	color_3;

	i = 0;
	color_1 = ft_atoi(color);
	while (color[i++] != "," && color[i]);
	color_1 = ft_atoi(color + i);
	while (color[i++] != "," && color[i]);
	color_1 = ft_atoi(color + i);
	img_addr[x * y ] = color_1;
	img_addr[x * y + 1] = color_2;
	img_addr[x * y + 2] = color_3;
	return (img_addr);
}