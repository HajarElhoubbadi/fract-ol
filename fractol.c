/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hajel-ho <hajel-ho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 12:27:22 by hajel-ho          #+#    #+#             */
/*   Updated: 2025/05/01 20:20:47 by hajel-ho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	check_args(int argc, char **argv)
{
	if ((argc == 2 && (!ft_strcmp(argv[1], "mandelbrot")
				|| !ft_strcmp(argv[1], "tricorn")))
		|| (argc == 4 && !ft_strcmp(argv[1], "julia")))
		return (1);
	write(2, "./fractol mandelbrot\n", 21);
	write(2, "./fractol tricorn\n", 18);
	write(2, "./fractol julia <real> <imaginary>\n", 35);
	return (0);
}

int	handle_julia(t_fractal *f, char **argv)
{
	if (!is_number(argv[2]) || !is_number(argv[3]))
	{
		write(2, "Error\n", 6);
		free(f);
		exit(1);
	}
	f->cr = ft_atof(argv[2]);
	f->ci = ft_atof(argv[3]);
	return (1);
}

int	main(int argc, char **argv)
{
	t_fractal	*f;

	if (!check_args(argc, argv))
		return (1);
	f = malloc(sizeof(t_fractal));
	if (!f)
		return (1);
	f->name = argv[1];
	if (!ft_strcmp(f->name, "julia"))
		handle_julia(f, argv);
	init_fractal(f);
	init_mlx(f);
	mlx_key_hook(f->window, key_hook, f);
	mlx_mouse_hook(f->window, mouse_hook, f);
	mlx_hook(f->window, 17, 0, exit_fractal, f);
	draw_fractal(f, f->name);
	mlx_loop(f->mlx);
	return (0);
}
