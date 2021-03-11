/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjani <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 14:48:06 by cjani             #+#    #+#             */
/*   Updated: 2021/03/10 14:48:41 by cjani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
//any kid of erros should by operated here
#include "../includes/include.h"

int			ft_error(char *err, t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	return (0);
}
