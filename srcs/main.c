/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebinjama <ebinjama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 08:51:09 by ebinjama          #+#    #+#             */
/*   Updated: 2024/01/24 08:51:39 by ebinjama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int c, char *v[])
{
	(void)c; (void)v;
	ft_putendl_fd("Hello!", 1);
	void* mlx_ptr = mlx_init();
	(void)mlx_ptr;
	return (0);
}
