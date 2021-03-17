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
	int		c;

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
			c = ft_color_texture(&all->txt.East, all->txt.tex_x, all->txt.tex_y);
		else if (all->ray.side == 2)
			c = ft_color_texture(&all->txt.South, all->txt.tex_x, all->txt.tex_y);
		else if (all->ray.side == 3)
			c = ft_color_texture(&all->txt.North, all->txt.tex_x, all->txt.tex_y);
		else if (all->ray.side == 4)
			c = ft_color_texture(&all->txt.West, all->txt.tex_x, all->txt.tex_y);
		my_mlx_pixel_put(&all->data, x, all->ray.drawStart++, c);
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

void			ft_render_sprite(t_all *all, float *dist)
{
	int			clr;

	while (all->sprt.stripe < all->sprt.end_x)
	{
		all->sprt.tex_x = (int)((all->sprt.stripe + all->sprt.sp_width / 2 - all->sprt.sp_screenX) * all->txt.Sprite.w / all->sprt.sp_width);
		if (all->sprt.transY > 0 && all->sprt.transY < dist[all->sprt.stripe])
		{
			all->sprt.y = all->sprt.start_y;
			while (all->sprt.y < all->sprt.end_y)
			{
				all->sprt.d = 128 * (all->sprt.y * 2 - all->vars.h + all->sprt.sp_hight);
				all->sprt.tex_y = all->sprt.d * all->txt.Sprite.h / all->sprt.sp_hight / 256;
				clr = ft_color_texture(&all->txt.Sprite, all->sprt.tex_x, all->sprt.tex_y);
				if (clr)
					my_mlx_pixel_put(&all->data, all->sprt.stripe, (int)all->sprt.y, clr);
				all->sprt.y += 1;
			}
		}
		(all->sprt.stripe)++;
	}
}
