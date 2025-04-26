/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hajel-ho <hajel-ho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 13:06:06 by hajel-ho          #+#    #+#             */
/*   Updated: 2025/04/26 19:50:23 by hajel-ho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
void	zoom(t_fractal *fractal, int x, int y, int zoom)
{
	double	zoom_level;
	double	mouse_re;
	double	mouse_im;

	zoom_level = 1.42;
	// First: get the position of the mouse in fractal coordinates
	mouse_re = scale(x,
		-2.0 / fractal->zoom + fractal->offset_x,
		 2.0 / fractal->zoom + fractal->offset_x, WIDTH);
	mouse_im = scale(y,
		-2.0 / fractal->zoom + fractal->offset_y,
		 2.0 / fractal->zoom + fractal->offset_y, SIZE);
	if (zoom == 1) // zoom in
		fractal->zoom *= zoom_level;
	else if (zoom == -1) // zoom out
		fractal->zoom /= zoom_level;
	else
		return ;
	// After zoom, adjust offset so that zoom happens *at the mouse position*
	fractal->offset_x = mouse_re - (scale(x,-2.0 / fractal->zoom,2.0 / fractal->zoom, WIDTH));
	fractal->offset_y = mouse_im - (scale(y,-2.0 / fractal->zoom,2.0 / fractal->zoom, SIZE));
}

int	key_hook(int key_code, t_fractal *fractal)
{
	if (key_code == ESC)
		exit(1);
	else if (key_code == LEFT)
		fractal->offset_x -= 0.1 / fractal->zoom;
	else if (key_code == RIGHT)
		fractal->offset_x += 0.1 / fractal->zoom;
	else if (key_code == UP)
		fractal->offset_y -= 0.1 / fractal->zoom;
	else if (key_code == DOWN)
		fractal->offset_y += 0.1 / fractal->zoom;
	else if (key_code == C)
		fractal->color += (fractal->color << 8);
	draw_fractal(fractal, fractal->name);
	return (0);
}

int	mouse_hook(int mouse_code, int x, int y, t_fractal *fractal)
{
	if (mouse_code == SCROLL_UP)
		zoom(fractal, x, y, 1);
	else if (mouse_code == SCROLL_DOWN)
		zoom(fractal, x, y, -1);
	draw_fractal(fractal, fractal->name);
	return (0);
}
