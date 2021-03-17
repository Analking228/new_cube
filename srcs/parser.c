/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshanti <kshanti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 13:25:02 by cjani             #+#    #+#             */
/*   Updated: 2021/03/17 04:46:40 by kshanti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/include.h"

int			check_map_str(char *str)
{
	char	*tmp;

	if (str)
	{
		while (*str && (!ft_isspace(*str) || *str == '1'))
		{
			str++;
			if (*str == 0)
				return (1);
		}

	}
	return (0);
}

int			ft_parser_make_map(t_list *head, t_map *map)
{
	int		i;
	int		flag;
	int		size;
	t_list	*tmp;
	
	tmp = head;
	while (tmp && !(check_map_str(tmp->content)))
		tmp = tmp->next;
	size = ft_lstsize(tmp);
	map->map = (char**)ft_calloc(size + 1, sizeof(char *));
	i = -1;
	while (tmp)
	{
		map->map[++i] = ft_strdup(tmp->content);
		tmp = tmp->next;
	}
	return (0);
}

void		set_dir(t_all *all, float l, float r, float x, float y)
{
	all->ray.left = l;
	all->ray.right = r;
	all->plr.dir_x = x;
	all->plr.dir_y = y;
}

int			ft_parser_plr_src_dir(t_all *all, int i, int j, char dir)
{
	if (!all->plr.pos_x && !all->plr.pos_y)
	{
		all->plr.pos_x = j + 0.001f;
		all->plr.pos_y = i + 0.001f;
		if (dir == 'N')
			set_dir(all, -0.66, 0, 0, -1);
		if (dir == 'W')
			set_dir(all, 0, 0.66, -1, 0);
		if (dir == 'S')
			set_dir(all, 0.66, 0, 0, 1);
		if (dir == 'E')
			set_dir(all, 0, -0.66, 1, 0);
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
		while(all->map.map[i][++j])
		{
			if (all->map.map[i][j] == 'W' || all->map.map[i][j] == 'S' || \
			all->map.map[i][j] == 'N' || all->map.map[i][j] == 'E')
				if (ft_parser_plr_src_dir(all, i, j, all->map.map[i][j]))
					ft_error_abort("Double Player error", all, NULL);
		}
	}
	if (!all->plr.pos_x && !all->plr.pos_y)
		ft_error_abort("NULL Player error", all, NULL);
	return (0);
}

void		ft_parser_vars(t_all *all, t_list *head)
{
	int		len;
	t_list	*tmp;

	tmp = head;
	while (tmp)
	{
		len = ft_strlen(tmp->content);
		if (ft_strnstr(tmp->content, "R ", len))
			ft_parser_resolution(ft_strtrim(tmp->content, "R "), head, all);
		else if (ft_strnstr(tmp->content, "NO ", len))
			ft_parser_texture(ft_strtrim(tmp->content, "NO "), head, all, 'N');
		else if (ft_strnstr(tmp->content, "WE ", len))
			ft_parser_texture(ft_strtrim(tmp->content, "WE "), head, all, 'W');
		else if (ft_strnstr(tmp->content, "EA ", len))
			ft_parser_texture(ft_strtrim(tmp->content, "EA "), head, all, 'E');
		else if (ft_strnstr(tmp->content, "SO ", len))
			ft_parser_texture(ft_strtrim(tmp->content, "SO "), head, all, 'S');
		else if (ft_strnstr(tmp->content, "S ", len))
			ft_parser_texture(ft_strtrim(tmp->content, "S "), head, all, 's');
		else if (ft_strnstr(tmp->content, "F ", len))
			ft_parser_color(ft_strtrim(tmp->content, "F "), head, all, 'F');
		else if (ft_strnstr(tmp->content, "C ", len))
			ft_parser_color(ft_strtrim(tmp->content, "C "), head, all, 'C');
		tmp = tmp->next;
	}
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
	ft_parser_vars(all, head);
	if (ft_parser_make_map(head, &all->map))
		ft_error_abort("Malloc Error", all, head);
	ft_lstclear(&head, free);
	if (ft_parser_plr_src(all))
		ft_error_abort("Double Player Error", all, head);
	close(fd);
	return (0);
}
