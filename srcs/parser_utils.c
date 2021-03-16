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

void			ft_parser_resolution(char *clr_str, t_list *list, t_all *all)
{
	char		*tmp;

	tmp = clr_str;
	if (ft_isdigit(*clr_str))
		if (!(all->vars.w = ft_atoi(clr_str)))
			ft_error_abort("Resolution Error", all, list);
	while (ft_isdigit(*clr_str))
		clr_str++;
	if (*clr_str == ' ')
	{
		if (!(all->vars.h = ft_atoi(++clr_str)))
			ft_error_abort("Resolution Error", all, list);
	}
	else
		ft_error_abort("Resolution Error", all, list);
	while (ft_isdigit(*clr_str))
		clr_str++;
	if (*clr_str)
		ft_error_abort("Resolution Error", all, list);
	free(tmp);
}

static void		texture_import(char *p, t_data *txt, t_all *all, t_list *list)
{
	if (txt->img != NULL)
		ft_error_abort("Multiple texture", all, list);
	txt->img = mlx_xpm_file_to_image(all->vars.mlx, p, &txt->w, &txt->h);
	if (txt->img == NULL)
		ft_error_abort("Invalid file or format", all, list);
	txt->addr = mlx_get_data_addr(txt->img, &txt->bits_per_pixel,\
			&txt->line_length, &txt->endian);
	if (txt->addr == NULL)
		ft_error_abort("Invalid file or format", all, list);
}

void			ft_parser_texture(char *clr_str, t_list *list, t_all *all, char t)
{
	if (*clr_str != '.')
		ft_error_abort("Texture Error", all, list);
	if (t == 'N')
		texture_import(clr_str, &all->txt.North, all, list);
	if (t == 'S')
		texture_import(clr_str, &all->txt.South, all, list);
	if (t == 'W')
		texture_import(clr_str, &all->txt.West, all, list);
	if (t == 'E')
		texture_import(clr_str, &all->txt.East, all, list);
	if (t == 's')
		texture_import(clr_str, &all->txt.Sprite, all, list);
	free(clr_str);
}

static int		ft_count_com(char *str)
{
	int			com;

	com = 0;
	while (*str)
	{
		if (*str == ',')
			com++;
		str++;
	}
	return (com);
}

void			ft_parser_color(char *clr_str, t_list *list, t_all *all, char t)
{
	int			rgb[3];
	char		**sp;
	int			i;

	ft_putendl_fd(clr_str, 1);
	if (ft_count_com(clr_str) == 2)
		sp = ft_split(clr_str, ',');
	else
		ft_error_abort("Invalid color format", all, list);
	i = -1;
	while (sp[++i])
		if (!ft_isdigit(*sp[i]) || (rgb[i] = ft_atoi(sp[i])) > 256)
			ft_error_abort("Invalid color format", all, list);
	if (i != 3)
		ft_error_abort("Invalid color format", all, list);
	if (t == 'F' && all->map.f_color == -1)
		all->map.f_color = ft_color(0, rgb[0], rgb[1], rgb[2]);
	else if (t == 'C' && all->map.c_color == -1)
		all->map.c_color = ft_color(0, rgb[0], rgb[1], rgb[2]);
	else
		ft_error_abort("Multiply color", all, list);
	free(clr_str);
}

/*int				ft_parser_map_src(char *str)
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
}*/
