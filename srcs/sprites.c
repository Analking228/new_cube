#include "../includes/include.h"

static int		ft_sprite_count(t_all *all)
{
	int			i;
	int			j;
	int			res;

	res = 0;
	j = -1;
	while (all->map.map[++j])
	{
		i = -1;
		while (all->map.map[j][++i])
			if (all->map.map[j][i] == '2')
				res++;
	}
	return (res);
}

void			cast_sprt_loc(t_sprt_loc *sprites, t_all *all)
{
	int			count;
	int			j;
	int			i;

	i = -1;
	count = -1;
	while (all->map.map[++i])
	{
		j = -1;
		while (all->map.map[i][++j])
			if (all->map.map[i][j] == '2')
			{
				sprites[++count].x = j + 0.5;
				sprites[count].y = i + 0.5;
			}
	}
}

void			swap_sprt(t_sprt_loc *a, t_sprt_loc *b)
{
	t_sprt_loc	c;

	c = *a;
	*a = *b;
	*b = c;

}

void			sort_sprite(t_sprt_loc *sp, int n)
{
	int			i;
	int			j;

	i = -1;
	while (++i < n)
	{
		j = n;
		while (--j > i)
			if (sp[j - 1].dist < sp[j].dist)
				swap_sprt(&sp[j], &sp[j - 1]);
	}
}

void			sprt_screen(t_all *all, t_sprt_loc *sp, int i)
{
	all->sprt.x = sp[i].x -all->plr.pos_x;
	all->sprt.y = sp[i].y -all->plr.pos_y;
	all->sprt.inv = 1.0 / (all->ray.left *all->plr.dir_y -all->plr.dir_x * all->ray.right);
	all->sprt.transX = all->sprt.inv * (all->plr.dir_y * all->sprt.x -all->plr.dir_x * all->sprt.y);
	all->sprt.transY = all->sprt.inv * (all->ray.left * all->sprt.y - all->ray.right * all->sprt.x);
	all->sprt.sp_screenX = (int)(all->vars.w - all->vars.w / 2 * (1 + all->sprt.transX / all->sprt.transY));
}

void			ft_sprite_hw(t_all *all)
{
	all->sprt.sp_hight = abs((int)(all->vars.h / all->sprt.transY));
	all->sprt.sp_width = abs((int)(all->vars.w / all->sprt.transY));
	all->sprt.start_y = all->vars.h / 2 - all->sprt.sp_hight / 2;
	all->sprt.end_y = all->vars.h / 2 + all->sprt.sp_hight / 2;
	all->sprt.start_x = all->sprt.sp_screenX - all->sprt.sp_width / 2;
	all->sprt.end_x = all->sprt.sp_screenX + all->sprt.sp_width / 2;
	if (all->sprt.start_y < 0)
		all->sprt.start_y = 0;
	if (all->sprt.start_x < 0)
		all->sprt.start_x = 0;
	if (all->sprt.end_y >= all->vars.h)
		all->sprt.end_y = all->vars.h - 1;
	if (all->sprt.end_x >= all->vars.w)
		all->sprt.end_x = all->vars.w - 1;
	all->sprt.stripe = all->sprt.start_x;
}

void			ft_sprite(t_all *all, float *dist)
{
	t_sprt_loc	sprites[ft_sprite_count(all)];
	int			i;

	i = -1;
	cast_sprt_loc(sprites, all);
	while (++i < ft_sprite_count(all))
		sprites[i].dist = (pow((all->plr.pos_x - sprites[i].x), 2) + pow((all->plr.pos_y - sprites[i].y), 2));
	sort_sprite(sprites, ft_sprite_count(all));
	i = -1;
	while (++i < ft_sprite_count(all))
	{
		sprt_screen(all, sprites, i);
		ft_sprite_hw(all);
		ft_render_sprite(all, dist);
	}
}