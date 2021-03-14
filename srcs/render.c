/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjani <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 15:56:31 by cjani             #+#    #+#             */
/*   Updated: 2021/03/10 15:56:34 by cjani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/include.h"

void		my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void		ft_render_square(t_data *data, int x_scl, int y_scl, int color)
{
	int		i;
	int		j;

	i = y_scl - 1;
	while (++i < (y_scl + G_SCALE))
	{
		j = x_scl - 1;
		while (++j < x_scl + G_SCALE)
			my_mlx_pixel_put(data, j, i, color);
	}
}

int			ft_render_plr(t_all *all)
{
	ft_render_square(&all->data, all->plr.x, all->plr.y, ft_color(0, 0, 0, 255));
	return (0);
}

int			ft_render_map(t_all *all)
{
	int		i;
	int		j;

	i = -1;
	while (all->map.map[++i])
	{
		//ft_putendl_fd(all->map.map[i], 1);
		j = -1;
		while (all->map.map[i][++j] != '\0')
		{
			if (all->map.map[i][j] == '1')
				ft_render_square(&all->data, j * G_SCALE, i * G_SCALE, ft_color(0, 255, 255, 255));
		}
	}
	return (0);
}

int			ft_render(t_all *all)
{
	mlx_do_sync(all->vars.mlx);
	ft_color_ceilling(&all->vars, &all->data, &all->map);
	ft_color_floor(&all->vars, &all->data, &all->map);
	ft_render_map(all);
	ft_render_plr(all);
	mlx_put_image_to_window(all->vars.mlx, all->vars.win, all->data.img, 0, 0);
	return (0);
}