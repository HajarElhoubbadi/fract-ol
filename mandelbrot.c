/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hajel-ho <hajel-ho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 17:55:11 by hajel-ho          #+#    #+#             */
/*   Updated: 2025/04/27 14:02:57 by hajel-ho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// double	scale_between(double unscaled_num, double min_allowed,
// 		double max_allowed, double max)
// {
// 	return ((max_allowed - min_allowed) * unscaled_num / max + min_allowed);
// }

double	scale(double pixel, double min, double max, int size)
{
	return (min + (pixel / (double)size) * (max - min));
}

void	calculate_mandelbrot(t_fractal *fractal)
{
	int		i;
	double	x_temp;

	fractal->zre = 0;
	fractal->zim = 0;
	fractal->cre = scale(fractal->x, -2.0 / fractal->zoom + fractal->offset_x,
			2.0 / fractal->zoom + fractal->offset_x, WIDTH);
	fractal->cim = scale(fractal->y, -2.0 / fractal->zoom + fractal->offset_y,
			2.0 / fractal->zoom + fractal->offset_y, SIZE);
	i = 0;
	while (++i < fractal->max_iterations)
	{
		x_temp = fractal->zre * fractal->zre
			- fractal->zim * fractal->zim + fractal->cre;
		fractal->zim = 2.0 * fractal->zre * fractal->zim + fractal->cim;
		fractal->zre = x_temp;
		if (fractal->zre * fractal->zre + fractal->zim * fractal->zim > 4.0)
			break ;
	}
	if (i == fractal->max_iterations)
		put_color_to_pixel(fractal, fractal->x, fractal->y, 0x000000);
	else
		put_color_to_pixel(fractal, fractal->x,
			fractal->y, fractal->color * i);
}
