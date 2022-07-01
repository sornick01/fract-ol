#ifndef DEFINES_H
# define DEFINES_H

# include "fractol.h"

/* Window defaults */

# define WIN_WIDTH			1280
# define WIN_HEIGHT 		1280
# define OFFSET				60
# define WIN_NAME			"fract-ol"
# define OFF				0	
# define ON					1	

/* Threads defaults */
# define THREADS			8
# define ITERATIONS_START	32
# define ITERATIONS_CHANGE	8
# define ITERATIONS_MIN		10
# define ITERATIONS_MAX		512

/* Fractals math */

# define MANDELBROT			0
# define JULIA				1
# define BURNINGSHIP		2
# define TRICORN			3

/* Colors */

# define WHITE				0xFFFFFF
# define COLORSET_GALACTIC	0
# define COLORSET_RED		1
# define COLORSET_PSYCHO	2

#endif