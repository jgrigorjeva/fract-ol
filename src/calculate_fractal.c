/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_fractal.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgrigorj <jgrigorj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 20:21:07 by jgrigorj          #+#    #+#             */
/*   Updated: 2025/03/04 16:52:18 by jgrigorj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// takes pixel with coordinates px, py and calculates
//  the number o iterations needed to escape the mandelbrot set condition
//  The pixel is then printed with the corresponding color
void	calc_mandel(t_frac *frac, int px, int py)
{
	int		i;
	double	x;
	double	y;
	double	x_temp;

	x = 0;
	y = 0;
	frac->x0 = (px - frac->width / 2.0) * frac->scale + frac->center_x;
	frac->y0 = (py - frac->height / 2.0) * frac->scale + frac->center_y;
	i = -1;
	while (x * x + y * y <= 4 && ++i < frac->max_iter)
	{
		x_temp = x * x - y * y + frac->x0;
		y = 2 * x * y + frac->y0;
		x = x_temp;
	}
	if (i < frac->max_iter)
		put_pixel_to_img(frac, px, py, \
			float_to_argb(i, 0, 100, frac));
	else
		put_pixel_to_img(frac, px, py, 0xFF000000);
}