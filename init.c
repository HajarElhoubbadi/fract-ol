/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hajel-ho <hajel-ho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 19:37:05 by hajel-ho          #+#    #+#             */
/*   Updated: 2025/04/27 14:03:31 by hajel-ho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_fractal(t_fractal *fractal)
{
	fractal->x = 0;
	fractal->y = 0;
	fractal->zoom = 1;
	fractal->max_iterations = 100;
	fractal->color = 0xFFF8DC;
	fractal->offset_x = 0.0;
	fractal->offset_y = 0.0;
}

void	init_mlx(t_fractal *fractal)
{
	fractal->mlx = mlx_init();
	if (!fractal->mlx)
	{
		write(2, "Error: MLX initialization failed\n", 33);
		exit_fractal(fractal);
	}
	fractal->window = mlx_new_window(fractal->mlx, SIZE, SIZE, fractal->name);
	if (!fractal->window)
	{
		write(2, "Error: Failed to create window\n", 31);
		exit_fractal(fractal);
	}
	fractal->image = mlx_new_image(fractal->mlx, SIZE, SIZE);
	if (!fractal->image)
	{
		write(2, "Error: Failed to create image\n", 30);
		exit_fractal(fractal);
	}
	fractal->pointer_to_image = mlx_get_data_addr(fractal->image,
			&fractal->bits_per_pixel, &fractal->size_line, &fractal->endian);
	if (!fractal->pointer_to_image)
	{
		write(2, "Error: Failed to get image address\n", 35);
		exit_fractal(fractal);
	}
}
