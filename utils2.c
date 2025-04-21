/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hajel-ho <hajel-ho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 18:43:50 by hajel-ho          #+#    #+#             */
/*   Updated: 2025/04/21 12:50:00 by hajel-ho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	is_digit(char c)
{
	return (c >= '0' && c <= '9');
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
		if (is_digit(s[i]))
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

double	ft_atof(char *s)
{
	int		i;
	double	nb;
	double	div;
	int		sign;

	i = 0;
	nb = 0;
	div = 0.1;
	sign = 1;
	if (s[i] == '-' || s[i] == '+')
		if (s[i++] == '-')
			sign = -1;
	while (s[i] >= '0' && s[i] <= '9')
		nb = nb * 10 + (s[i++] - '0');
	if (s[i] == '.')
	{
		i++;
		while (s[i] >= '0' && s[i] <= '9')
		{
			nb += (s[i++] - '0') * div;
			div *= 0.1;
		}
	}
	return (nb * sign);
}

int	kill_window(t_fractal *s_fractal)
{
	mlx_destroy_image(s_fractal->mlx, s_fractal->image);
	mlx_destroy_window(s_fractal->mlx, s_fractal->window);
	free (s_fractal);
	exit(0);
}
