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

void	ft_raycast(t_all *all)
{
	t_plr	ray;
	int		i;
	int		j;

	ft_raycast_init(&ray, &all->plr);
	i = (int)(ray.y / G_SCALE);
	j = (int)(ray.x / G_SCALE);
	ray.left = ray.dir - (FOV / 2.f);
	ray.right = ray.dir + (FOV / 2.f);
	while (ray.left <= ray.right)
	{
		ray.x = all->plr.x;
		ray.y = all->plr.y;
		while (all->map.map[(int)(ray.y / G_SCALE)][(int)(ray.x / G_SCALE)] != '1')
		{
			ray.x -= cos(ray.left);
			ray.y -= sin(ray.left);
			my_mlx_pixel_put(&all->data, ray.x, ray.y, 0x990099);
		}
		ray.left += (FOV / 480.f);
	}
}
