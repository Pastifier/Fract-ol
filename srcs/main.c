/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebinjama <ebinjama@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 08:51:09 by ebinjama          #+#    #+#             */
/*   Updated: 2024/02/16 01:28:01 by ebinjama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

static int	parse_input(int c, char **v);
static void	mlx_set_hooks(t_program *program);

// I like the values -1.999 and -0.0005

int	main(int c, char *v[])
{
	static t_program	screen;

	screen.chosen_set = parse_input(c, v);
	screen.algo_toggle = 0x00DD00EE;
	if (JULIA == screen.chosen_set)
		init_julia(v, &screen);
	else if (MANDELBROT == screen.chosen_set)
		init_mandelbrot(&screen);
	else if (OTHER == screen.chosen_set)
		init_mandelbrot(&screen);
	else
		return (ft_putendl_fd(RED"usage:-\n"\
				"JULIA: ./fractol <{julia/JULIA}> <real> <imaginary>\n"\
				"MANDELBROT: ./fractol <{mandelbrot/MANDELBROT}>\n"\
				"BURNING-SHIP: fractol <{other/OTHER}>"DFLT,
				STDERR_FILENO), 2);
	mlx_set_hooks(&screen);
	return (0);
}

int	parse_input(int c, char **v)
{
	if (c < 2)
		return (NONE);
	if ((!ft_strncmp("JULIA", v[1], 6) && c == 4)
		|| (!ft_strncmp("julia", v[1], 6) && c == 4))
		return (JULIA);
	else if ((!ft_strncmp("MANDELBROT", v[1], 11) && c == 2)
		|| (!ft_strncmp("mandelbrot", v[1], 11) && c == 2))
		return (MANDELBROT);
	else if ((!ft_strncmp("OTHER", v[1], 11) && c == 2)
		|| (!ft_strncmp("other", v[1], 11) && c == 2))
		return (OTHER);
	return (NONE);
}

int	dynamic_julia(int x, int y, t_program *fractol)
{
	if (JULIA == fractol->chosen_set && !fractol->lock
		&& (x != fractol->pixel.x || y != fractol->pixel.y))
	{
		fractol->mouse_pos.a = (x / (double)WIN_WIDTH) * 3.0 - 2.0;
		fractol->mouse_pos.b = (y / (double)WIN_HEIGHT) * 2.0 - 1.0;
		mlx_clear_window(fractol->mlx, fractol->win);
		render(fractol);
		mlx_put_image_to_window(fractol->mlx, fractol->win,
			fractol->img.img, 0, 0);
	}
	return (0);
}

void	mlx_set_hooks(t_program *fractol)
{
	mlx_hook(fractol->win, ON_MOUSEMOVE,
		1L << ON_MOUSEMOVE, dynamic_julia, fractol);
	mlx_hook(fractol->win, ON_KEYDOWN, 1L, handle_key_inputs, fractol);
	mlx_hook(fractol->win, ON_MOUSEDOWN, 1L << 2, handle_mouse_inputs, fractol);
	mlx_hook(fractol->win, ON_DESTROY, 0, destroy_program, fractol);
	if (fractol->chosen_set == JULIA)
		render(fractol);
	render(fractol);
	mlx_put_image_to_window(fractol->mlx, fractol->win,
		fractol->img.img, 0, 0);
	mlx_loop(fractol->mlx);
}
