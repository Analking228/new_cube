/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   include.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshanti <kshanti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 13:26:03 by cjani             #+#    #+#             */
/*   Updated: 2021/03/17 03:26:00 by kshanti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INCLUDE_CUBE_H
# define INCLUDE_CUBE_H
# include "../libs/libft/libft.h"
# include "../libs/mlx/mlx.h"
# include <fcntl.h>
# include <math.h>
# include <limits.h>
# include <stdio.h>
# include <errno.h>

# define G_SCALE 20
# define M_SCALE 5
# define ESC	53
# define LEFT	123
# define RIGHT	124
# define W		13
# define D		2
# define S		1
# define A		0




			/*********** Structs ************/

typedef struct		s_map
{
	char			**map;
	int				f_color;
	int				c_color;
}					t_map;

typedef struct		s_player
{
	float				pos_x;
	float				pos_y;
	float				dir_x;
	float				dir_y;
}					t_plr;


typedef struct		s_image
{
	void			*img;
	char			*addr;
	int				w;
	int				h;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
}					t_data;

typedef struct 		s_master_texture
{
	t_data			North;
	t_data			East;
	t_data			South;
	t_data			West;
	t_data			Sprite;
	int				tex_x;
	int				tex_y;
	float			wall_x;
	float			step;
	float			tex_pos;
}					t_textures;


typedef struct		s_mlx_variables
{
	void			*mlx;
	void			*win;
	int				w;
	int				h;
}					t_vars;

typedef struct		s_sprite_location
{
	float			x;
	float			y;
	float			dist;
}					t_sprt_loc;

typedef struct		s_sprite_variables
{
	float			x;
	float			y;
	float			inv;
	float			transX;
	float			transY;
	int				sp_screenX;
	int				sp_hight;
	int				sp_width;
	int				start_x;
	int				start_y;
	int				end_x;
	int				end_y;
	int				stripe;
	int				tex_x;
	int				tex_y;
	int				i;
	int				d;
}					t_sprite;

typedef struct		s_ray_variables
{
	float			left;
	float			right;
	float			cameraX;
	float			rayDirX;
	float			rayDirY;
	float			sideDistX;
	float			sideDistY;
	float			deltaDistX;
	float			deltaDistY;
	int				mapX;
	int				mapY;
	int				stepX;
	int				stepY;
	int				hit;
	int				side;
	float			perpWallDist;
	int				lineHeight;
	int				drawStart;
	int				drawEnd;
}					t_ray;

typedef struct		s_master
{
	t_vars			vars;
	t_map			map;
	t_data			data;
	t_textures		txt;
	t_plr			plr;
	t_ray			ray;
	t_sprite		sprt;
}					t_all;


			/************ Colors ************/

int				ft_color(int t, int r, int g, int b);
int				ft_color_txt(t_data *texture, int x, int y);

			/********* Preparations *********/

int				ft_preparing(t_all *all, int ac, char **av);

			/************ Parser ************/

int				ft_parser(t_all *all, int ac, char **av);
int				ft_parser_map_src(char *str);
void			ft_parser_resolution(char *res, t_list *list, t_all *all);
void			ft_parser_texture(char *res, t_list *list, t_all *all, char t);
void			ft_parser_color(char *res, t_list *list, t_all *all, char t);
int				ft_parser_plr_src_dir(t_all *all, int i, int j, char dir);

			/************ Render ************/

void			my_mlx_pixel_put(t_data *data, int x, int y, int color);
void			ft_render_coloumn(t_all *all, int x);
void			ft_render_sprite(t_all *all, float *dist);

			/************ Errors ************/

int				ft_error_abort(char *err, t_all *all, t_list *head);

			/*********** Controls ***********/

int				key_p(int keycode, t_all *all);

			/********** Raycasting **********/

void			ft_raycast(t_all *all);
void			ft_raycast_get_texture(t_all *all);
int				ft_texture_color(t_data *texture, int x, int y);

			/********** Validation **********/

void		ft_validator(t_all *all);
void		ft_validate_map(t_list *head, t_map *map, int last);

			/********** Screeeeeen **********/

void			ft_screen(t_all *all);
void			ft_sprite(t_all *all, float dist[]);
void			sort_sprite(t_sprt_loc *sp, int n);

#endif
