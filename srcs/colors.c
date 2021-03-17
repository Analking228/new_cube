/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshanti <kshanti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 14:56:17 by cjani             #+#    #+#             */
/*   Updated: 2021/03/17 03:20:41 by kshanti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/include.h"

int			ft_color(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int		ft_color_texture(t_data *texture, int x, int y)
{
	int		res;

	x = abs(x);
	y = abs(y);
	res = 0;
	if (!texture->h || !texture->w)
		return (0);
	if (x > texture->w || y > texture->h)
		return (0);
	res = (*(int*)(texture->addr + ((x + (y * texture->w)) * (texture->bits_per_pixel / 8))));
	return (res);
}

int		color_no(t_all *all, int x, int y)
{
	int		res;

	x = abs(x);
	y = abs(y);
	res = 0;
	if (!all->txt.North.h || !all->txt.North.w)
		return (0);
	if (x > all->txt.North.w || y > all->txt.North.h)
		return (0);
	res = (*(int*)(all->txt.North.addr + ((x + (y * all->txt.North.w)) * (all->txt.North.bits_per_pixel / 8))));
	return (res);
}

int		color_ea(t_all *all, int x, int y)
{
	int		res;

	x = abs(x);
	y = abs(y);
	res = 0;
	if (!all->txt.East.h || !all->txt.East.w)
		return (0);
	if (x > all->txt.East.w || y > all->txt.East.h)
		return (0);
	res = (*(int*)(all->txt.East.addr + ((x + (y * all->txt.East.w)) * (all->txt.East.bits_per_pixel / 8))));
	return (res);
}

int		color_so(t_all *all, int x, int y)
{
	int		res;

	x = abs(x);
	y = abs(y);
	res = 0;
	if (!all->txt.South.h || !all->txt.South.w)
		return (0);
	if (x > all->txt.South.w || y > all->txt.South.h)
		return (0);
	res = (*(int*)(all->txt.South.addr + ((x + (y * all->txt.South.w)) * (all->txt.South.bits_per_pixel / 8))));
	return (res);
}

int		color_s(t_all *all, int x, int y)
{
	int		res;

	x = abs(x);
	y = abs(y);
	res = 0;
	if (!all->txt.Sprite.h || !all->txt.Sprite.w)
		return (0);
	if (x > all->txt.Sprite.w || y > all->txt.Sprite.h)
		return (0);
	res = (*(int*)(all->txt.Sprite.addr + ((x + (y * all->txt.Sprite.w)) * (all->txt.Sprite.bits_per_pixel / 8))));
	return (res);
}

int		color_we(t_all *all, int x, int y)
{
	int		res;

	x = abs(x);
	y = abs(y);
	res = 0;
	if (!all->txt.West.h || !all->txt.West.w)
		return (0);
	if (x > all->txt.West.w || y > all->txt.West.h)
		return (0);
	res = (*(int*)(all->txt.West.addr + ((x + (y * all->txt.West.w)) * (all->txt.West.bits_per_pixel / 8))));
	return (res);
}