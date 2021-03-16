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

void		ft_controls_pos_fb(t_map *map, t_plr *plr, float speed)
{
	int		i;
	int		j;

	i = (plr->y + sin(plr->dir) * speed) / G_SCALE;
	j = (plr->x + cos(plr->dir) * speed) / G_SCALE;
	if (map->map[i][j] != '1')
	{
		plr->y += sin(plr->dir) * speed;
		plr->x += cos(plr->dir) * speed;
	}
}

void		ft_controls_pos_lr(t_map *map, t_plr *plr, float speed)
{
	int		i;
	int		j;

	i = (plr->y - cos(plr->dir) * speed) / G_SCALE;
	j = (plr->x + sin(plr->dir) * speed) / G_SCALE;
	if (map->map[i][j] != '1')
	{
		plr->y -= cos(plr->dir) * speed;
		plr->x += sin(plr->dir) * speed;
	}
}

int			key_p(int keycode, t_all *all)
{
	if (keycode == ESC)
		ft_error_abort("See you next time", all);
	if (keycode == LEFT)
		all->plr.dir -= tan(0.1f);
	else if (keycode == RIGHT)
		all->plr.dir += tan(0.1f);
	if (keycode == W)
		ft_controls_pos_fb(&all->map, &all->plr, -3.f);
	else if (keycode == S)
		ft_controls_pos_fb(&all->map, &all->plr, 1.f);
	else if (keycode == D)
		ft_controls_pos_lr(&all->map, &all->plr, 3.f);
	else if (keycode == A)
		ft_controls_pos_lr(&all->map, &all->plr, -3.f);
	ft_render(all);
	return (0);
}
