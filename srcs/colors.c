/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjani <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 14:56:17 by cjani             #+#    #+#             */
/*   Updated: 2021/03/10 14:56:20 by cjani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/include.h"

int			ft_color(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void		ft_color_floor(t_vars *vars, t_data *data, t_map *map)
{
	int		i;
	int		j;
	int		height;
	int		width;

	i = -1;
	height = vars->h/2;
	width = vars->w;
	while (++i < height)
	{
		j = -1;
		while (++j < width)
			my_mlx_pixel_put(data, j, i, map->f_color);
	}
}

void		ft_color_ceilling(t_vars *vars, t_data *data, t_map *map)
{
	int		height;
	int		width;

	height = vars->h/2 - 1;
	while (++height < vars->h)
	{
		width = -1;
		while (++width < vars->w)
			my_mlx_pixel_put(data, width, height, map->f_color);
	}
}