/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjani <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 17:36:18 by cjani             #+#    #+#             */
/*   Updated: 2021/03/15 17:36:21 by cjani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/include.h"

void	ft_raycast_init(t_plr *ray, t_plr *plr)
{
	ray->x = plr->x;
	ray->y = plr->y;
	ray->dir = plr->dir;
}

void	ft_raycast_wall(t_all *all, t_plr *ray, float wall_h, float x)
{
	float y;
	int	equator;

	if (wall_h > all->vars.h)
		wall_h = all->vars.h;
	equator = all->vars.h / 2;	
	y = equator - (wall_h / 2) - 1;
	while (++y < equator + (wall_h / 2))
		my_mlx_pixel_put(&all->data, x, y, 0x990099);
}

void	ft_raycast(t_all *all)
{
	t_plr	ray;
	float	x;
	float	r_length;
	float	wall_height;

	ft_raycast_init(&ray, &all->plr);
	ray.left = ray.dir - (FOV / 2.f);
	ray.right = ray.dir + (FOV / 2.f);
	x = 0;
	while (ray.left <= ray.right)
	{
		ray.x = all->plr.x;
		ray.y = all->plr.y;
		while (all->map.map[(int)(ray.y / G_SCALE)][(int)(ray.x / G_SCALE)] != '1')
		{
			ray.x -= cos(ray.left);
			ray.y -= sin(ray.left);
			//my_mlx_pixel_put(&all->data, ray.x, ray.y, 0x990099);
		}
		r_length = sqrt(pow(all->plr.x - ray.x, 2) + pow(all->plr.y - ray.y, 2));
		wall_height = (all->vars.h / (r_length /** fabs(cos(ray.left - ray.dir))*/ )) * G_SCALE;
		ft_raycast_wall(all, &ray, wall_height, x);
		x++;
		ray.left += (FOV / all->vars.w);
	}
}
