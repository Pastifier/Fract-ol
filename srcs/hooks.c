/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebinjama <ebinjama@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 01:46:16 by ebinjama          #+#    #+#             */
/*   Updated: 2024/02/12 15:56:09 by ebinjama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	handle_key_inputs(int keysym, t_program *fractol)
{
	if (KEY_ESC == keysym)
		destroy_program(fractol);
	if (KEY_D == keysym)
		fractol->algo_toggle ^= 0x00B0FFB0;
	if (KEY_A == keysym)
		fractol->lock ^= true;
	render(fractol);
	mlx_put_image_to_window(fractol->mlx, fractol->win,
		fractol->img.img, 0, 0);
	return (0);
}
