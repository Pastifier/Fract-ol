/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebinjama <ebinjama@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 14:08:25 by ebinjama          #+#    #+#             */
/*   Updated: 2024/02/13 17:48:53 by ebinjama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_julia(char **v, t_program *program)
{
	program->mlx = mlx_init();
	if (!program->mlx)
		(ft_putendl_fd(RED"Couldn't init mlx"DFLT, 2), (void)exit(2));
	program->win = mlx_new_window(program->mlx, WIN_WIDTH, WIN_HEIGHT, "Julia");
	if (!program->win)
		(free(program->mlx), ft_putendl_fd(RED"Couldn't init mlx"DFLT, 2),
			(void)exit(2));
	program->img.img = mlx_new_image(program->mlx, WIN_WIDTH, WIN_HEIGHT);
	program->img.addr = mlx_get_data_addr(program->img.img,
			&program->img.bits_per_pixel, &program->img.line_length,
			&program->img.endian);
	program->mouse_pos = (t_complex){.a = 0.3147,
		.b = 0.000005};
	program->lock = true;
	program->pixel = (t_point){0};
	program->zoom = 200.0;
	(void)v;
}

void	init_mandelbrot(t_program *program)
{
	program->mlx = mlx_init();
	if (!program->mlx)
		(ft_putendl_fd(RED"Couldn't init mlx"DFLT, 2), (void)exit(2));
	program->win = mlx_new_window(program->mlx, WIN_WIDTH, WIN_HEIGHT,
			"Mandelbrot");
	if (!program->win)
		(free(program->mlx), ft_putendl_fd(RED"Couldn't init mlx"DFLT, 2),
			(void)exit(2));
	program->img.img = mlx_new_image(program->mlx, WIN_WIDTH, WIN_HEIGHT);
	program->img.addr = mlx_get_data_addr(program->img.img,
			&program->img.bits_per_pixel, &program->img.line_length,
			&program->img.endian);
	program->lock = true;
	program->pixel = (t_point){0};
	program->mouse_pos = (t_complex){0};
	program->zoom = 150.0;
}
