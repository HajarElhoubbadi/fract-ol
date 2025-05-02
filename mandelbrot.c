/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hajel-ho <hajel-ho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 17:55:11 by hajel-ho          #+#    #+#             */
/*   Updated: 2025/05/02 17:52:05 by hajel-ho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	scale(double pixel, double min, double max, int size)
{
	return (min + (pixel / (double)size) * (max - min));
}

void	calculate_mandelbrot(t_fractal *f)
{
	int		i;
	double	zr;
	double	zi;
	double	tmp;

	f->cr = scale(f->x, -2.0 / f->zoom + f->offset_x,
			2.0 / f->zoom + f->offset_x, WIDTH);
	f->ci = scale(f->y, -2.0 / f->zoom + f->offset_y,
			2.0 / f->zoom + f->offset_y, SIZE);
	zr = 0;
	zi = 0;
	i = 0;
	while (++i < f->max_iterations)
	{
		tmp = zr * zr - zi * zi + f->cr;
		zi = 2.0 * zr * zi + f->ci;
		zr = tmp;
		if ((zr * zr + zi * zi) > 4.0)
			break ;
	}
	if (i == f->max_iterations)
		put_color_to_pixel(f, f->x, f->y, 0x000000);
	else
		put_color_to_pixel(f, f->x, f->y, f->color * i);
}
