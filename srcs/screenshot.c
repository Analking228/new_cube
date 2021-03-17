/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screenshot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjani <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 09:34:13 by cjani             #+#    #+#             */
/*   Updated: 2021/03/17 09:34:15 by cjani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/include.h"

void				make_head(unsigned char *bmp_h, unsigned char *bmp_f, \
								t_all *scr)
{
	int				size;

	size = 14 + 40 + scr->vars.w * scr->vars.h * scr->data.bits_per_pixel / 8;
	bmp_h[0] = 'B';
	bmp_h[1] = 'M';
	bmp_h[2] = (unsigned char)(size);
	bmp_h[3] = (unsigned char)(size >> 8);
	bmp_h[4] = (unsigned char)(size >> 16);
	bmp_h[5] = (unsigned char)(size >> 24);
	bmp_h[10] = (unsigned char)(54);
	bmp_f[0] = (unsigned char)(40);
	bmp_f[4] = (unsigned char)(scr->vars.w);
	bmp_f[5] = (unsigned char)(scr->vars.w >> 8);
	bmp_f[6] = (unsigned char)(scr->vars.w >> 16);
	bmp_f[7] = (unsigned char)(scr->vars.w >> 24);
	bmp_f[8] = (unsigned char)(-scr->vars.h);
	bmp_f[9] = (unsigned char)(-scr->vars.h >> 8);
	bmp_f[10] = (unsigned char)(-scr->vars.h >> 16);
	bmp_f[11] = (unsigned char)(-scr->vars.h >> 24);
	bmp_f[12] = (unsigned char)(1);
	bmp_f[14] = (unsigned char)(scr->data.bits_per_pixel);
}

void				make_file(unsigned char *bmp_h, unsigned char *bmp_f,\
							t_all *scr)
{
	int				fd;
	char			*filename;
	int				i;
	int				size;

	i = -1;
	filename = "screen.bmp";
	fd = open(filename, O_RDWR | O_CREAT, 0777);
	write(fd, bmp_h, 14);
	write(fd, bmp_f, 40);
	size = scr->data.bits_per_pixel / 8 * scr->vars.w;
	while (++i < scr->vars.h)
		write(fd, scr->data.addr + i * scr->data.line_length, size);
	close(fd);
}

void				ft_screen(t_all *all)
{
	unsigned char	bmp_head[14];
	unsigned char	bmp_fhead[40];

	ft_bzero(bmp_head, 14);
	ft_bzero(bmp_fhead, 40);
	make_head(bmp_head, bmp_fhead, all);
	make_file(bmp_head, bmp_fhead, all);
	ft_error_abort("Saved!", all, NULL);
}
