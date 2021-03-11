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

typedef struct		s_data
{
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
}					t_data;

typedef struct  s_vars {
    void        *mlx;
    void        *win;
	t_map		map;
	t_data		img;
}               t_vars;

			/************ Colors ************/

int				create_trgb(int t, int r, int g, int b);
int				get_t(int trgb);
int				get_r(int trgb);
int				get_g(int trgb);
int				get_b(int trgb);
int				create_negative(int trgb);

			/************ Parser ************/

int			ft_parse(t_vars *vars, int ac, char **av);

			/************ Render ************/

void			my_mlx_pixel_put(t_data *data, int x, int y, int color);

			/************ Errors ************/

int				ft_error(char *err, t_vars *vars);
