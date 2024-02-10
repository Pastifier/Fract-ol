/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebinjama <ebinjama@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 01:46:16 by ebinjama          #+#    #+#             */
/*   Updated: 2024/02/11 02:47:54 by ebinjama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	handle_key_inputs(int keysym, t_program *fractol)
{
	if (KEY_ESC == keysym)
		destroy_program(fractol);
	if (KEY_D == keysym)
		fractol->algo_toggle ^= 0xF1FBAA00;
	if (KEY_A == keysym)
		fractol->lock ^= true;
	return (0);
}
