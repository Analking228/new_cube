/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjani <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 20:38:59 by cjani             #+#    #+#             */
/*   Updated: 2021/03/16 20:39:01 by cjani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/include.h"

/*void		ft_validate_map(t_list *head, t_map *map, int last)
{
	int		i;
	int		j;

	i = -1;
	while (map->map[++i])
	{
		j = -1;
		while (map->map[i][++j])
		{
			if ((map->map[i][j] == '0') && ((i == 0) || (j == 0)))
				ft_error_parser("Map error", head, map->map);
			if (map->map[i][j] == '0' && (i == last || j + 1 == '\0'))
				ft_error_parser("Map error", head, map->map);
			if ((map->map[i][j] == '0' && (i != last && j != '\0'))\
			&& (map->map[i][j + 1] == ' ' || map->map[i][j - 1] == ' ' ))
				ft_error_parser("Map error", head, map->map);
			if ((map->map[i][j] == '0' && (i != last && j != '\0'))\
			&& (map->map[i + 1][j] == ' ' || map->map[i - 1][j] == ' ' ))
				ft_error_parser("Map error", head, map->map);
			if (((map->map[i][j] == ' ') && (i == 0)) && \
			(map->map[i + 1][j] != '1' && map->map[i][j + 1] != '1' && \
			map->map[i + 1][j + 1] != '1'))
				ft_error_parser("Map error", head, map->map);
		}
	}
}*/
