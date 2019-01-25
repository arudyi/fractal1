/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudyi <arudyi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 16:15:17 by arudyi            #+#    #+#             */
/*   Updated: 2019/01/25 20:21:45 by arudyi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTAL_H
# define FRACTAL_H

# include <pthread.h>
# include <stdlib.h>
# include <math.h>
# include <mlx.h>
# include "../lib/libft/includes/libft.h"

typedef struct		s_elem
{
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img_ptr;
	double			zoom;
	unsigned int	imageheight;
	unsigned int	imagewidth;
	char			*begin_str;
	int				size_line;
	int				bits_per_pixel;
	int				endian;
	int				color;
	int				isinside;
	double			minre;
	double			maxre;
	double			minim;
	double			maxim;
	double			re_factor;
	double			im_factor;
	unsigned		maxiterations;
	double			c_im;
	double			c_re;
	double			z_re;
	double			z_re2;
	double			z_im;
	double			z_im2;
	unsigned		x;
	unsigned		y;
	unsigned		z;
	unsigned		n;
	double			more;
	double			moim;
	double			k;
	double			mousex;
	double			mousey;
	int				type;
	int				pthread;
	int				i;
	int				j;
	char			*str;
	char			*tmp;
	char			*tmp2;
	double			center_re;
	double			center_im;
	int				press;
}					t_elem;

typedef struct		s_addition
{
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img_ptr;
	double			zoom;
	unsigned int	imageheight;
	unsigned int	imagewidth;
	char			*begin_str;
	int				size_line;
	int				bits_per_pixel;
	int				endian;
	int				color;
	int				isinside;
	double			minre;
	double			maxre;
	double			minim;
	double			maxim;
	double			re_factor;
	double			im_factor;
	unsigned		maxiterations;
	double			c_im;
	double			c_re;
	double			z_re;
	double			z_re2;
	double			z_im;
	double			z_im2;
	unsigned		x;
	unsigned		y;
	unsigned		z;
	unsigned		n;
	double			more;
	double			moim;
	double			k;
	double			mousex;
	double			mousey;
	int				type;
	int				pthread;
	int				i;
}					t_addition;

int					mouse_release(int button, int x, int y, t_elem *s_pixel);
int					mouse_press(int button, int x, int y, t_elem *s_pixel);
int					ft_check_key(int key, t_elem *s_pixel);
void				ft_divide_ft_fractal(t_addition *data);
void				ft_string_inter1(t_elem *s_pixel);
void				ft_clear_programm(t_elem *s_pixel);
void				ft_copy_data1(t_elem *s_pixel, t_addition
*thread_data, int j);
void				ft_copy_data(t_elem *s_pixel, t_addition
*thread_data, int j);
void				ft_change_pthreads(t_elem *s_pixel, int key);
int					ft_multi_threading(t_elem *s_pixel);
void				*ft_ship(void *thread_data);
void				ft_refresh(t_elem *s_pixel);
int					mouse_move(int x, int y, t_elem *s_pixel);
int					mouse_release(int button, int x, int y, t_elem *s_pixel);
unsigned int		get_color(t_addition *data);
void				ft_prepare_fractal_change(t_elem *s_pixel);
void				ft_string_inter(t_elem *s_pixel);
void				ft_prepare_fractal(t_elem *s_pixel);
void				ft_pixel_to_image(t_addition *data, int x, int y,
int color);
void				ft_draw_display(t_elem *s_pixel);
void				*ft_mal(void *thread_data);
void				ft_line(t_elem *s_pixel);
void				ft_print_line_high(t_elem *s_pixel);
void				ft_print_line_low(t_elem *s_pixel);
int					ft_main_draw(t_elem *s_pixel);
void				ft_change_position(t_elem *s_pixel, int key);
void				*ft_jul(void *thread_data);

#endif
