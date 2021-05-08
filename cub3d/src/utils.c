/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tprat <tprat@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 14:43:32 by tprat             #+#    #+#             */
/*   Updated: 2021/05/07 16:26:09 by tprat            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	is_wall(int x, int y, t_rcs *rcs)
{
	int	i;
	int	c;

	i = 0;
	c = 0;
	while (rcs->map[i])
		i++;
	i--;
	while (c < y && i)
	{
		if (rcs->map[i] == '\n')
			c++;
		i--;
	}
	while (rcs->map[i - 1] != '\n' && i - 1 > 0)
		i--;
	if (rcs->map[i + x] == '2')
		return (2);
	if (rcs->map[i + x] != '1')
		return (1);
	return (0);
}

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	insert_pixel(t_data *data, int	x, int y, int color)
{
	char	*dst;

	dst = data->img_adr + (y * data->line_s + x * (data->bpp / 8));
	*(unsigned int *)dst = color;
}

int	get_pixel(t_tex *text, int x, int y)
{
	int	color;
	int	*dest;

	dest = text->addr + (y * text->line_s / 4 + x);
	color = *(unsigned int *)dest;
	return (color);
}

void	ft_error(char *str)
{
	ft_putstr_fd(str, 2);
	exit(EXIT_FAILURE);
}
