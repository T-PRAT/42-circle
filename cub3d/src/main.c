/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tprat <tprat@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 17:20:47 by tprat             #+#    #+#             */
/*   Updated: 2021/03/03 11:51:52 by tprat            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"
/*
int print_img(t_vars *vars)
{
    void    *img;
    char    *murnoir_path = "./img/img.xpm";
    int     img_width = 160;
    int     img_height = 160;
    char    *memimg;
    int     bpp = 32;
    int     sline = 640;
    int     endian = 0;

    img = mlx_xpm_file_to_image(vars->mlx, murnoir_path, &img_width, &img_height);
    memimg = mlx_get_data_addr(img, &bpp, &sline, &endian);
    write(1, memimg, 20);
	mlx_put_image_to_window(vars->mlx, vars->win, img, 0, 0);
    ft_memcpy(memimg, "\0\0\0\0\0\0\0\0\0", 9);
    write(1, memimg, 20);
	mlx_put_image_to_window(vars->mlx, vars->win, img, 0, 0);
}
*/
int main(int ac, char **av)
{
    t_map   *map;

    if (ac != 2)
    {
        ft_putstr_fd("to many arguments", 2);
        return (0);
    }
    if (!(map = parse_map(av[1])))
        ft_putstr_fd("Error\n", 2);
    else
    {
	    printf("width:%d\nheight:%d\ntext_N:%s\ntext_S:%s\ntext_W:%s\ntext_E:%s\nsprite:%s\ncolor_f:%s\ncorlor_c:%s\nmap:\n>>>%s<<<\n", map->res_w, map->res_h, map->text_N, map->text_S, map->text_W, map->text_E, map->sprite, map->color_f, map->color_c, map->map);
        if (!(loop(map)))
            return (0);
    }
    return (0);
}
