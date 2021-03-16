/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjani <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 13:25:02 by cjani             #+#    #+#             */
/*   Updated: 2021/03/10 13:25:09 by cjani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/include.h"

int			ft_parser_make_map(t_list **head, int size, t_map *map)
{
	int		i;
	t_list	*tmp;

	if (!(map->map = (char **)ft_calloc(size + 1, sizeof(char *))))
		return (1);
	i = -1;
	tmp = *head;
	while (tmp)
	{
		map->map[++i] = ft_strdup(tmp->content);
		tmp = tmp->next;
	}
	return (0);
}

int			ft_parser_plr_src_dir(t_all *all, int i, int j, char dir)
{
	if (!all->plr.x && !all->plr.y)
	{
		all->plr.x = ((float)j * G_SCALE) + G_SCALE /2.f;
		all->map.plr_x = ((float)j * G_SCALE) + G_SCALE /2.f;
		all->plr.y = ((float)i * G_SCALE) + G_SCALE /2.f;
		all->map.plr_y = ((float)i * G_SCALE) + G_SCALE /2.f;
		if (dir == 'N')
			all->plr.dir = M_PI_2;
		if (dir == 'W')
			all->plr.dir = M_PI;
		if (dir == 'S')
			all->plr.dir = M_PI_4 * 3;
		if (dir == 'E')
			all->plr.dir = 0;
	}
	else
		return (1);
	return (0);
}

int			ft_parser_plr_src(t_all *all)
{
	int		i;
	int		j;
	
	i = -1;
	while (all->map.map[++i])
	{
		j = -1;
		while (all->map.map[i][++j] != '\0')
		{
			if (all->map.map[i][j] == 'N' || all->map.map[i][j] == 'S' || \
			all->map.map[i][j] == 'W' || all->map.map[i][j] == 'E')
				if (ft_parser_plr_src_dir(all, i, j, all->map.map[i][j]))
					return (1);
		}
	}
	return (0);
}

int			ft_parser(t_all *all, int ac, char **av)
{
	int 	fd;
	char	*line;
	t_list	*head;

	fd = open(av[1], O_RDONLY);
	head = NULL;
	while (get_next_line(fd, &line))
		ft_lstadd_back(&head, ft_lstnew(line));
	ft_lstadd_back(&head, ft_lstnew(line));
	if (ft_parser_make_map(&head, ft_lstsize(head), &all->map))
		ft_error_parser("Malloc Error", head, line, all->map.map);
	if (ft_parser_plr_src(all))
		ft_error_parser("Double Player Error", head, line, all->map.map);
	ft_lstclear(&head, free);
	free(line);
	return (0);
}
