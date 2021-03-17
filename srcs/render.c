/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshanti <kshanti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 15:56:31 by cjani             #+#    #+#             */
/*   Updated: 2021/03/17 02:07:03 by kshanti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/include.h"

void		my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

static void		ft_get_texture(t_all *all, int x)
{
	int		color;

	while (all->ray.drawStart <= all->ray.drawEnd)
	{
		if (all->ray.side == 1)
			all->txt.tex_y = (int)all->txt.tex_pos & (all->txt.East.h - 1);
		else if (all->ray.side == 2)
			all->txt.tex_y = (int)all->txt.tex_pos & (all->txt.South.h - 1);
		else if (all->ray.side == 3)
			all->txt.tex_y = (int)all->txt.tex_pos & (all->txt.North.h - 1);
		else if (all->ray.side == 4)
			all->txt.tex_y = (int)all->txt.tex_pos & (all->txt.West.h - 1);
		all->txt.tex_pos += all->txt.step;
		if (all->ray.side == 1)
			color = color_ea(all, all->txt.tex_x, all->txt.tex_y);
		else if (all->ray.side == 2)
			color = color_so(all, all->txt.tex_x, all->txt.tex_y);
		else if (all->ray.side == 3)
			color = color_no(all, all->txt.tex_x, all->txt.tex_y);
		else if (all->ray.side == 4)
			color = color_we(all, all->txt.tex_x, all->txt.tex_y);
		my_mlx_pixel_put(&all->data, x, all->ray.drawStart++, color);
	}
}

void		ft_render_coloumn(t_all *all, int x)
{
	int		color;
	int		i;

	i = -1;
	while (++i < all->ray.drawStart)
		my_mlx_pixel_put(&all->data, x, i, all->map.c_color);
	ft_get_texture(all, x);
	i = all->ray.drawEnd;
	while (++i < all->vars.h)
		my_mlx_pixel_put(&all->data, x, i, all->map.f_color);
}