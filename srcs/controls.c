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

static void		key_p_fb(t_all *all, int speed)
{
	if (ft_strchr("0WESN", all->map.map[(int)all->plr.pos_y]\
	[(int)(all->plr.pos_x + (all->plr.dir_x * 0.1)  * speed)]))
		all->plr.pos_x += (all->plr.dir_x * 0.1) * speed;
	if (ft_strchr("0WESN", all->map.map[(int)(all->plr.pos_y + \
	(all->plr.dir_y * 0.1)  * speed)][(int)all->plr.pos_x]))
		all->plr.pos_y += (all->plr.dir_y * 0.1)  * speed;
	ft_raycast(all);
}

static void		key_p_lr(t_all *all, int speed)
{
	if (ft_strchr("0WESN", all->map.map[(int)all->plr.pos_y]\
	[(int)(all->plr.pos_x + (all->ray.left * 0.1)) * speed]))
		all->plr.pos_x += (all->ray.left * 0.1) * speed;
	if (ft_strchr("0WESN", all->map.map[(int)(all->plr.pos_y + \
	(all->ray.right * 0.1) * speed)][(int)all->plr.pos_x]))
		all->plr.pos_y += (all->ray.right * 0.1) * speed;
	ft_raycast(all);
}

void		key_p_turn(t_all *all, int speed)
{
	float old;
	
	old = all->plr.dir_x;
	all->plr.dir_x = all->plr.dir_x * cos(-0.05 * speed) \
	- all->plr.dir_y * sin(-0.05 * speed);
	all->plr.dir_y = old * sin(-0.05 * speed) + all->plr.dir_y 
	* cos(-0.05 * speed);
	old = all->ray.left;
	all->ray.left = all->ray.left * cos(-0.05 * speed) - \
	all->ray.right * sin(-0.05 * speed);
	all->ray.right = old * sin(-0.05 * speed) + all->ray.right * \
	cos(-0.05 * speed);
	ft_raycast(all);
}

int			key_p(int key, t_all *all)
{
	if (key == ESC)
		ft_error_abort("See you next time", all, NULL);
	if (key == W)
		key_p_fb(all, 2);
	else if (key == S)
		key_p_fb(all, -2);
	else if (key == A)
		key_p_lr(all, 2);
	else if (key == D)
		key_p_lr(all, -2);
	else if (key == LEFT)
		key_p_turn(all, 2);
	else if (key == RIGHT)
		key_p_turn(all, -2);
	return (0);
}