/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_fractals.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudyi <arudyi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 17:27:26 by arudyi            #+#    #+#             */
/*   Updated: 2019/01/25 20:50:09 by arudyi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractal.h"

void	ft_prepare_fractal(t_elem *s_p)
{
	s_p->i = 1;
	s_p->zoom = 0;
	s_p->minre = -2.0;
	s_p->maxre = 2.0;
	s_p->minim = -1.2;
	s_p->maxim = s_p->minim + (s_p->maxre - s_p->minre) *
	s_p->imageheight / s_p->imagewidth;
	s_p->re_factor = (s_p->maxre - s_p->minre) /
	(s_p->imagewidth - 1);
	s_p->im_factor = (s_p->maxim - s_p->minim) /
	(s_p->imageheight - 1);
	s_p->x = -1;
	s_p->y = -1;
	s_p->n = -1;
	s_p->mousex = -0.2321;
	s_p->mousey = -0.835;
	ft_string_inter(s_p);
	ft_multi_threading(s_p);
}

void	ft_prepare_fractal_change(t_elem *s_p)
{
	s_p->maxim = s_p->minim + (s_p->maxre - s_p->minre) *
	s_p->imageheight / s_p->imagewidth;
	s_p->re_factor = (s_p->maxre - s_p->minre) /
	(s_p->imagewidth - 1);
	s_p->im_factor = (s_p->maxim - s_p->minim) /
	(s_p->imageheight - 1);
	s_p->x = -1;
	s_p->y = -1;
	s_p->n = -1;
	s_p->i = 1;
	ft_string_inter(s_p);
	ft_multi_threading(s_p);
}

void	ft_string_inter(t_elem *s_p)
{
	s_p->tmp2 = ft_itoa(s_p->minre);
	s_p->str = ft_strjoin("minre = ", s_p->tmp2);
	free(s_p->tmp2);
	s_p->tmp = ft_strjoin(s_p->str, " maxre = ");
	free(s_p->str);
	s_p->str = s_p->tmp;
	s_p->tmp2 = ft_itoa(s_p->maxre);
	s_p->tmp = ft_strjoin(s_p->str, s_p->tmp2);
	free(s_p->str);
	free(s_p->tmp2);
	s_p->str = s_p->tmp;
	s_p->tmp = ft_strjoin(s_p->str, " minim = ");
	free(s_p->str);
	s_p->str = s_p->tmp;
	s_p->tmp2 = ft_itoa(s_p->minim);
	s_p->tmp = ft_strjoin(s_p->str, s_p->tmp2);
	free(s_p->str);
	free(s_p->tmp2);
	s_p->str = s_p->tmp;
	s_p->tmp = ft_strjoin(s_p->str, " maxim = ");
	free(s_p->str);
	s_p->str = s_p->tmp;
	s_p->tmp2 = ft_itoa(s_p->maxim);
	s_p->tmp = ft_strjoin(s_p->str, s_p->tmp2);
	ft_string_inter1(s_p);
}

void	ft_string_inter1(t_elem *s_p)
{
	free(s_p->str);
	free(s_p->tmp2);
	s_p->str = s_p->tmp;
	s_p->tmp = ft_strjoin(s_p->str, " maxiterations = ");
	free(s_p->str);
	s_p->str = s_p->tmp;
	s_p->tmp2 = ft_itoa(s_p->maxiterations);
	s_p->tmp = ft_strjoin(s_p->str, s_p->tmp2);
	free(s_p->str);
	free(s_p->tmp2);
	s_p->str = s_p->tmp;
	s_p->tmp = ft_strjoin(s_p->str, " pthread = ");
	free(s_p->str);
	s_p->str = s_p->tmp;
	s_p->tmp2 = ft_itoa(s_p->pthread);
	s_p->tmp = ft_strjoin(s_p->str, s_p->tmp2);
	free(s_p->str);
	free(s_p->tmp2);
	s_p->str = s_p->tmp;
	mlx_string_put(s_p->mlx_ptr, s_p->win_ptr, 50, 750, 0xFFFFFF, s_p->str);
	free(s_p->str);
}

int		ft_multi_threading(t_elem *s_p)
{
	pthread_t	*threads;
	t_addition	*s_data;

	s_p->j = -1;
	threads = (pthread_t *)malloc(s_p->pthread * sizeof(pthread_t));
	s_data = (t_addition *)malloc(s_p->pthread * sizeof(t_addition));
	while (++s_p->j < s_p->pthread)
	{
		ft_copy_data(s_p, s_data, s_p->j);
		if (s_p->type == 1)
			pthread_create(&threads[s_p->j], NULL, ft_mal, &s_data[s_p->j]);
		if (s_p->type == 2)
			pthread_create(&(threads[s_p->j]), NULL, ft_jul, &s_data[s_p->j]);
		if (s_p->type == 3)
			pthread_create(&(threads[s_p->j]), NULL, ft_ship, &s_data[s_p->j]);
		s_p->i++;
	}
	s_p->j = -1;
	while (++s_p->j < s_p->pthread)
		pthread_join(threads[s_p->j], NULL);
	free(threads);
	free(s_data);
	ft_main_draw(s_p);
	return (0);
}
