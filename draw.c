/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hajel-ho <hajel-ho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 19:34:49 by hajel-ho          #+#    #+#             */
/*   Updated: 2025/05/09 18:03:57 by hajel-ho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	draw_fractal(t_fractal *f, char *name)
{
	mlx_clear_window(f->mlx, f->window);
	if (ft_strcmp(name, "mandelbrot") == 0)
		draw_mandelbrot(f);
	else if (ft_strcmp(name, "julia") == 0)
		draw_julia(f);
	else if (ft_strcmp(name, "tricorn") == 0)
		draw_tricorn(f);
	else
		exit_fractal(f);
	return (0);
}

int	draw_mandelbrot(t_fractal *f)
{
	f->y = 0;
	while (f->y < SIZE)
	{
		f->x = 0;
		while (f->x < WIDTH)
		{
			calculate_mandelbrot(f);
			f->x++;
		}
		f->y++;
	}
	mlx_put_image_to_window(f->mlx, f->window, f->image, 0, 0);
	return (0);
}

int	draw_julia(t_fractal *f)
{
	f->y = 0;
	while (f->y < SIZE)
	{
		f->x = 0;
		while (f->x < WIDTH)
		{
			calculate_julia(f);
			f->x++;
		}
		f->y++;
	}
	mlx_put_image_to_window(f->mlx, f->window, f->image, 0, 0);
	return (0);
}

int	draw_tricorn(t_fractal *f)
{
	f->y = 0;
	while (f->y < SIZE)
	{
		f->x = 0;
		while (f->x < WIDTH)
		{
			calculate_tricorn(f);
			f->x++;
		}
		f->y++;
	}
	mlx_put_image_to_window(f->mlx, f->window, f->image, 0, 0);
	return (0);
}
