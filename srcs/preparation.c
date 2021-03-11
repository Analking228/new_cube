/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preparation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjani <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 18:10:21 by cjani             #+#    #+#             */
/*   Updated: 2021/03/11 18:10:27 by cjani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/include.h"

void		ft_init(t_all *all)
{
	all->vars.w = 0;
	all->vars.h = 0;
	all->vars.mlx = NULL;
	all->vars.win = NULL;
}

int			ft_preparing(t_all *all, int ac, char **av)
{
	int		i;

	i = 0;
	ft_init(all);
	ft_parsing(all, ac, av);
	if (!(all->vars.mlx = mlx_init()))
		ft_error("MLX init error", all);
	all->data.img = mlx_new_image(all->vars.mlx, all->vars.w, all->vars.h);
	return (0);
}
