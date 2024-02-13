/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebinjama <ebinjama@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 01:46:16 by ebinjama          #+#    #+#             */
/*   Updated: 2024/02/13 17:51:49 by ebinjama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	handle_key_inputs(int keysym, t_program *fractol)
{
	if (KEY_ESC == keysym)
		destroy_program(fractol);
	else if (KEY_D == keysym)
		fractol->algo_toggle ^= 0x00B0FFB0;
	else if (KEY_A == keysym)
		fractol->lock ^= true;
	if (AKEY_L == keysym)
		fractol->zoom_focus.x += 25;
	if (AKEY_R == keysym)
		fractol->zoom_focus.x -= 25;
	if (AKEY_D == keysym)
		fractol->zoom_focus.y -= 25;
	if (AKEY_U == keysym)
		fractol->zoom_focus.y += 25;
	render(fractol);
	mlx_put_image_to_window(fractol->mlx, fractol->win,
		fractol->img.img, 0, 0);
	return (0);
}

int	handle_mouse_inputs(int insym, int x, int y, t_program *fractol)
{
	if (MSCROLL_DOWN == insym || MSCROLL_UP == insym)
	{
		if (fractol->zoom_focus.x != x || fractol->zoom_focus.y != y)
			fractol->zoom_focus = (t_point){x, y};
		if (MSCROLL_UP == insym)
			fractol->zoom *= 1.1;
		else if (MSCROLL_DOWN == insym)
			fractol->zoom *= 0.8;
	}
	render(fractol);
	mlx_put_image_to_window(fractol->mlx, fractol->win,
		fractol->img.img, 0, 0);
	return (0);
}
