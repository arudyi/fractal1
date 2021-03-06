/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudyi <arudyi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 17:34:12 by arudyi            #+#    #+#             */
/*   Updated: 2019/01/25 21:05:40 by arudyi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractal.h"

unsigned int	get_color(t_addition *data)
{
	unsigned int color;

	data->color = 0x000000;
	color = data->color >> 2;
	color = color + data->n;
	color = color << 2;
	return (color);
}

void			ft_copy_data(t_elem *s_pixel, t_addition *thread_data, int j)
{
	thread_data[j].zoom = s_pixel->zoom;
	thread_data[j].imageheight = s_pixel->imageheight;
	thread_data[j].imagewidth = s_pixel->imagewidth;
	thread_data[j].maxim = s_pixel->maxim;
	thread_data[j].minim = s_pixel->minim;
	thread_data[j].maxre = s_pixel->maxre;
	thread_data[j].minre = s_pixel->minre;
	thread_data[j].isinside = s_pixel->isinside;
	thread_data[j].x = s_pixel->x;
	thread_data[j].y = s_pixel->y;
	thread_data[j].n = s_pixel->n;
	thread_data[j].mousex = s_pixel->mousex;
	thread_data[j].mousey = s_pixel->mousey;
	thread_data[j].c_im = s_pixel->c_im;
	ft_copy_data1(s_pixel, thread_data, j);
}

void			ft_copy_data1(t_elem *s_pixel, t_addition *thread_data, int j)
{
	thread_data[j].c_re = s_pixel->c_re;
	thread_data[j].z_re = s_pixel->z_re;
	thread_data[j].z_im = s_pixel->z_im;
	thread_data[j].z_re2 = s_pixel->z_re2;
	thread_data[j].z_im2 = s_pixel->z_im2;
	thread_data[j].pthread = s_pixel->pthread;
	thread_data[j].i = s_pixel->i;
	thread_data[j].begin_str = s_pixel->begin_str;
	thread_data[j].size_line = s_pixel->size_line;
	thread_data[j].maxiterations = s_pixel->maxiterations;
	thread_data[j].color = s_pixel->color;
	thread_data[j].re_factor = s_pixel->re_factor;
	thread_data[j].im_factor = s_pixel->im_factor;
	thread_data[j].mousex = s_pixel->mousex;
	thread_data[j].mousey = s_pixel->mousey;
	thread_data[j].type = s_pixel->type;
}

int				ft_check_key(int key, t_elem *s_p)
{
	if (key == 53)
	{
		mlx_destroy_image(s_p->mlx_ptr, s_p->img_ptr);
		mlx_destroy_window(s_p->mlx_ptr, s_p->win_ptr);
		ft_clear_programm(s_p);
		exit(1);
	}
	if (key == 83 || key == 85)
		ft_change_pthreads(s_p, key);
	if (key == 123 || key == 126 || key == 124 || key == 125)
		ft_change_position(s_p, key);
	if (key == 69)
		if (s_p->maxiterations != 250)
			s_p->maxiterations += 1;
	if (key == 78)
		if (s_p->maxiterations != 1)
			s_p->maxiterations -= 1;
	if (key == 51)
	{
		mlx_clear_window(s_p->mlx_ptr, s_p->win_ptr);
		ft_prepare_fractal(s_p);
	}
	ft_refresh(s_p);
	return (0);
}
