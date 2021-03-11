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
	t_vars	vars;

	ft_parse(&vars, argc, argv);
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 640, 480, "AYE");
	mlx_loop(vars.mlx);
	ft_error("AAAAA", &vars);
}
