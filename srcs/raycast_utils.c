/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjani <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 07:59:28 by cjani             #+#    #+#             */
/*   Updated: 2021/03/17 07:59:30 by cjani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/include.h"

static void	ft_raycast_get_texture_scale(t_all *all, t_data *texture)
{
	all->txt.tex_x = (int)(all->txt.wall_x * (float)texture->w);
	all->txt.tex_x = texture->w - all->txt.tex_x - 1;
	all->txt.step = (float)texture->h / all->ray.lineHeight;
}

void		ft_raycast_get_texture(t_all *all)
{
	if (all->ray.side == 1)
		ft_raycast_get_texture_scale(all, &all->txt.East);
	else if (all->ray.side == 2)
		ft_raycast_get_texture_scale(all, &all->txt.South);
	else if (all->ray.side == 3)
		ft_raycast_get_texture_scale(all, &all->txt.North);
	else if (all->ray.side == 4)
		ft_raycast_get_texture_scale(all, &all->txt.West);
	all->txt.tex_pos = all->txt.step * (all->ray.drawStart - \
	all->vars.h / 2 + all->ray.lineHeight / 2);
}
