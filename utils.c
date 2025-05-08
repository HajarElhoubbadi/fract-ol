/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hajel-ho <hajel-ho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 18:01:44 by hajel-ho          #+#    #+#             */
/*   Updated: 2025/05/08 15:19:38 by hajel-ho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	exit_fractal(t_fractal *f)
{
	mlx_destroy_image(f->mlx, f->image);
	mlx_destroy_window(f->mlx, f->window);
	free(f->mlx);
	free(f);
	exit(1);
	return (0);
}

void	put_color_to_pixel(t_fractal *f, int x, int y, int color)
{
	char	*buffer;

	buffer = f->pointer_to_addr + ((y * f->size_line)
			+ (x *(f->bits_per_pixel / 8)));
	*(unsigned int *)buffer = color;
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
	{
		i++;
	}
	return ((unsigned char )s1[i] - (unsigned char)s2[i]);
}

int	is_number(char *s)
{
	int	i;
	int	dot;
	int	digit;

	i = 0;
	dot = 0;
	digit = 0;
	if (!s || !*s)
		return (0);
	if (s[i] == '-' || s[i] == '+')
		i++;
	while (s[i])
	{
		if (s[i] >= '0' && s[i] <= '9')
			digit = 1;
		else if (s[i] == '.' && !dot)
			dot = 1;
		else
			return (0);
		i++;
	}
	if (!digit || (dot && s[i - 1] == '.'))
		return (0);
	return (1);
}

double	parsing(char *s)
{
	int		i;
	double	res;
	double	div;
	int		sign;

	i = 0;
	res = 0;
	div = 0.1;
	sign = 1;
	if (s[i] == '-' || s[i] == '+')
		if (s[i++] == '-')
			sign = -1;
	while (s[i] >= '0' && s[i] <= '9')
		res = res * 10 + (s[i++] - '0');
	if (s[i] == '.')
	{
		i++;
		while (s[i] >= '0' && s[i] <= '9')
		{
			res = res + (s[i++] - '0') * div;
			div = div * 0.1;
		}
	}
	return (res * sign);
}
