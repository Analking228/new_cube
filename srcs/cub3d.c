/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjani <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 13:25:21 by cjani             #+#    #+#             */
/*   Updated: 2021/03/10 13:25:24 by cjani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/include.h"

int			main(int argc, char **argv)
{
	t_all	all;

	//ft_validation();
	ft_preparing(&all, argc, argv);
	all.vars.mlx = mlx_init();
	all.vars.win = mlx_new_window(all.vars.mlx, 640, 480, "AYE");
	mlx_loop(all.vars.mlx);
}
