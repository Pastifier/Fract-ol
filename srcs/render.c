/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebinjama <ebinjama@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 23:30:52 by ebinjama          #+#    #+#             */
/*   Updated: 2024/02/13 17:56:36 by ebinjama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	render(t_program *fractol)
{
	unsigned int	color;
	int				escape_time;
	// int				i;
	int				(*chosen_set)(int, t_program*, t_complex*);

	if (JULIA == fractol->chosen_set)
		chosen_set = escape_time_julia;
	else if (MANDELBROT == fractol->chosen_set)
		chosen_set = escape_time_mandel;
	else
		chosen_set = escape_time_julia;
	// i = -1;
	fractol->pixel.y = -1;
	while (++fractol->pixel.y <  WIN_HEIGHT)
	{
		// fractol->pixel = (t_point){i % WIN_WIDTH, i / WIN_HEIGHT};
		fractol->pixel.x = -1;
		while (++fractol->pixel.x < WIN_WIDTH)
		{escape_time = (*chosen_set)(MAX_ITER, fractol, &fractol->mouse_pos);
		if (MAX_ITER == escape_time)
			color = 0;
		else
			color = escape_time * fractol->algo_toggle;
		pixel_put(&fractol->img, fractol->pixel, color % 0xFFFFFFFF);}
	}
}
