/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tprat <tprat@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 18:32:52 by tprat             #+#    #+#             */
/*   Updated: 2021/03/04 11:42:58 by tprat            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int		close_wd(int keycode, t_loop *loop)
{
	mlx_destroy_window(loop->mlx, loop->win);
	return (0);
}

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
	return (0);
}

int		deal_key(int key, t_loop *loop)
{
	//ft_putnbr_fd(key, 1);
	if (key == 53)
	{
		mlx_destroy_window(loop->mlx, loop->win);
		exit (1);
		return (0);
	}
	return (0);
}

int		loop(t_map *map)
{
    t_loop	*loop;

	if(!(loop = malloc(sizeof(t_loop))))
		return (0);
    loop->mlx = mlx_init();
	loop->win = mlx_new_window(loop->mlx, map->res_w, map->res_h, "CUB3D");
	mlx_key_hook(loop->win, deal_key, loop);
	map = img_path_to_adr(map, loop->mlx);
	map = get_pos(map);
	//printf("pos:%f///%f", map->pos_x, map->pos_y);
	//printf("dir:%f///%f\n", map->dir_x, map->dir_y);
	//printf("pla:%f///%f\n", map->pla_x, map->pla_y);
	raycasting(map, loop);
	//create_image(loop, map);
	mlx_loop(loop->mlx);
	return (0);
}