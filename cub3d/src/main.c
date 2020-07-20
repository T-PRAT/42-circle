#include "../include/cub3d.h"

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

int main()
{
    t_vars  *vars;

    vars = malloc(sizeof(t_vars));
    vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, 1280 ,1024, "LA FENETRE");
    print_img(vars);
    //mlx_key_hook(vars->win, key_press, vars);
	mlx_loop(vars->mlx);
    return (0);
}
