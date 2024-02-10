/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebinjama <ebinjama@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 08:42:35 by ebinjama          #+#    #+#             */
/*   Updated: 2024/02/11 01:09:45 by ebinjama         ###   ########.fr       */
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

# ifndef MAX_ITER
#  define MAX_ITER 100
# endif // !MAX_ITER

# define RED "\x1b[31m"
# define GREEN "\x1b[32m"
# define DFLT "\x1b[0m"

# define NONE 0
# define JULIA 1
# define MANDELBROT 2

# ifdef __linux__

enum e_keysyms
{
	KEY_ESC = 0xF1BB
};
# endif // !__linux__

# ifdef __MACH__

enum e_keysyms
{
	KEY_ESC = 53
};
# endif // !__MACH__

/*--- STRUCTS ---*/

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_data;

/*
 *	Complex numbers are defined as
 *	numbers containing a real part `a`
 *	and an imaginary part `b`. Often written
 *	as: `a + bi`, where `i` is the imaginary
 *	unit.
 */
typedef struct s_complex
{
	double a;
	double b;
}	t_complex;

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct s_program
{
	void		*mlx;
	void		*win;
	t_point		pixel;
	uint32_t	algo_toggle;
	t_complex	mouse_pos;
	double		zoom;
	t_data		img;
	t_complex	seed;
	bool		error;
	bool		lock;
	short		chosen_set;
}	t_program;

enum
{
	ON_KEYDOWN = 2,
	ON_KEYUP,
	ON_MOUSEDOWN,
	ON_MOUSEUP,
	ON_MOUSEMOVE,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

/*--- COLORING ---*/

// The escape time of the given pixel through `f: C -> C`; 
// `f(z) = z^{2} + c`; where both `z` and `c` are
// complex numbers.
// The sequence `z_{n+1} = f(z_{n})` escapes to infinity
// when `z_{n+1} >= 4`
int		escape_time_julia(int max_iterations, t_program *screen, t_complex *c);
void	pixel_put(t_data *data, t_point coordinates, int color);

/*--- RENDERING ---*/

void	render(t_program *fractol);
#endif // !FRACTOL_H
