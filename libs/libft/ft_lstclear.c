/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjani <cjani@studen.21-school.ru>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/21 13:19:00 by flexer            #+#    #+#             */
/*   Updated: 2020/05/26 23:37:55 by cjani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list *cur_elem;

	while (*lst != NULL)
	{
		cur_elem = *lst;
		*lst = cur_elem->next;
		del(cur_elem->content);
		free(cur_elem);
	}
}
