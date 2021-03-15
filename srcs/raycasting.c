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
	ray->left = plr->left;
	ray->right = plr->right;
}

void	ft_cast_ray(t_all *all)
{
	t_plr	ray; // задаем координаты луча равные координатам игрока
	int		i;
	int		j;

	ft_raycast_init(&ray, &all->plr);
	i = (int)(ray.y / G_SCALE);
	j = (int)(ray.x / G_SCALE);
	while (all->map.map[i][j] != '1')
	{
		ray.x += cos(ray.dir);
		printf("%f\n", ray.x);
		ray.y += sin(ray.dir);
		printf("%f\n", ray.y);
		my_mlx_pixel_put(&all->data, ray.x, ray.y, 0x990099);
		i = (int)(ray.y / G_SCALE);
		j = (int)(ray.x / G_SCALE);
	}
}
