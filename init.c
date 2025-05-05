/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hajel-ho <hajel-ho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 19:37:05 by hajel-ho          #+#    #+#             */
/*   Updated: 2025/05/05 12:32:36 by hajel-ho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_fractal(t_fractal *f)
{
	f->x = 0;
	f->y = 0;
	f->zoom = 1;
	f->max_iterations = 100;
	f->color = 0xFFF8DC;
	f->offset_x = 0;
	f->offset_y = 0;
}

void	init_mlx(t_fractal *f)
{
	f->mlx = mlx_init();
	if (!f->mlx)
	{
		write(2, "Error: MLX initialization failed\n", 33);
		exit_fractal(f);
	}
	f->window = mlx_new_window(f->mlx, WIDTH, SIZE, f->name);
	if (!f->window)
	{
		write(2, "Error: Failed to create window\n", 31);
		exit_fractal(f);
	}
	f->image = mlx_new_image(f->mlx, WIDTH, SIZE);
	if (!f->image)
	{
		write(2, "Error: Failed to create image\n", 30);
		exit_fractal(f);
	}
	f->pointer_to_addr = mlx_get_data_addr(f->image,
			&f->bits_per_pixel, &f->size_line, &f->endian);
	if (!f->pointer_to_addr)
	{
		write(2, "Error: Failed to get image address\n", 35);
		exit_fractal(f);
	}
}
