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

#include "../includes/include.h"

static void	close_mlx(t_all *all)
{
	if (all->vars.mlx == NULL)
		return ;
	if (all->vars.win)
		mlx_destroy_window(all->vars.mlx, all->vars.win);
	if (all->txt.East.img)
		mlx_destroy_image(all->vars.mlx, all->txt.East.img);
	if (all->txt.West.img)
		mlx_destroy_image(all->vars.mlx, all->txt.West.img);
	if (all->txt.North.img)
		mlx_destroy_image(all->vars.mlx, all->txt.North.img);
	if (all->txt.South.img)
		mlx_destroy_image(all->vars.mlx, all->txt.South.img);
	if (all->txt.Sprite.img)
		mlx_destroy_image(all->vars.mlx, all->txt.Sprite.img);
	if (all->data.img)
		mlx_destroy_image(all->vars.mlx, all->data.img);
	if (all->vars.mlx)
		free(all->vars.mlx);
}

int			ft_error_abort(char *err, t_all *all, t_list *head)
{
	int		i;

	i = -1;
	close_mlx(all);
	if (head)
		ft_lstclear(&head, free);
	if (all->map.map)
	{
		while (all->map.map[++i])
			free(all->map.map[i]);
		free(all->map.map[i]);
		free(all->map.map);
	}
	ft_putendl_fd(err, 1);
	exit(0);
	return (0);
}
