/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebinjama <ebinjama@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 08:42:35 by ebinjama          #+#    #+#             */
/*   Updated: 2024/02/14 15:02:58 by ebinjama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft.h"
# include "mlx.h"
# include <math.h>

/*--- CONST. DEFINES ---*/

# ifndef WIN_HEIGHT
#  define WIN_HEIGHT 700
# endif // !WIN_HEIGHT

# ifndef WIN_WIDTH
#  define WIN_WIDTH 700
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
# define OTHER 3

# ifdef __linux__

enum e_keysyms
{
	MSCROLL_UP = 4,
	MSCROLL_DOWN,
	KEY_A = 97,
	KEY_D = 100,
	KEY_R = 114,
	AKEY_L = 65361,
	AKEY_U,
	AKEY_R,
	AKEY_D,
	KEY_ESC = 65307
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
	double	a;
	double	b;
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
	t_point		zoom_focus;
	double		initial_zoom;
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

/*--- INIT ---*/

void	init_julia(char **v, t_program *program);
void	init_mandelbrot(t_program *program);

/*--- COLORING ---*/

// The escape time of the given pixel through `f: C -> C`; 
// `f(z) = z^{2} + c`; where both `z` and `c` are
// complex numbers.
// The sequence `z_{n+1} = f(z_{n})` escapes to infinity
// when `z_{n+1} >= 4`
int		escape_time_julia(int max_iterations, t_program *screen, t_complex *c);

// Since the mandelbrot set is just a special case of the julia set,
// we can just use this function as a wrapper for the julia one.
int		escape_time_mandel(int max_iterations, t_program *screen, t_complex *d);
int		escape_time_burning(int max_iterations, t_program *screen,
			t_complex *disregard);
void	pixel_put(t_data *data, t_point coordinates, int color);

/*--- RENDERING ---*/

void	render(t_program *fractol);
int		destroy_program(t_program *fractol);

/*--- HOOKS ---*/

int		handle_key_inputs(int keysym, t_program *fractol);
int		handle_mouse_inputs(int insym, int x, int y, t_program *fractol);

/*--- UTILS ---*/

double	ft_atof(const char *rep);
#endif // !FRACTOL_H
