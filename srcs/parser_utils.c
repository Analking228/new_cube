/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjani <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 18:06:13 by cjani             #+#    #+#             */
/*   Updated: 2021/03/16 18:06:15 by cjani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/include.h"

void			ft_parser_resolution(char *res, t_list *list, t_all *all)
{
	all->vars.w = ft_atoi(res);
	while (*res && ft_isdigit(*res))
		res++;
	if (ft_isspace(*res))
		res++;
	else
		ft_error_parser("Resolution Error", list, all->map.map);
	all->vars.h = ft_atoi(res);
	if (all->vars.w <= 0 || all->vars.h <= 0)
		ft_error_parser("Resolution Error", list, all->map.map);
}

static void		ft_txt_import(char *p, t_data *txt, t_all *all, t_list *list)
{
	if (txt->img != NULL)
		ft_error_parser("Multiple texture", list, all->map.map);
	txt->img = mlx_xpm_file_to_image(all->vars.mlx, p, &txt->w, &txt->h);
	if (txt->img == NULL)
		ft_error_parser("Invalid file", list, all->map.map);
	txt->addr = mlx_get_data_addr(txt->img, &txt->bits_per_pixel,\
			&txt->line_length, &txt->endian);
	if (txt->addr == NULL)
		ft_error_parser("Invalid file", list, all->map.map);
}

void			ft_parser_color(char *res, t_list *list, t_all *all, char t)
{

}

void			ft_parser_texture(char *res, t_list *list, t_all *all, char t)
{
	ft_putendl_fd(res, 1);
	while (ft_isspace(*res))
		res++;
	if (*res != '.')
		ft_error_parser("Texture Error", list, all->map.map);
	if (t == 'N')
		ft_txt_import(res, &all->txt.North, all, list);
	if (t == 'S')
		ft_txt_import(res, &all->txt.South, all, list);
	if (t == 'W')
		ft_txt_import(res, &all->txt.West, all, list);
	if (t == 'E')
		ft_txt_import(res, &all->txt.East, all, list);
	if (t == 's')
		ft_txt_import(res, &all->txt.Sprite, all, list);
}

int				ft_parser_map_src(char *str)
{
	int			i;

	i = 0;
	if (str[i] == 0)
		return (1);
	if (ft_isalpha(str[i]))
			return (1);
	if (ft_isdigit(str[i]) || ft_isblank(str[i]))
		return (0);
	return (2);
}
