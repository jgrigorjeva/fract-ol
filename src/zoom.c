/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgrigorj <jgrigorj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 15:07:08 by jgrigorj          #+#    #+#             */
/*   Updated: 2025/03/11 16:58:17 by jgrigorj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// The mouse_x (mouse_y) variable represents the mouse 
// position in the fractal (complex) coordinates.
int	mouse_zoom(int mouse_code, int x, int y, t_frac *frac)
{
	double	zoom_factor;
	double	mouse_x;
	double	mouse_y;

	if (mouse_code == 4)
		zoom_factor = 0.9;
	else if (mouse_code == 5)
		zoom_factor = 1.1;
	else
		return (0);
	mouse_x = (x - frac->width / 2.0) * (4.0 / frac->width) + frac->center_x;
	mouse_y = (y - frac->height / 2.0) * (4.0 / frac->height) + frac->center_y;
	frac->scale *= zoom_factor;
	frac->center_x = mouse_x + (frac->center_x - mouse_x) * zoom_factor;
	frac->center_y = mouse_y + (frac->center_y - mouse_y) * zoom_factor;
	draw_fractal(frac);
	return (0);
}
