/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hajel-ho <hajel-ho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 13:06:06 by hajel-ho          #+#    #+#             */
/*   Updated: 2025/05/02 18:49:36 by hajel-ho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	zoom(t_fractal *f, int x, int y, int zoom)
{
	double	zoom_level;
	double	mouse_re;
	double	mouse_im;

	zoom_level = 1.42;
	mouse_re = scale(x, -2.0 / f->zoom + f->offset_x,
			2.0 / f->zoom + f->offset_x, WIDTH);
	mouse_im = scale(y, -2.0 / f->zoom + f->offset_y,
			2.0 / f->zoom + f->offset_y, SIZE);
	if (zoom == 1)
		f->zoom *= zoom_level;
	else if (zoom == -1)
		f->zoom /= zoom_level;
	else
		return ;
	f->offset_x = mouse_re - (scale(x, -2.0 / f->zoom, 2.0 / f->zoom, WIDTH));
	f->offset_y = mouse_im - (scale(y, -2.0 / f->zoom, 2.0 / f->zoom, SIZE));
}

int	key_hook(int key_code, t_fractal *f)
{
	if (key_code == ESC)
		exit(0);
	else if (key_code == LEFT)
		f->offset_x -= 0.1 / f->zoom;
	else if (key_code == RIGHT)
		f->offset_x += 0.1 / f->zoom;
	else if (key_code == UP)
		f->offset_y -= 0.1 / f->zoom;
	else if (key_code == DOWN)
		f->offset_y += 0.1 / f->zoom;
	else if (key_code == C)
		f->color += (f->color << 8);
	draw_fractal(f, f->name);
	return (0);
}

int	mouse_hook(int mouse_code, int x, int y, t_fractal *f)
{
	if (mouse_code == SCROLL_UP)
		zoom(f, x, y, 1);
	else if (mouse_code == SCROLL_DOWN)
		zoom(f, x, y, -1);
	draw_fractal(f, f->name);
	return (0);
}
