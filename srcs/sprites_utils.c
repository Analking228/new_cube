/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjani <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 09:57:15 by cjani             #+#    #+#             */
/*   Updated: 2021/03/17 09:57:17 by cjani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/include.h"

void			swap_sprt(t_sprt_loc *a, t_sprt_loc *b)
{
	t_sprt_loc	c;

	c = *a;
	*a = *b;
	*b = c;
}

void			sort_sprite(t_sprt_loc *sp, int n)
{
	int			i;
	int			j;

	i = -1;
	while (++i < n)
	{
		j = n;
		while (--j > i)
			if (sp[j - 1].dist < sp[j].dist)
				swap_sprt(&sp[j], &sp[j - 1]);
	}
}
