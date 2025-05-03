/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hajel-ho <hajel-ho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 18:43:50 by hajel-ho          #+#    #+#             */
/*   Updated: 2025/05/03 12:40:45 by hajel-ho         ###   ########.fr       */
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

double	parsing(char *av)
{
	int		i;
	double	nb;
	double	div;
	int		sign;

	i = 0;
	nb = 0;
	div = 0.1;
	sign = 1;
	if (av[i] == '-' || av[i] == '+')
		if (av[i++] == '-')
			sign = -1;
	while (av[i] >= '0' && av[i] <= '9')
		nb = nb * 10 + (av[i++] - '0');
	if (av[i] == '.')
	{
		i++;
		while (av[i] >= '0' && av[i] <= '9')
		{
			nb += (av[i++] - '0') * div;
			div *= 0.1;
		}
	}
	return (nb * sign);
}
