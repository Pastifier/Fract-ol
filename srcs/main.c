/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebinjama <ebinjama@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 08:51:09 by ebinjama          #+#    #+#             */
/*   Updated: 2024/02/11 02:42:53 by ebinjama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	parse_input(int c, char **v);
static void	mlx_set_hooks(t_program *program);
static void	init_julia(char **v, t_program *program);

int	main(int c, char *v[])
{
	static t_program	screen;

	screen.zoom = 100.0;
	screen.chosen_set = parse_input(c, v);
	screen.algo_toggle = 0xFF01BBEE;
	if (JULIA == screen.chosen_set)
		init_julia(v, &screen);
	else if (MANDELBROT == screen.chosen_set)
		;
	else
		return (ft_putendl_fd(RED"usage:-\n"\
				"JULIA: fractol <{julia/JULIA}> <x> <y>\n"\
				"MANDELBROT: fractol {mandelbrot/MANDELBROT}"DFLT,
				STDERR_FILENO), 2);
	mlx_set_hooks(&screen);
	return (0);
}

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
	program->mouse_pos = (t_complex){.a = ft_atoi(v[2]).value,
		.b = ft_atoi(v[3]).value};
	program->lock = false;
	program->pixel = (t_point){0};
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
	return (NONE);
}

int	dynamic_julia(int x, int y, t_program *fractol)
{
	if (JULIA == fractol->chosen_set && !fractol->lock
		&& (x != fractol->pixel.x || y != fractol->pixel.y))
	{
		fractol->mouse_pos.a = (x / (double)WIN_WIDTH) * 3.0 - 2.0;
		fractol->mouse_pos.b = (y / (double)WIN_HEIGHT) * 2.0 - 1.0;
		// mlx_clear_window(fractol->mlx, fractol->win);
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
	mlx_hook(fractol->win, ON_DESTROY, 0, destroy_program, fractol);
	render(fractol);
	mlx_loop(fractol->mlx);
}
