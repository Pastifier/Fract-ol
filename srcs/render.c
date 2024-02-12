/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebinjama <ebinjama@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 23:30:52 by ebinjama          #+#    #+#             */
/*   Updated: 2024/02/12 14:24:27 by ebinjama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	render(t_program *fractol)
{
	unsigned int	color;
	int				escape_time;
	int				(*chosen_set)(int, t_program*, t_complex*);

	if (JULIA == fractol->chosen_set)
		chosen_set = escape_time_julia;
	else if (MANDELBROT == fractol->chosen_set)
		chosen_set = escape_time_mandel;
	else
		chosen_set = escape_time_julia;
	fractol->pixel.y = -1;
	while (++fractol->pixel.y < WIN_HEIGHT - 1)
	{
		fractol->pixel.x = -1;
		while (++fractol->pixel.x < WIN_WIDTH - 1)
		{
			escape_time = (*chosen_set)(MAX_ITER, fractol, &fractol->mouse_pos);
			if (MAX_ITER == escape_time)
				color = 0;
			else
				color = escape_time * fractol->algo_toggle;
			pixel_put(&fractol->img, fractol->pixel, color % 0xFFFFFFFF);
		}
	}
}
