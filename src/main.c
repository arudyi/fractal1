/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudyi <arudyi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 16:13:39 by arudyi            #+#    #+#             */
/*   Updated: 2019/01/25 19:23:20 by arudyi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractal.h"

int		ft_main_draw(t_elem *s_pixel)
{
	mlx_put_image_to_window(s_pixel->mlx_ptr, s_pixel->win_ptr,
	s_pixel->img_ptr, 0, 0);
	mlx_hook(s_pixel->win_ptr, 2, 5, ft_check_key, s_pixel);
	mlx_hook(s_pixel->win_ptr, 4, 5, mouse_press, s_pixel);
	mlx_hook(s_pixel->win_ptr, 6, 5, mouse_move, s_pixel);
	mlx_loop(s_pixel->mlx_ptr);
	return (0);
}

void	ft_draw_display(t_elem *s_pixel)
{
	s_pixel->color = 0xFFFFFF;
	s_pixel->imagewidth = 1000;
	s_pixel->imageheight = 700;
	s_pixel->win_ptr = mlx_new_window(s_pixel->mlx_ptr, s_pixel->imagewidth,
	s_pixel->imageheight + 100, "fractal");
	s_pixel->img_ptr = mlx_new_image(s_pixel->mlx_ptr, s_pixel->imagewidth,
	s_pixel->imageheight);
	s_pixel->begin_str = mlx_get_data_addr(s_pixel->img_ptr,
	&(s_pixel->bits_per_pixel), &(s_pixel->size_line), &(s_pixel->endian));
}

int		ft_start_programm(t_elem *s_pixel, int type)
{
	s_pixel->type = type;
	s_pixel->mlx_ptr = mlx_init();
	s_pixel->pthread = 1;
	s_pixel->i = 1;
	ft_draw_display(s_pixel);
	ft_prepare_fractal(s_pixel);
	return (0);
}

int		main(int ac, char **av)
{
	t_elem	*s_pixel;
	int		type;

	if (ac == 2)
	{
		if (!(s_pixel = (t_elem *)malloc(sizeof(t_elem))))
			return (0);
		if (ft_strcmp(av[1], "mal") == 0)
			type = 1;
		else if (ft_strcmp(av[1], "jul") == 0)
			type = 2;
		else if (ft_strcmp(av[1], "ship") == 0)
			type = 3;
		else
		{
			write(1, "error! please type: mal, jul or ship\n", 37);
			system("leaks fractal");
			return (0);
		}
		if (!(s_pixel = (t_elem *)malloc(sizeof(t_elem))))
			return (0);
		return (ft_start_programm(s_pixel, type));
	}
	write(1, "error! please type: mal, jul or ship\n", 37);
	system("leaks fractal");
	return (0);
}
