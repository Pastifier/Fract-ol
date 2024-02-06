/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebinjama <ebinjama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 08:51:09 by ebinjama          #+#    #+#             */
/*   Updated: 2024/02/06 21:07:40 by ebinjama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int			parse_input(int c, char **v);
static t_program	init_julia(int c, char **v);

int	main(int c, char *v[])
{
	static t_program	program;
	int					chosen_set;

	chosen_set = parse_input(c, v);
	if (JULIA == chosen_set)
		program = init_julia(c, v);
	else if (MANDELBROT == chosen_set)
		// ft_mandelbrot();
		return (ft_putendl_fd("You chose Mandelbrot", STDOUT_FILENO), 0);
	else
		return (ft_putendl_fd(RED"usage: fractol [set_name] [x1] [x2]"DFLT,
				STDERR_FILENO), 2);
	return (0);
}

t_program	init_julia(int c, char **v)
{
	t_program	self;

	self.mlx = mlx_init();
	if (!self.mlx)
		(ft_putendl_fd(RED"fractol: skill issue."DFLT, STDERR_FILENO),
			exit(2));
	self.win = mlx_new_window(self.mlx, WIN_HEIGHT, WIN_WIDTH, "Julia Set");
	// REMEMBER TO FREE!!
	if (!self.win)
		(ft_putendl_fd(RED"fractol: skill issue."DFLT, STDERR_FILENO),
			exit(2));
	if (c == 4)
		self.range = (t_range){.left_bound = ft_atoi(v[2]),
			ft_atoi(v[3])};
	else
		(ft_putendl_fd(RED"fractol: skill issue."DFLT, STDERR_FILENO),
			exit(2));
	if (self.range.left_bound.error || self.range.right_bound.error)
		(ft_putendl_fd(RED"Please use correct inputs"DFLT, STDERR_FILENO),
			exit(2));
	return (self);
}

int	parse_input(int c, char **v)
{
	if (c < 2)
		return (NONE);
	if (!ft_strncmp("JULIA", v[1], 6) || !ft_strncmp("julia", v[1], 6))
		return (JULIA);
	else if (!ft_strncmp("MANDELBROT", v[1], 11)
		|| !ft_strncmp("mandelbrot", v[1], 11))
		return (MANDELBROT);
	return (NONE);
}
