/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hajel-ho <hajel-ho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 19:34:49 by hajel-ho          #+#    #+#             */
/*   Updated: 2025/04/26 20:37:00 by hajel-ho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	draw_fractal(t_fractal *fractal, char *query)
{
	mlx_clear_window(fractal->mlx, fractal->window);
	if (!ft_strcmp(query, "mandelbrot"))
		draw_mandelbrot(fractal);
	else if (!ft_strcmp(query, "julia"))
		draw_julia(fractal);
	else if (!ft_strcmp(query, "tricorn"))
		draw_tricorn(fractal);
	else
		exit_fractal(fractal);
	return (0);
}

int	draw_mandelbrot(t_fractal *fractal)
{
	fractal->x = 0;
	fractal->y = 0;
	while (fractal->y < WIDTH)
	{
		while (fractal->x < HIGH)
		{
			
			calculate_mandelbrot(fractal);
			fractal->x++;
		}
		fractal->y++;
		fractal->x = 0;
	}
	mlx_put_image_to_window(fractal->mlx, fractal->window,
		fractal->image, 0, 0);
	return (0);
}

int	draw_julia(t_fractal *fractal)
{
	fractal->x = 0;
	fractal->y = 0;
	while (fractal->x < HIGH)
	{
		while (fractal->y < HIGH)
		{
			calculate_julia(fractal);
			fractal->y++;
		}
		fractal->x++;
		fractal->y = 0;
	}
	mlx_put_image_to_window(fractal->mlx, fractal->window,
		fractal->image, 0, 0);
	return (0);
}

int	draw_tricorn(t_fractal *fractal)
{
	fractal->x = 0;
	fractal->y = 0;
	while (fractal->x < HIGH)
	{
		while (fractal->y < HIGH)
		{
			calculate_tricorn(fractal);
			fractal->y++;
		}
		fractal->x++;
		fractal->y = 0;
	}
	mlx_put_image_to_window(fractal->mlx, fractal->window,
		fractal->image, 0, 0);
	return (0);
}
