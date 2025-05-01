/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hajel-ho <hajel-ho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 19:34:49 by hajel-ho          #+#    #+#             */
/*   Updated: 2025/05/01 20:42:20 by hajel-ho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	draw_fractal(t_fractal *f, char *query)
{
	mlx_clear_window(f->mlx, f->window);
	if (ft_strcmp(query, "mandelbrot") == 0)
		draw_mandelbrot(f);
	else if (ft_strcmp(query, "julia") == 0)
		draw_julia(f);
	else if (ft_strcmp(query, "tricorn") == 0)
		draw_tricorn(f);
	else
		exit_fractal(f);
	return (0);
}

int	draw_mandelbrot(t_fractal *f)
{
	f->x = 0;
	f->y = 0;
	while (f->y < WIDTH)
	{
		while (f->x < SIZE)
		{
			calculate_mandelbrot(f);
			f->x++;
		}
		f->y++;
		f->x = 0;
	}
	mlx_put_image_to_window(f->mlx, f->window,
		f->image, 0, 0);
	return (0);
}

int	draw_julia(t_fractal *f)
{
	f->x = 0;
	f->y = 0;
	while (f->x < SIZE)
	{
		while (f->y < SIZE)
		{
			calculate_julia(f);
			f->y++;
		}
		f->x++;
		f->y = 0;
	}
	mlx_put_image_to_window(f->mlx, f->window,
		f->image, 0, 0);
	mlx_hook(f->window, 6, 0, move_julia, f);
	return (0);
}

int	draw_tricorn(t_fractal *f)
{
	f->x = 0;
	f->y = 0;
	while (f->x < SIZE)
	{
		while (f->y < SIZE)
		{
			calculate_tricorn(f);
			f->y++;
		}
		f->x++;
		f->y = 0;
	}
	mlx_put_image_to_window(f->mlx, f->window,
		f->image, 0, 0);
	return (0);
}
