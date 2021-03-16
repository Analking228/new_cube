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

static void	close_mlx(t_all *all)
{
	if (all->vars.mlx == NULL)
		return ;
	if (all->vars.win)
		mlx_destroy_window(all->vars.mlx, all->vars.win);
	/*if (all->texture.e.img)
		mlx_destroy_image(all->frame.mlx, all->texture.e.img);*/
	if (all->data.img)
		mlx_destroy_image(all->vars.mlx, all->data.img);
	if (all->vars.mlx)
		free(all->vars.mlx);
}

int			ft_error_abort(char *err, t_all *all)
{
	int		i;

	i = -1;
	close_mlx(all);
	while(all->map.map[++i])
		free(all->map.map[i]);
	free(all->map.map[i]);
	free(all->map.map);
	ft_putendl_fd(err, 1);
	exit(0);
	return (0);
}

int			ft_error_parser(char *err, t_list *head, char **map)
{
	int		i;

	i = -1;
	ft_lstclear(&head, free);
	if (map)
	{
		while(map[++i])
			free(map[i]);
		free(map[i]);
		free(map);
	}
	ft_putendl_fd(err, 1);
	exit(0);
	return (0);
}
