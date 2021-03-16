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
	//mlx_hook(all.vars.win, 17, 0, close_me, &all);
	//mlx_key_hook(all.vars.win, key_hook, &all.vars);
	//mlx_hook(all.vars.win, 2, 1L<<0, key_p, &all);
	mlx_loop(all.vars.mlx);
	return (0);
}
