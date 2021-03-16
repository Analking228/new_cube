/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   include.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjani <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 13:26:03 by cjani             #+#    #+#             */
/*   Updated: 2021/03/10 13:26:05 by cjani            ###   ########.fr       */
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

# define G_SCALE 20
# define ESC	53
# define LEFT	123
# define RIGHT	124
# define W		13
# define D		2
# define S		1
# define A		0
# define FOV (M_PI / 3.f) 



			/*********** Structs ************/

typedef struct		s_map
{
	char			**map;
	int				f_color;
	int				c_color;
	int				plr_pos[2];
}					t_map;

typedef struct		s_player
{
	float				x;
	float				y;
	float				dir;
	float				left;
	float				right;
}					t_plr;


typedef struct		s_image
{
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
}					t_data;

typedef struct		s_mlx_variables
{
	void			*mlx;
	void			*win;
	int				w;
	int				h;
}					t_vars;

typedef struct		s_master
{
	t_vars			vars;
	t_map			map;
	t_data			data;
	t_plr			plr;
}					t_all;


			/************ Colors ************/

int				ft_color(int t, int r, int g, int b);
void			ft_color_floor(t_vars *vars, t_data *data, t_map *map);
void			ft_color_ceilling(t_vars *vars, t_data *data, t_map *map);

			/********* Preparations *********/

int			ft_preparing(t_all *all, int ac, char **av);

			/************ Parser ************/

int			ft_parser(t_all *all, int ac, char **av);

			/************ Render ************/

void			my_mlx_pixel_put(t_data *data, int x, int y, int color);
int				ft_render(t_all *all);
int				ft_render_map(t_all *all);

			/************ Errors ************/

int				ft_error(char *err, t_all *all);

			/*********** Controls ***********/

int			key_p(int keycode, t_all *all);

			/********** Raycasting **********/

void		ft_raycast(t_all *all);

#endif
