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

#include "../libs/libft/libft.h"
#include "../libs/mlx/mlx.h"
#include <fcntl.h>


			/*********** Structs ************/

typedef struct		s_map
{
	char			**map;
	int				plr_pos[2];
}					t_map;

typedef struct		s_player
{
	double				x;
	double				y;
}					t_plr;


typedef struct		s_data
{
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
}					t_data;

typedef struct		s_vars
{
	void			*mlx;
	void			*win;
	int				w;
	int				h;
}					t_vars;

typedef struct		s_all
{
	t_vars			vars;
	t_map			map;
	t_data			data;
}					t_all;


			/************ Colors ************/

int				create_trgb(int t, int r, int g, int b);
int				get_t(int trgb);
int				get_r(int trgb);
int				get_g(int trgb);
int				get_b(int trgb);
int				create_negative(int trgb);

			/********* Preparations *********/

int			ft_preparing(t_all *all, int ac, char **av);

			/************ Parser ************/

int			ft_parsing(t_all *all, int ac, char **av);

			/************ Render ************/

void			my_mlx_pixel_put(t_data *data, int x, int y, int color);

			/************ Errors ************/

int				ft_error(char *err, t_all *all);
