/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hajel-ho <hajel-ho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 19:37:05 by hajel-ho          #+#    #+#             */
/*   Updated: 2025/04/21 12:42:59 by hajel-ho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_fractal(t_fractal *fractal)
{
	fractal->x = 0;
	fractal->y = 0;
	fractal->color = 0xffffff;
	fractal->zoom = 300;
	if (ft_strcmp(fractal->name, "mandelbrot") == 0)
	{
		fractal->offset_x = -2.10;
		fractal->offset_y = -1.50;
	}
	else if (ft_strcmp(fractal->name, "julia") == 0)
	{
		fractal->offset_x = -1.60;
		fractal->offset_y = -1.50;
	}
	else if (ft_strcmp(fractal->name, "tricorn") == 0)
	{
		fractal->offset_x = -2.10;
		fractal->offset_y = -1.50;
	}
	fractal->max_iterations = 42;
}

void	init_mlx(t_fractal *fractal)
{
	fractal->mlx = mlx_init();
	if (fractal->mlx == NULL)
	{
		free(fractal->mlx);
		free(fractal);
		write(2, "There was a problem\n", 20);
		exit(1);
	}
	fractal->window = mlx_new_window(fractal->mlx, SIZE, SIZE, fractal->name);
	if (fractal->window == NULL)
	{
		free(fractal->window);
		free(fractal->mlx);
		write(2, "There was a problem creating the window\n", 40);
		exit(1);
	}
	fractal->image = mlx_new_image(fractal->mlx, SIZE, SIZE);
	fractal->pointer_to_image = mlx_get_data_addr
		(fractal->image, &fractal->bits_per_pixel,
			&fractal->size_line, &fractal->endian);
}
