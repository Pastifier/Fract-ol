/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebinjama <ebinjama@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 16:00:33 by ebinjama          #+#    #+#             */
/*   Updated: 2024/02/15 19:53:10 by ebinjama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	ft_atof(const char *rep)
{
	double	mantissa;
	size_t	dividend;
	short	sign;
	bool	found_point;

	mantissa = 0;
	dividend = 1;
	found_point = false;
	sign = 1;
	if (*rep == '+' || *rep == '-')
	{
		if (*rep == '-')
			sign *= -1;
		++rep;
	}
	while (*rep && ft_isdigit(*rep))
	{
		if (*(rep + 1) == '.' && !found_point)
		{
			found_point = true;
			mantissa = ((10 * mantissa) + (*rep - '0'));
			rep += 2;
		}
		else
		{
			if (found_point)
				dividend *= 10;
			mantissa = ((10 * mantissa) + (*rep - '0'));
			++rep;
		}
	}
	return (sign * mantissa / dividend);
}

int	destroy_program(t_program *fractol)
{
	mlx_destroy_image(fractol->mlx, fractol->img.img);
	mlx_destroy_window(fractol->mlx, fractol->win);
	free(fractol->mlx);
	if (fractol->error)
		exit(fractol->error);
	return (exit(EXIT_SUCCESS), 0);
}
