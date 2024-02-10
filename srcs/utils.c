/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebinjama <ebinjama@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 16:00:33 by ebinjama          #+#    #+#             */
/*   Updated: 2024/02/11 00:27:56 by ebinjama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	atof(const char *rep)
{
	double	result;

	(void)rep;
	result = 0;
	return (result);
}

t_point	set_point(double x, double y)
{
	t_point	self;

	self.x = x;
	self.y = y;
	return (self);
}
