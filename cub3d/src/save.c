/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tprat <tprat@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 17:58:57 by tprat             #+#    #+#             */
/*   Updated: 2021/05/06 08:21:03 by tprat            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	print_header(int fd, t_rcs *rcs, t_data *data)
{
	int	tmp;

	write(fd, "BM", 2);
	tmp = 14 + 40 + 4 * rcs->res_h * rcs->res_w;
	write(fd, &tmp, 4);
	tmp = 0;
	write(fd, &tmp, 2);
	write(fd, &tmp, 2);
	tmp = 54;
	write(fd, &tmp, 4);
	tmp = 40;
	write(fd, &tmp, 4);
	write(fd, &rcs->res_w, 4);
	write(fd, &rcs->res_h, 4);
	tmp = 1;
	write(fd, &tmp, 2);
	write(fd, &data->bpp, 2);
	tmp = 0;
	write(fd, &tmp, 4);
	write(fd, &tmp, 4);
	write(fd, &tmp, 4);
	write(fd, &tmp, 4);
	write(fd, &tmp, 4);
	write(fd, &tmp, 4);
}

void	save_image(t_data *data, t_rcs *rcs)
{
	int	fd;
	int	x;
	int	y;

	y = rcs->res_h;
	raycasting(data);
	fd = open("cub3d.bmp", O_CREAT | O_RDWR);
	if (!fd)
		ft_error("Erreur lors de la création du .bmp\n");
	print_header(fd, rcs, data);
	while (y >= 0)
	{
		x = 0;
		while (x < rcs->res_w)
		{
			write(fd,
				&data->img_adr[y * data->line_s + x * (data->bpp / 8)], 4);
			x++;
		}
		y--;
	}
	close(fd);
	clean_exit(data);
}
