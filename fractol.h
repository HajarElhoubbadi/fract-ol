/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hajel-ho <hajel-ho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 12:27:44 by hajel-ho          #+#    #+#             */
/*   Updated: 2025/04/27 14:27:20 by hajel-ho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <mlx.h>
# include <stdlib.h>
# include <unistd.h>

# define SIZE 800
# define WIDTH 800

# define ESC 53
# define UP 126
# define DOWN 125
# define LEFT 123
# define RIGHT 124
# define C 8

# define SCROLL_UP 4
# define SCROLL_DOWN 5

typedef struct s_fractal
{
	void	*mlx;
	void	*window;
	void	*image;
	char	*pointer_to_image;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
	int		x;
	int		y;
	double	zre;
	double	zim;
	double	cre;
	double	cim;
	int		color;
	double	offset_x;
	double	offset_y;
	double	zoom;
	char	*name;
	int		max_iterations;
}			t_fractal;

int		exit_fractal(t_fractal *fractal);
int		key_hook(int key_code, t_fractal *fractal);
int		mouse_hook(int mouse_code, int x, int y, t_fractal *fractal);
void	zoom(t_fractal *fractal, int x, int y, int zoom);
int		draw_mandelbrot(t_fractal *fractal);
int		draw_julia(t_fractal *fractal);
int		draw_tricorn(t_fractal *fractal);
void	init_fractal(t_fractal *fractal);
void	init_mlx(t_fractal *fractal);
double	ft_atof(char *str);
void	calculate_julia(t_fractal *fractal);
void	calculate_mandelbrot(t_fractal *fractal);
void	calculate_tricorn(t_fractal *fractal);
int		ft_strcmp(char *s1, char *s2);
double	generate_random_c(void);
int		move_julia(int x, int y, t_fractal *ptr);
void	put_color_to_pixel(t_fractal *fractal, int x, int y, int color);
void	change_iterations(t_fractal *fractal, int key_code);
int		draw_fractal(t_fractal *fractal, char *query);
int		is_number(char *s);
double	scale(double pixel, double min, double max, int size);

#endif