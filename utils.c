/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hajel-ho <hajel-ho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 18:01:44 by hajel-ho          #+#    #+#             */
/*   Updated: 2025/05/03 14:31:00 by hajel-ho         ###   ########.fr       */
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
