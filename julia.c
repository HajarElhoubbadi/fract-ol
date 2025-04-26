/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hajel-ho <hajel-ho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 17:54:47 by hajel-ho          #+#    #+#             */
/*   Updated: 2025/04/26 20:14:45 by hajel-ho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	calculate_julia(t_fractal *fractal)
{
	int		i;
	double	tmp;

	fractal->zre = scale(fractal->x, -2.0 / fractal->zoom + fractal->offset_x,
			2.0 / fractal->zoom + fractal->offset_x, WIDTH);
	fractal->zim = scale(fractal->y, -2.0 / fractal->zoom + fractal->offset_y,
			2.0 / fractal->zoom + fractal->offset_y, SIZE);
	i = 0;
	while (++i < fractal->max_iterations)
	{
		tmp = fractal->zre;
		fractal->zre = fractal->zre * fractal->zre
			- fractal->zim * fractal->zim + fractal->cre;
		fractal->zim = 2.0 * fractal->zim * tmp + fractal->cim;
		if (fractal->zre * fractal->zre + fractal->zim * fractal->zim > 4.0)
			break ;
	}
	if (i == fractal->max_iterations)
		put_color_to_pixel(fractal, fractal->x, fractal->y, 0x000000);
	else
		put_color_to_pixel(fractal, fractal->x,
			fractal->y, fractal->color * i);
}
