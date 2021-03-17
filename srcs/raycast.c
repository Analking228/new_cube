/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjani <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 08:00:57 by cjani             #+#    #+#             */
/*   Updated: 2021/03/17 08:01:00 by cjani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/include.h"

void	ft_raycast_rayhit(t_all *all)
{
	while (all->ray.hit == 0)
	{
		if (all->ray.sideDistX <= all->ray.sideDistY)
		{
			all->ray.sideDistX += all->ray.deltaDistX;
			all->ray.mapX += all->ray.stepX;
			if (all->plr.pos_x > all->ray.mapX)
				all->ray.side = 1;
			else
				all->ray.side = 2;
		}
		else
		{
			all->ray.sideDistY += all->ray.deltaDistY;
			all->ray.mapY += all->ray.stepY;
			if (all->plr.pos_y > all->ray.mapY)
				all->ray.side = 3;
			else
				all->ray.side = 4;
		}
		if (all->map.map[all->ray.mapY][all->ray.mapX] == '1')
			all->ray.hit = 1;
	}
}

void	ft_raycast_prerender(t_all *all, float *dist, int x)
{
	if (all->ray.side < 3)
	{
		all->ray.perpWallDist = (all->ray.mapX - all->plr.pos_x + \
		(1 - all->ray.stepX) / 2) / all->ray.rayDirX;
		all->txt.wall_x = all->plr.pos_y + all->ray.perpWallDist * \
		all->ray.rayDirY;
	}
	else
	{
		all->ray.perpWallDist = (all->ray.mapY - all->plr.pos_y + \
		(1 - all->ray.stepY) / 2) / all->ray.rayDirY;
		all->txt.wall_x = all->plr.pos_x + all->ray.perpWallDist * \
		all->ray.rayDirX;
	}
	all->txt.wall_x -= (int)(all->txt.wall_x);
	all->ray.lineHeight = all->vars.h / all->ray.perpWallDist;
	all->ray.drawStart = (all->vars.h / 2) - (all->ray.lineHeight / 2);
	all->ray.drawEnd = (all->vars.h / 2) + (all->ray.lineHeight / 2);
	if (all->ray.drawEnd >= all->vars.h)
		all->ray.drawEnd = all->vars.h - 1;
	if (all->ray.drawStart < 0)
		all->ray.drawStart = 0;
	dist[x] = all->ray.perpWallDist;
	ft_raycast_get_texture(all);
	ft_render_coloumn(all, x);
}

void	ft_raycast_init(t_all *all, int x)
{
	all->ray.mapX = (int)all->plr.pos_x;
	all->ray.mapY = (int)all->plr.pos_y;
	all->ray.cameraX = (2 - 2 * x / (float)all->vars.w) - 1;
	all->ray.rayDirX = all->plr.dir_x + all->ray.left * all->ray.cameraX;
	all->ray.rayDirY = all->plr.dir_y + all->ray.right * all->ray.cameraX;
	all->ray.hit = 0;
	all->ray.deltaDistX = fabs(1 / all->ray.rayDirX);
	all->ray.deltaDistY = fabs(1 / all->ray.rayDirY);
}

void	ft_raycast_step(t_all *all)
{
	if (all->ray.rayDirX < 0)
	{
		all->ray.stepX = -1;
		all->ray.sideDistX = (all->plr.pos_x - all->ray.mapX) *\
		all->ray.deltaDistX;
	}
	else
	{
		all->ray.stepX = 1;
		all->ray.sideDistX = (all->ray.mapX - all->plr.pos_x + 1.0)\
		* all->ray.deltaDistX;
	}
	if (all->ray.rayDirY < 0)
	{
		all->ray.stepY = -1;
		all->ray.sideDistY = (all->plr.pos_y - all->ray.mapY) *\
		all->ray.deltaDistY;
	}
	else
	{
		all->ray.stepY = 1;
		all->ray.sideDistY = (all->ray.mapY - all->plr.pos_y + 1.0)\
		* all->ray.deltaDistY;
	}
}

void	ft_raycast(t_all *all)
{
	float		dist[all->vars.w];
	int			x;

	x = -1;
	while (++x < all->vars.w)
	{
		ft_raycast_init(all, x);
		ft_raycast_step(all);
		ft_raycast_rayhit(all);
		ft_raycast_prerender(all, dist, x);
	}
	ft_sprite(all, dist);
	mlx_put_image_to_window(all->vars.mlx, all->vars.win, all->data.img, 0, 0);
}
