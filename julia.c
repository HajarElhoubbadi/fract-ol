/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hajel-ho <hajel-ho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 17:54:47 by hajel-ho          #+#    #+#             */
/*   Updated: 2025/05/01 20:25:24 by hajel-ho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	calculate_julia(t_fractal *f)
{
	int		i;
	double	zr;
	double	zi;
	double	tmp;

	zr = scale(f->x, -2.0 / f->zoom + f->offset_x,
			2.0 / f->zoom + f->offset_x, WIDTH);
	zi = scale(f->y, 2.0 / f->zoom + f->offset_y,
			-2.0 / f->zoom + f->offset_y, SIZE);
	i = 0;
	while (++i < f->max_iterations)
	{
		tmp = zr;
		zr = zr * zr - zi * zi + f->cr;
		zi = 2.0 * zi * tmp + f->ci;
		if ((zr * zr + zi * zi) > 4.0)
			break ;
	}
	if (i == f->max_iterations)
		put_color_to_pixel(f, f->x, f->y, 0x000000);
	else
		put_color_to_pixel(f, f->x, f->y, f->color * i);
}
