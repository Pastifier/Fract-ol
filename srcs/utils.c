/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebinjama <ebinjama@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 16:00:33 by ebinjama          #+#    #+#             */
/*   Updated: 2024/02/15 22:14:54 by ebinjama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

static void	init_atof(char **rep, double *sign);
static void	validate_rep(char *rep, t_program *fractol);

double	ft_atof(char *rep, t_program *fractol)
{
	double	mantissa;
	size_t	dividend;
	double	sign;
	bool	found_point;

	validate_rep(rep, fractol);
	mantissa = 0;
	dividend = 1;
	found_point = false;
	init_atof(&rep, &sign);
	while (*rep)
	{
		if (ft_isdigit(*rep))
		{
			mantissa = (10 * mantissa) + (*rep - '0');
			if (found_point)
				dividend *= 10;
		}
		else if (*rep == '.' && !found_point)
			found_point = true;
		else
			break ;
		++rep;
	}
	printf("(%f)\n", sign * mantissa / dividend);
	return (sign * mantissa / dividend);
}

int	destroy_program(t_program *fractol)
{
	mlx_destroy_image(fractol->mlx, fractol->img.img);
	mlx_destroy_window(fractol->mlx, fractol->win);
	free(fractol->mlx);
	if (fractol->error)
	{
		ft_putendl_fd(RED"Invalid!"DFLT, STDERR_FILENO);
		exit(fractol->error);
	}
	return (exit(EXIT_SUCCESS), 0);
}

static void	init_atof(char **rep, double *sign)
{
	while (**rep && (**rep == ' ' || **rep == '\t'))
		*rep += 1;
	*sign = 1;
	if (**rep == '-')
	{
		*sign = -1;
		(*rep)++;
	}
	else if (**rep == '+')
	{
		(*rep)++;
	}
	*rep += 1;
}

static void	validate_rep(char *rep, t_program *fractol)
{
	t_vatof	utils;

	if (!*rep)
		return (fractol->error = 2, (void)destroy_program(fractol));
	utils = (t_vatof){0};
	while (*rep == ' ' || *rep == '\t')
		++rep;
	while (*rep)
	{
		if (*rep == '-' || *rep == '+')
			++utils.sign_count;
		else if (ft_isdigit(*rep))
			++utils.digit_count;
		else if (*rep == '.')
			++utils.dot_count;
		else if (ft_isalpha(*rep))
			utils.found_alpha = true;
		++rep;
	}
	if (!utils.digit_count || utils.sign_count > 1 || utils.found_alpha
		|| utils.dot_count > 1)
		return (fractol->error = 2, (void)destroy_program(fractol));
}
