/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tprat <tprat@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 17:00:29 by user42            #+#    #+#             */
/*   Updated: 2021/05/05 17:06:00 by tprat            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../mlx/mlx.h"
# include <math.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdbool.h>
// A VIRER
# include <stdio.h>
# include "../libft/libft.h"

# define POV 60
# define MS 0.05
# define RS 0.03
# define ESC 53
# define FORWARD 13
# define BACKWARD 1
# define RIGHT 2
# define LEFT 0
# define ROT_RIGHT 124
# define ROT_LEFT 123

typedef struct s_tex
{
	char	*path;
	void	*img;
	int		*addr;
	int		bpp;
	int		line_s;
	int		endian;
	int		width;
	int		height;
}				t_tex;
typedef struct s_key
{
	bool	forward;
	bool	backward;
	bool	right;
	bool	left;
	bool	rot_right;
	bool	rot_left;
}				t_key;

typedef struct	t_spr
{
	int		spr_pos_x;
	int		spr_pos_y;
	int		spr_x;
	int		spr_y;
	double	perp_d;
}				t_spr;

typedef struct s_map
{
	bool	save;
	char	*map;
	int		res_w;
	int		res_h;
	t_tex	texts[5];
	int		color_f;
	int		color_c;
	t_key	*key;
	t_spr	*spr;
	double	dir_x;
	double	dir_y;
	double	pos_x;
	double	pos_y;
	double	pla_x;
	double	pla_y;
	double	ray_x;
	double	ray_y;
	double	cam_x;
	double	side_x;
	double	side_y;
	double	delta_x;
	double	delta_y;
	double	perp_d;
	int		step_x;
	int		step_y;
	int		map_x;
	int		map_y;
	char	side;
	double	wall_x;
	int		wall_h;
	int		text_x;
	int		text_y;
	double	*perp_ds;
}				t_map;

typedef struct	s_data
{
	t_map	*map;
	void	*mlx;
	void	*win;
	void	*img;
	char	*img_adr;
	int		bpp;
	int		line_s;
	int		endian;
}				t_data;

t_map			*parse_map(char *map_path);
char			*clean_map(char *map);
int				get_color(char *str);
int				loop(t_map *map);
void			*create_image(t_data *data, t_map *map);
t_map			*get_pos(t_map *map);
int				raycasting(t_data *data);
int				check_wall(int x, int y, t_map *map);
void			draw_line(t_map *map, t_data *data, int x);
void			insert_pixel(t_data *t_data, int	x, int y, int color);
int				get_pixel(t_tex *text, int x, int y);
int				create_trgb(int t, int r, int g, int b);
void			ft_error(char *str);
int				key_press(int keycode, t_data *data);
int				key_release(int keycode, t_key *key);
int				clean_exit(t_data	*data);
void			check_move(t_map *map);
t_map			*draw_sprite(t_map *map, t_data *data, int x);
void			save_image(t_data *data, t_map *map);

#endif
