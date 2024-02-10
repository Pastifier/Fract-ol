/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebinjama <ebinjama@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 01:46:16 by ebinjama          #+#    #+#             */
/*   Updated: 2024/02/11 02:31:38 by ebinjama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	handle_key_inputs(int keysym, t_program *fractol)
{
	static int	right;

	if (KEY_ESC == keysym)
		destroy_program(fractol);
	if (KEY_D == keysym)
	{
		if (2 == right)
			fractol->algo_toggle = 0xF1FBAA00;
		if (1 == right)
			fractol->algo_toggle = 0xFFFF0000;
		if (0 == right)
			fractol->algo_toggle = 0xFF01BBEE;
		if (3 == ++right)
			right = 0;
	}
	return (0);
}
