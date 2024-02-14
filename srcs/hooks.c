/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebinjama <ebinjama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 01:46:16 by ebinjama          #+#    #+#             */
/*   Updated: 2024/02/14 18:49:55 by ebinjama         ###   ########.fr       */
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
	if (KEY_R == keysym)
	{
		fractol->zoom_focus = (t_point){0};
		fractol->zoom = fractol->initial_zoom;
	}
	mlx_clear_window(fractol->mlx, fractol->win);
	render(fractol);
	mlx_put_image_to_window(fractol->mlx, fractol->win,
		fractol->img.img, 0, 0);
	return (0);
}

int	handle_mouse_inputs(int insym, int x, int y, t_program *fractol)
{
	double		zoom_factor;
	t_complex	offset;

	if (MSCROLL_DOWN == insym || MSCROLL_UP == insym)
	{
		if (MSCROLL_UP == insym)
			zoom_factor = 1.1;
		else
			zoom_factor = 1.0 / 1.1;
		offset.a = x - fractol->zoom_focus.x;
		offset.b = y - fractol->zoom_focus.y;
		fractol->zoom *= zoom_factor;
		fractol->zoom_focus.x = x - offset.a * zoom_factor;
		fractol->zoom_focus.y = y - offset.b * zoom_factor;
	}
	mlx_clear_window(fractol->mlx, fractol->win);
	render(fractol);
	mlx_put_image_to_window(fractol->mlx, fractol->win,
		fractol->img.img, 0, 0);
	return (0);
}
