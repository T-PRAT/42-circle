/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tprat <tprat@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 18:32:52 by tprat             #+#    #+#             */
/*   Updated: 2021/01/05 16:09:38 by tprat            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

t_map	*img_path_to_adr(t_map *map, void *mlx)
{
	void	*img;
	int		size;
	int		bpp;
	int		endian;

	size = 512;
	bpp = 4;
	endian = 0;
	map->all_text = malloc(sizeof(map->all_text));
	img = mlx_xpm_file_to_image(mlx, map->text_N, &size, &size);
	map->all_text[0] = mlx_get_data_addr(img, &bpp, &size, &endian);
	img = mlx_xpm_file_to_image(mlx, map->text_S, &size, &size);
	map->all_text[1] = mlx_get_data_addr(img, &bpp, &size, &endian);
	img = mlx_xpm_file_to_image(mlx, map->text_E, &size, &size);
	map->all_text[2] = mlx_get_data_addr(img, &bpp, &size, &endian);
	img = mlx_xpm_file_to_image(mlx, map->text_W, &size, &size);
	map->all_text[3] = mlx_get_data_addr(img, &bpp, &size, &endian);
	map->all_text[4] = ft_strdup(0);
	return (map);
}

int 	print_img(t_loop *loop, int x)
{
	void	*img;
	char    *murnoir_path = "./img/img.xpm";
    int     img_width = 160;
    int     img_height = 160;

    img = mlx_xpm_file_to_image(loop->mlx, murnoir_path, &img_width, &img_height);
	mlx_put_image_to_window(loop->mlx, loop->win, img, x, x);
}

int		deal_key(int key, t_loop *loop)
{
	static int		x;

	if (!x)
		x = 0;
	printf("x:%d\n", x);
	ft_putnbr_fd(key, 1);
	if (key == 'a')
	{
		print_img(loop, x);
		x++;
	}
	if (key == 65307)
	{
		x++;
		mlx_destroy_window(loop->mlx, loop->win);
		return (0);
	}
	return (0);
}

int		loop(t_map *map)
{
    t_loop	*loop;
    void    *img;

	if(!(loop = malloc(sizeof(t_loop))))
		return (0);
    loop->mlx = mlx_init();
	loop->win = mlx_new_window(loop->mlx, map->res_w, map->res_h, "CUB3D");
	//mlx_key_hook(loop->win, deal_key, loop);
	map = img_path_to_adr(map, loop->mlx);
	map = get_pos(map);
	create_image(loop, map);
	mlx_loop(loop->mlx);
}