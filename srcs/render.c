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

void		ft_render_square(t_data *data, int x, int y)
{
	int		i;
	int		j;
	int		color;

	color = create_trgb(0, 255, 0, 0);
	i = -1;
	while (++i < 5)
	{
		y++;
		j = -1;
		while (++j < 5)
		{
			x++;
			my_mlx_pixel_put(data, x, y, color);
		}
	}
}

int			ft_render_map(t_all *all)
{
	int		i;
	int		j;

	i = 0;
	while (all->map.map[i])
	{
		ft_putendl_fd(all->map.map[i], 1);
		j = 0;
		while (all->map.map[i][j] != '\0')
		{
			if (all->map.map[i][j] == 1)
				my_mlx_pixel_put(&all->data, j, i, 0x00FF0000);
				//ft_render_square(data, j, i);
			j++;
		}
		i++;
	}
	return (0);
}

int			ft_render(t_all *all)
{
	ft_render_map(all);
	return (0);
}