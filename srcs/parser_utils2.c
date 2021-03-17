/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjani <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 09:50:21 by cjani             #+#    #+#             */
/*   Updated: 2021/03/17 09:50:22 by cjani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/include.h"

static void		set_dir_NW(t_all *all, char dir)
{
	if (dir == 'N')
	{
		all->ray.left = -0.66;
		all->ray.right = 0;
		all->plr.dir_x = 0;
		all->plr.dir_y = -1;
	}
	if (dir == 'W')
	{
		all->ray.left = 0;
		all->ray.right = 0.66;
		all->plr.dir_x = -1;
		all->plr.dir_y = 0;
	}
}

static void		set_dir_SE(t_all *all, char dir)
{
	if (dir == 'S')
	{
		all->ray.left = 0.66;
		all->ray.right = 0;
		all->plr.dir_x = 0;
		all->plr.dir_y = 1;
	}
	if (dir == 'E')
	{
		all->ray.left = 0;
		all->ray.right = -0.66;
		all->plr.dir_x = 1;
		all->plr.dir_y = 0;
	}
}

int				ft_parser_plr_src_dir(t_all *all, int i, int j, char dir)
{
	if (!all->plr.pos_x && !all->plr.pos_y)
	{
		all->plr.pos_x = j + 0.001f;
		all->plr.pos_y = i + 0.001f;
		if (dir == 'N' || dir == 'W')
			set_dir_NW(all, dir);
		if (dir == 'S' || dir == 'E')
			set_dir_SE(all, dir);
	}
	else
		return (1);
	return (0);
}
