/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_key_mouse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudyi <arudyi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 17:29:39 by arudyi            #+#    #+#             */
/*   Updated: 2019/01/25 19:23:34 by arudyi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractal.h"

int		ft_check_key(int key, t_elem *s_p)
{
	if (key == 53)
	{
		mlx_destroy_image(s_p->mlx_ptr, s_p->img_ptr);
		mlx_destroy_window(s_p->mlx_ptr, s_p->win_ptr);
		ft_clear_programm(s_p);
		system("leaks fractal");
		exit(1);
	}
	if (key == 83 || key == 85)
		ft_change_pthreads(s_p, key);
	if (key == 123 || key == 126 || key == 124 || key == 125)
		ft_change_position(s_p, key);
	if (key == 51)
	{
		mlx_clear_window(s_p->mlx_ptr, s_p->win_ptr);
		ft_prepare_fractal(s_p);
	}
	ft_refresh(s_p);
	return (0);
}

void	ft_change_pthreads(t_elem *s_p, int key)
{
	if (key == 83)
		if (s_p->pthread < 8)
			s_p->pthread++;
	if (key == 85)
		if (s_p->pthread != 1)
			s_p->pthread--;
}

void	ft_change_position(t_elem *s_p, int key)
{
	if (key == 123)
		s_p->minre = s_p->minre / 1.1;
	if (key == 124)
		s_p->minre = s_p->minre * 1.1;
	if (key == 126)
		s_p->minim = s_p->minim / 1.1;
	if (key == 125)
		s_p->minim = s_p->minim * 1.1;
}

int		mouse_press(int button, int x, int y, t_elem *s_p)
{
	s_p->more = (double)x / ((s_p->imagewidth - 1) /
	(s_p->maxre - s_p->minre)) + s_p->minre;
	s_p->moim = (double)y / ((s_p->imageheight - 1) /
	(s_p->maxim - s_p->minim)) + s_p->minim;
	if (button == 5)
	{
		s_p->k = 1.0 / 1.1;
		s_p->minre = s_p->more + ((s_p->minre - s_p->more) * s_p->k);
		s_p->maxre = s_p->more + ((s_p->maxre - s_p->more) * s_p->k);
		s_p->minim = s_p->moim + ((s_p->minim - s_p->moim) * s_p->k);
		s_p->zoom++;
	}
	if (button == 4)
	{
		s_p->k = 1.0 / 0.9;
		s_p->minre = s_p->more + ((s_p->minre - s_p->more) * s_p->k);
		s_p->maxre = s_p->more + ((s_p->maxre - s_p->more) * s_p->k);
		s_p->minim = s_p->moim + ((s_p->minim - s_p->moim) * s_p->k);
		s_p->zoom--;
	}
	ft_refresh(s_p);
	return (0);
}

int		mouse_move(int x, int y, t_elem *s_p)
{
	if ((0 <= x && x <= (int)s_p->imagewidth) &&
	(0 <= y && y <= (int)s_p->imageheight))
	{
		s_p->mousex = s_p->minre + x * s_p->re_factor;
		s_p->mousey = s_p->minim + y * s_p->im_factor;
	}
	ft_refresh(s_p);
	return (0);
}
