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
	all->map.map = NULL;
	all->vars.w = -1;
	all->vars.h = -1;
	all->vars.mlx = NULL;
	all->vars.win = NULL;
	all->plr.x = 0;
	all->plr.y = 0;
	all->map.c_color = -1;
	all->map.f_color = -1;
	all->txt.North.img = NULL;
	all->txt.South.img = NULL;
	all->txt.West.img = NULL;
	all->txt.East.img = NULL;
	all->txt.Sprite.img = NULL;
	all->txt.North.addr = NULL;
	all->txt.South.addr = NULL;
	all->txt.West.addr = NULL;
	all->txt.East.addr = NULL;
	all->txt.Sprite.addr = NULL;
}

int			ft_preparing_img(t_vars *vars, t_data *data)
{
	if ((vars->win = mlx_new_window(vars->mlx, vars->w, vars->h, "CUBE")))
		if ((data->img = mlx_new_image(vars->mlx, vars->w, vars->h)))
			if ((data->addr = mlx_get_data_addr(data->img, \
				&data->bits_per_pixel, &data->line_length, &data->endian)))
				return (0);
	return (1);
}

int			ft_preparing(t_all *all, int ac, char **av)
{
	ft_init(all);
	if (!(all->vars.mlx = mlx_init()))
		ft_error_abort("mlx failed", all, NULL);
	if (ft_parser(all, ac, av))
		return (1);
	if (ft_preparing_img(&all->vars, &all->data))
		ft_error_abort("mlx-img init failed", all, NULL);
	//ft_render(all);
	return (0);
}
