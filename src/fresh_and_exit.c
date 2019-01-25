/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fresh_and_exit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudyi <arudyi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 17:33:21 by arudyi            #+#    #+#             */
/*   Updated: 2019/01/25 19:09:30 by arudyi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractal.h"

void	ft_clear_programm(t_elem *s_pixel)
{
	free(s_pixel);
}

void	ft_refresh(t_elem *s_pixel)
{
	mlx_destroy_image(s_pixel->mlx_ptr, s_pixel->img_ptr);
	mlx_clear_window(s_pixel->mlx_ptr, s_pixel->win_ptr);
	s_pixel->img_ptr = mlx_new_image(s_pixel->mlx_ptr, s_pixel->imagewidth,
	s_pixel->imageheight);
	s_pixel->begin_str = mlx_get_data_addr(s_pixel->img_ptr,
	&(s_pixel->bits_per_pixel), &(s_pixel->size_line), &(s_pixel->endian));
	ft_prepare_fractal_change(s_pixel);
}
