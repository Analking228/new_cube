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

int			make_map(t_list **head, int size, t_map *map)
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

int			ft_parsing(t_all *all, int ac, char **av)
{
	int 	fd;
	char	*line;
	t_list	*head;

	fd = open(av[1], O_RDONLY);
	head = NULL;
	while (get_next_line(fd, &line))
	{
		ft_lstadd_back(&head, ft_lstnew(line));
	}
	ft_lstadd_back(&head, ft_lstnew(line));
	if (make_map(&head, ft_lstsize(head), &all->map))
		ft_error("malloc failed", all);
	ft_lstclear(&head, free);
	return (0);
}
