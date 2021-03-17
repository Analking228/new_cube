/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshanti <kshanti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 13:25:21 by cjani             #+#    #+#             */
/*   Updated: 2021/03/17 05:19:10 by kshanti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/include.h"

int			close_me(int key, t_all	*all)
{
	exit(1);
	return (0);
}

int			main(int argc, char **argv)
{
	t_all	all;

	ft_preparing(&all, argc, argv);
	mlx_hook(all.vars.win, 17, 0, close_me, &all);
	mlx_hook(all.vars.win, 2, 0, key_p, &all);
	mlx_loop(all.vars.mlx);
	return (0);
}
