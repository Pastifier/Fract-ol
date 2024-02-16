/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebinjama <ebinjama@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 16:00:33 by ebinjama          #+#    #+#             */
/*   Updated: 2024/02/16 21:44:16 by ebinjama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

static void	init_atof(char **rep, double *sign, t_program *f);
static void	validate_rep(char *rep, t_program *fractol);
static void	validate_double(double num, t_program *f);

double	ft_atof(char *rep, t_program *fractol)
{
	double	mantissa;
	double	dividend;
	bool	found_point;

	validate_rep(rep, fractol);
	mantissa = 0.0;
	dividend = 1.0;
	found_point = false;
	init_atof(&rep, &dividend, fractol);
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
	validate_double(mantissa / dividend, fractol);
	return (mantissa / dividend);
}

int	destroy_program(t_program *fractol)
{
	mlx_clear_window(fractol->mlx, fractol->win);
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

static void	init_atof(char **rep, double *sign, t_program *f)
{
	while (**rep && (**rep == ' ' || **rep == '\t'))
		(*rep)++;
	*sign = 1.0;
	if (**rep == '-' || **rep == '+')
	{
		if (**rep == '-')
			*sign = -1.0;
		(*rep)++;
		if (!ft_isdigit(**rep))
			return (f->error = 2, (void)destroy_program(f));
	}
	else if (ft_isdigit(**rep))
	{
		if (*(*rep + 1) == '.')
		{
			if (!ft_isdigit(*(*rep + 2)))
				return (f->error = 2, (void)destroy_program(f));
		}
		else if (!ft_isdigit(*(*rep + 1)) && (*(*rep + 1)))
			return (f->error = 2, (void)destroy_program(f));
	}
	else
		return (f->error = 2, (void)destroy_program(f));
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

static void	validate_double(double num, t_program *f)
{
	if (isnan(num) || isinf(num))
		return (f->error = 2, (void)destroy_program(f));
}
