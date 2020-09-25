/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tprat <tprat@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 18:32:52 by tprat             #+#    #+#             */
/*   Updated: 2020/09/25 03:08:10 by tprat            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	deal_key(int key, t_loop *loop)
{
	ft_putnbr_fd(key, 1);
	if (key == 65307)
	{
		mlx_destroy_window(loop->mlx, loop->win);
		return (0);
	}
}

int print_img(t_loop *loop)
{
    void    *img;
    char    *murnoir_path = "./img/img.xpm";
    int     img_width = 160;
    int     img_height = 160;
    char    *memimg;
    int     bpp = 32;
    int     sline = 640;
    int     endian = 0;

    img = mlx_xpm_file_to_image(loop->mlx, murnoir_path, &img_width, &img_height);
	mlx_put_image_to_window(loop->mlx, loop->win, img, 0, 0);
}

int	loop(t_map *map)
{
    t_loop	*loop;

	if(!(loop = malloc(sizeof(t_loop))))
		return (0);
    loop->mlx = mlx_init();
	loop->win = mlx_new_window(loop->mlx, map->res_w, map->res_h, "CUB3D");
	print_img(loop);
	mlx_key_hook(loop->win, deal_key, (void *)0);
	mlx_loop(loop->mlx);
}