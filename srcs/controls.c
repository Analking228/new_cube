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

int			key_p_lr(int keycode, t_all *all)
{
	/*if (keycode == LEFT)
		all->plr.x -= 1;
	else if (keycode == RIGHT)
		all->plr.x += 1;*/
	if (keycode == W)
		all->plr.y -= 2;
	else if (keycode == S)
		all->plr.y += 2;
	else if (keycode == D)
		all->plr.x += 2;
	else if (keycode == A)
		all->plr.x -= 2;
	ft_render(all);
	return (0);
}

int			key_p_term(int keykode, t_all *all)
{
	/*if (keycode == ESC)
		close_me(all);*/
	return (0);
}