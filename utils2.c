/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hajel-ho <hajel-ho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 18:43:50 by hajel-ho          #+#    #+#             */
/*   Updated: 2025/05/03 18:08:08 by hajel-ho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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
