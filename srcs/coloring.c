/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coloring.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebinjama <ebinjama@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 14:03:08 by ebinjama          #+#    #+#             */
/*   Updated: 2024/02/11 01:07:18 by ebinjama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	escape_time_julia(int max_iterations, t_program *screen, t_complex *c)
{
	int			i;
	t_complex	z;
	t_complex	fz;

	i = 0;
	z.a = (screen->pixel.x / screen->zoom) - (WIN_WIDTH / 2.0 / screen->zoom);
	z.b = (screen->pixel.y / screen->zoom) - (WIN_HEIGHT / 2.0 / screen->zoom);
	while (++i < max_iterations)
	{
		fz.a = (z.a * z.a) - (z.b * z.b) + (c->a);
		fz.b = 2.0 * z.a * z.b + c->b;
		if ((fz.a * fz.a) + (fz.b * fz.b) >= 4.0)
			break ;
		z = fz;
	}
	return (i);
}

void	pixel_put(t_data *data, t_point point, int color)
{
	char	*dst;

	dst = data->addr + (point.y * data->line_length
			+ point.x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}