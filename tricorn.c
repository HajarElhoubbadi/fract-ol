/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tricorn.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hajel-ho <hajel-ho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 11:43:31 by hajel-ho          #+#    #+#             */
/*   Updated: 2025/04/21 12:47:26 by hajel-ho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	calculate_tricorn(t_fractal *fractal)
{
	int		i;
	double	x_temp;

	fractal->zx = 0;
	fractal->zy = 0;
	fractal->cx = (fractal->x - SIZE / 2.0) / fractal->zoom
		+ fractal->offset_x;
	fractal->cy = (fractal->y - SIZE / 2.0) / fractal->zoom
		+ fractal->offset_y;
	i = 0;
	while (++i < fractal->max_iterations)
	{
		x_temp = fractal->zx * fractal->zx - fractal->zy * fractal->zy
			+ fractal->cx;
		fractal->zy = -2.0 * fractal->zx * fractal->zy + fractal->cy;
		fractal->zx = x_temp;
		if (fractal->zx * fractal->zx + fractal->zy * fractal->zy > 4.0)
			break ;
	}
	if (i == fractal->max_iterations)
		put_color_to_pixel(fractal, fractal->x, fractal->y, 0x000000);
	else
		put_color_to_pixel(fractal, fractal->x, fractal->y,
			fractal->color * i);
}
