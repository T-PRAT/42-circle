/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tprat <tprat@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 17:00:29 by user42            #+#    #+#             */
/*   Updated: 2021/07/04 20:22:35 by tprat            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../minilibx-linux/mlx.h"
# include <math.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdbool.h>
// A VIRER
# include <stdio.h>
# include "../libft/libft.h"

# define POV 80
# define MS 0.07
# define RS 0.05
# define ESC 33
# define FORWARD 119
# define BACKWARD 115
# define RIGHT 100
# define LEFT 97
# define ROT_RIGHT 65363
# define ROT_LEFT 65361

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

typedef struct s_spr
{
	int				order;
	int				spr_pos_x;
	int				spr_pos_y;
	double			perp_d;
	int				spr_h;
	int				spr_w;
	int				spr_t;
	int				start_x;
	int				end_x;
	int				start_y;
	int				end_y;
	double			trans_x;
	double			trans_y;
	struct s_spr	*next;

}				t_spr;

typedef struct s_rcs
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
	int		start;
	int		end;
	double	*perp_ds;
}				t_rcs;

typedef struct s_data
{
	t_rcs	*rcs;
	void	*mlx;
	void	*win;
	void	*img;
	char	*img_adr;
	int		bpp;
	int		line_s;
	int		endian;
}				t_data;

t_rcs			*parse_map(t_rcs *rcs, char *map_path);
void			clean_map(t_rcs *rcs);
int				get_color(char *str);
int				loop(t_rcs *rcs);
void			*create_image(t_data *data, t_rcs *rcs);
void			get_pos(t_rcs *rcs);
int				raycasting(t_data *data);
int				is_wall(int x, int y, t_rcs *rcs);
void			draw_line(t_rcs *rcs, t_data *data, int x);
void			insert_pixel(t_data *t_data, int	x, int y, int color);
int				get_pixel(t_tex *text, int x, int y);
int				create_trgb(int t, int r, int g, int b);
void			ft_error(char *str);
int				key_press(int keycode, t_data *data);
int				key_release(int keycode, t_key *key);
int				clean_exit(t_data	*data);
void			check_move(t_rcs *rcs);
void			select_sprite(t_rcs *rcs, t_data *data);
void			save_image(t_data *data, t_rcs *rcs);
t_rcs			*new_sprite_list(t_rcs *rcs);
int				check_sprite(t_rcs *rcs);

#endif
