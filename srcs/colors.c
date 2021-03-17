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
