/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preparation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjani <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 18:10:21 by cjani             #+#    #+#             */
/*   Updated: 2021/03/11 18:10:27 by cjani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/include.h"

void		ft_init(t_all *all)
{
	all->vars.w = 640;
	all->vars.h = 480;
	all->vars.mlx = NULL;
	all->vars.win = NULL;
	all->plr.x = 0;
	all->plr.y = 0;
	all->map.f_color = ft_color(0, 99, 0, 99);
	all->map.f_color = ft_color(0, 0, 99, 0);

}

int			ft_preparing_img(t_vars *vars, t_data *data)
{
	if ((vars->mlx = mlx_init()))
		if ((vars->win = mlx_new_window(vars->mlx, vars->w, vars->h, "CUBE")))
			if ((data->img = mlx_new_image(vars->mlx, vars->w, vars->h)))
				if ((data->addr = mlx_get_data_addr(data->img, \
					&data->bits_per_pixel, &data->line_length, &data->endian)))
					return (0);
	return (1);
}

int			ft_preparing(t_all *all, int ac, char **av)
{
	int		i;
	int		j;

	i = -1;
	ft_init(all);
	ft_parsing(all, ac, av);
	if (ft_preparing_img(&all->vars, &all->data))
		ft_error("mlx-img init failed", all);
	ft_render(all);
	mlx_put_image_to_window(all->vars.mlx, all->vars.win, all->data.img, 0, 0);
	return (0);
}
