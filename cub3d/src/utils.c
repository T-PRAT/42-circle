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

int		create_trgb(int t, int r, int g, int b)
{
	return(t << 24 | r << 16 | g << 8 | b);
}

void	insert_pixel(t_data *data, int	x, int y, int color)
{
	char	*dst;

	dst = data->img_adr + (y * data->line_s + x * (data->bpp / 8));
	*(unsigned int*)dst = color;
}