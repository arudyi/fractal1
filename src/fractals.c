/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudyi <arudyi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 17:24:15 by arudyi            #+#    #+#             */
/*   Updated: 2019/01/25 19:17:08 by arudyi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractal.h"

void	*ft_mal(void *thread_data)
{
	t_addition *data;

	data = (t_addition *)thread_data;
	data->y = data->imageheight / data->pthread * data->i;
	data->y = data->y - (data->imageheight / data->pthread) - 1;
	while (++data->y < data->imageheight / data->pthread * data->i)
	{
		data->c_im = data->minim + data->y * data->im_factor;
		data->x = -1;
		while (++data->x < data->imagewidth)
		{
			data->c_re = data->minre + data->x * data->re_factor;
			data->z_re = data->c_re;
			data->z_im = data->c_im;
			data->isinside = 1;
			data->n = -1;
			while (++data->n < data->maxiterations)
				ft_divide_ft_fractal(data);
			if (data->isinside == 1)
				ft_pixel_to_image(data, data->x, data->y, 0x000000);
		}
	}
	pthread_exit(0);
	return (NULL);
}

void	*ft_jul(void *thread_data)
{
	t_addition *data;

	data = (t_addition *)thread_data;
	data->y = data->imageheight / data->pthread * data->i;
	data->y = data->y - (data->imageheight / data->pthread) - 1;
	while (++data->y < data->imageheight / data->pthread * data->i)
	{
		data->c_im = data->minim + data->y * data->im_factor;
		data->x = -1;
		while (++data->x < data->imagewidth)
		{
			data->c_re = data->minre + data->x * data->re_factor;
			data->z_re = data->c_re;
			data->z_im = data->c_im;
			data->isinside = 1;
			data->n = -1;
			while (++data->n < data->maxiterations)
				ft_divide_ft_fractal(data);
			if (data->isinside == 1)
				ft_pixel_to_image(data, data->x, data->y, 0x000000);
		}
	}
	pthread_exit(0);
	return (NULL);
}

void	*ft_ship(void *thread_data)
{
	t_addition *data;

	data = (t_addition *)thread_data;
	data->y = data->imageheight / data->pthread * data->i;
	data->y = data->y - (data->imageheight / data->pthread) - 1;
	while (++data->y < data->imageheight / data->pthread * data->i)
	{
		data->c_im = data->minim + data->y * data->im_factor;
		data->x = -1;
		while (++data->x < data->imagewidth)
		{
			data->c_re = data->minre + data->x * data->re_factor;
			data->z_re = data->c_re;
			data->z_im = data->c_im;
			data->isinside = 1;
			data->n = -1;
			while (++data->n < data->maxiterations)
				ft_divide_ft_fractal(data);
			if (data->isinside == 1)
				ft_pixel_to_image(data, data->x, data->y, 0x000000);
		}
	}
	pthread_exit(0);
	return (NULL);
}

void	ft_divide_ft_fractal(t_addition *data)
{
	data->z_re2 = data->z_re * data->z_re;
	data->z_im2 = data->z_im * data->z_im;
	if ((data->z_re * data->z_re) + (data->z_im * data->z_im) > 4)
	{
		ft_pixel_to_image(data, data->x, data->y, get_color(data));
		data->isinside = 0;
	}
	if (data->type == 1)
	{
		data->z_im = 2 * data->z_re * data->z_im + data->c_im;
		data->z_re = data->z_re2 - data->z_im2 + data->c_re;
	}
	if (data->type == 2)
	{
		data->z_im = 2 * data->z_re * data->z_im + data->mousex;
		data->z_re = data->z_re2 - data->z_im2 + data->mousey;
	}
	if (data->type == 3)
	{
		data->z_im = fabs(2 * data->z_re * data->z_im) + data->c_im;
		data->z_re = fabs(data->z_re2 - data->z_im2) + data->c_re;
	}
}

void	ft_pixel_to_image(t_addition *data, int x, int y, int color)
{
	int index;

	index = data->size_line * y + x * 4;
	*(unsigned *)(data->begin_str + index) = color;
}
