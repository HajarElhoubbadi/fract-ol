/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hajel-ho <hajel-ho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 12:27:44 by hajel-ho          #+#    #+#             */
/*   Updated: 2025/05/02 18:49:19 by hajel-ho         ###   ########.fr       */
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
	char	*pointer_to_addr;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
	int		x;
	int		y;
	double	zr;
	double	zi;
	double	cr;
	double	ci;
	int		color;
	double	offset_x;
	double	offset_y;
	double	zoom;
	char	*name;
	int		max_iterations;
}			t_fractal;

int		exit_fractal(t_fractal *f);
int		key_hook(int key_code, t_fractal *f);
int		mouse_hook(int mouse_code, int x, int y, t_fractal *f);
void	zoom(t_fractal *f, int x, int y, int zoom);
int		draw_mandelbrot(t_fractal *f);
int		draw_julia(t_fractal *f);
int		draw_tricorn(t_fractal *f);
void	init_fractal(t_fractal *f);
void	init_mlx(t_fractal *f);
double	ft_atof(char *str);
void	calculate_julia(t_fractal *f);
void	calculate_mandelbrot(t_fractal *f);
void	calculate_tricorn(t_fractal *f);
int		ft_strcmp(char *s1, char *s2);
double	generate_random_c(void);
void	put_color_to_pixel(t_fractal *f, int x, int y, int color);
int		draw_fractal(t_fractal *f, char *name);
int		is_number(char *s);
double	scale(double pixel, double min, double max, int size);

#endif