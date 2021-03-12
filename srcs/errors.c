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

int			ft_error(char *err, t_all *all)
{
	mlx_destroy_window(all->vars.mlx, all->vars.win);
	ft_putendl_fd(err, 1);
	return (0);
}
