#include "../includes/include.h"

int			col_sprite(t_all *all)
{
	int		i;
	int		j;
	int		res;

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

void		cast_sprt_loc(t_sprt_loc sp[], t_all *all)
{
	int		i_sp;
	int		x;
	int		y;

	y = -1;
	i_sp = -1;
	while (all->map.map[++y])
	{
		x = -1;
		while (all->map.map[y][++x])
			if (all->map.map[y][x] == '2')
			{
				sp[++i_sp].x = x + 0.5;
				sp[i_sp].y = y + 0.5;
			}
	}
}

void		swap_sprt(t_sprt_loc *a, t_sprt_loc *b)
{
	t_sprt_loc	c;

	c = *a;
	*a = *b;
	*b = c;

}

void		sort_sprite(t_sprt_loc sp[], int n)
{
	int		i;
	int		j;

	i = -1;
	while (++i < n)
	{
		j = n;
		while (--j > i)
			if (sp[j - 1].dist < sp[j].dist)
				swap_sprt(&sp[j], &sp[j - 1]);
	}
}

void		sprt_screen(t_all *all, t_sprt_loc sp[], int i)
{
	all->sprt.x = sp[i].x -all->plr.pos_x;
	all->sprt.y = sp[i].y -all->plr.pos_y;
	all->sprt.inv = 1.0 / (all->ray.left *all->plr.dir_y -all->plr.dir_x * all->ray.right);
	all->sprt.transX = all->sprt.inv * (all->plr.dir_y * all->sprt.x -all->plr.dir_x * all->sprt.y);
	all->sprt.transY = all->sprt.inv * (all->ray.left * all->sprt.y - all->ray.right * all->sprt.x);
	all->sprt.sp_screenX = (int)(all->vars.w - all->vars.w / 2 * (1 + all->sprt.transX / all->sprt.transY));
}

void		sprt_h_w(t_all *all)
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

void		draw_sprt(t_all *all, float dist[])
{
	int		clr;

	while (all->sprt.stripe < all->sprt.end_x)
	{
		all->sprt.tex_x = (int)((all->sprt.stripe + all->sprt.sp_width / 2 - all->sprt.sp_screenX) * all->txt.Sprite.w / all->sprt.sp_width);
		if (all->sprt.transY > 0 && all->sprt.transY < dist[all->sprt.stripe])
		{
			all->sprt.y = all->sprt.start_y;
			while (all->sprt.y < all->sprt.end_y)
			{
				all->sprt.d = 128 * (all->sprt.y * 2 - all->vars.h + all->sprt.sp_hight);
				all->sprt.tex_y = all->sprt.d * all->txt.Sprite.h / all->sprt.sp_hight / 256;
				clr = color_s(all, all->sprt.tex_x, all->sprt.tex_y);
				if (clr)
					my_mlx_pixel_put(&all->data, all->sprt.stripe, (int)all->sprt.y, clr);
				all->sprt.y += 1;
			}
		}
		(all->sprt.stripe)++;
	}
}

void		sprite(t_all *all, float dist[])
{
	t_sprt_loc	sprites[col_sprite(all)];
	int				i;

	i = -1;
	cast_sprt_loc(sprites, all);
	while (++i < col_sprite(all))
		sprites[i].dist = (pow((all->plr.pos_x - sprites[i].x), 2) + pow((all->plr.pos_y - sprites[i].y), 2));
	sort_sprite(sprites, col_sprite(all));
	i = -1;
	while (++i < col_sprite(all))
	{
		sprt_screen(all, sprites, i);
		sprt_h_w(all);
		draw_sprt(all, dist);
	}
}