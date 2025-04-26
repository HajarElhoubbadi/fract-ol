/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hajel-ho <hajel-ho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 12:27:22 by hajel-ho          #+#    #+#             */
/*   Updated: 2025/04/26 14:16:54 by hajel-ho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	is_valid_args(int argc, char **argv)
{
	if (argc == 2 && !ft_strcmp(argv[1], "mandelbrot"))
		return (1);
	if (argc == 4 && !ft_strcmp(argv[1], "julia"))
		return (1);
	if (argc == 2 && !ft_strcmp(argv[1], "tricorn"))
		return (1);
	return (0);
}

void	setup_hooks(t_fractal *s_fractal)
{
	mlx_key_hook(s_fractal->window, key_hook, s_fractal);
	mlx_mouse_hook(s_fractal->window, mouse_hook, s_fractal);
	mlx_hook(s_fractal->window, 17, 0, kill_window, s_fractal);
}

t_fractal	*init_program(int argc, char **argv)
{
	t_fractal	*fractal;

	fractal = malloc(sizeof(t_fractal));
	if (!fractal)
		return (NULL);
	fractal->name = argv[1];
	if (!ft_strcmp(argv[1], "julia") && argc == 4)
	{
		if (!is_number(argv[2]) || !is_number(argv[3]))
		{
			write(2, "Error\n", 6);
			free(fractal);
			exit(1);
		}
		fractal->cre = ft_atof(argv[2]);
		fractal->cim = ft_atof(argv[3]);
	}
	init_fractal(fractal);
	init_mlx(fractal);
	return (fractal);
}

int	main(int argc, char **argv)
{
	t_fractal	*fractal;

	if (!is_valid_args(argc, argv))
	{
		write(2, "./fractol mandelbrot\n", 21);
		write(2, "./fractol tricorn\n", 18);
		write(2, "./fractol julia <real> <imaginary>\n", 35);
		return (1);
	}
	fractal = init_program(argc, argv);
	if (!fractal)
		return (1);
	setup_hooks(fractal);
	draw_fractal(fractal, fractal->name);
	mlx_loop(fractal->mlx);
	return (0);
}
