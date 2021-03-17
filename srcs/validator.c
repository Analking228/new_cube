/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjani <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 06:55:19 by cjani             #+#    #+#             */
/*   Updated: 2021/03/17 06:55:22 by cjani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/include.h"

static int	ft_count_map(char **map)
{
	int		i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

static void	ft_validator_map(t_all *all)
{
	char	**m;
	int		i;
	int		j;
	int		last;

	last = ft_count_map(all->map.map);
	m = all->map.map;
	i = -1;
	while (m[++i])
	{
		j = -1;
		if (m[i][0] == 0 && m[i + 1] != NULL)
			ft_error_abort("Map Error", all, NULL);
		if (i == 0 && ft_strchr(m[i], '0'))
			ft_error_abort("Map Error", all, NULL);
		while (m[i][++j])
		{
			if ((i != last && i != 0 && m[i][j] == ' ') && (m[i][j - 1] == '0'\
			|| m[i][j + 1] == '0' || m[i - 1][j] == '0' || m[i + 1][j] == '0'))
				ft_error_abort("Map Error", all, NULL);
			if ((i != last && i != 0 && m[i][j] == '0') && (m[i][j - 1] == ' '\
			|| m[i][j + 1] == ' ' || m[i - 1][j] == ' ' || m[i + 1][j] == ' '))
				ft_error_abort("Map Error", all, NULL);
		}
	}
}

void		ft_validator(t_all *all)
{
	if (all->vars.w > 2560)
		all->vars.w = 2560;
	if (all->vars.h > 1380)
		all->vars.h = 1380;
	if (all->map.c_color == -1)
		ft_error_abort("No Celling color", all, NULL);
	if (all->map.f_color == -1)
		ft_error_abort("No Floor color", all, NULL);
	if (all->txt.North.img == NULL)
		ft_error_abort("North texture Error", all, NULL);
	if (all->txt.South.img == NULL)
		ft_error_abort("South texture Error", all, NULL);
	if (all->txt.West.img == NULL)
		ft_error_abort("West texture Error", all, NULL);
	if (all->txt.East.img == NULL)
		ft_error_abort("East texture Error", all, NULL);
	if (all->txt.Sprite.img == NULL)
		ft_error_abort("Sprite texture Error", all, NULL);
	ft_validator_map(all);
}
