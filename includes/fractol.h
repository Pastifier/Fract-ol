/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebinjama <ebinjama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 08:42:35 by ebinjama          #+#    #+#             */
/*   Updated: 2024/02/06 20:40:17 by ebinjama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft.h"
# include "mlx.h"
# include <math.h>

/*--- CONST. DEFINES ---*/

# ifndef WIN_HEIGHT
#  define WIN_HEIGHT 960
# endif // !WIN_HEIGHT

# ifndef WIN_WIDTH
#  define WIN_WIDTH 1080
# endif // !WIN_WIDTH

# define RED "\x1b[31m"
# define GREEN "\x1b[32m"
# define DFLT "\x1b[0m"

# define NONE 0
# define JULIA 1
# define MANDELBROT 2

# ifdef __linux__
# endif // !__linux__

# ifdef __MACH__
# endif // !__MACH__

/*--- STRUCTS ---*/


typedef struct s_range
{
	t_eint	left_bound;
	t_eint	right_bound;
}	t_range;

typedef struct s_program
{
	void	*mlx;
	void	*win;
	t_range	range;
	bool	error;
}	t_program;
#endif // !FRACTOL_H
