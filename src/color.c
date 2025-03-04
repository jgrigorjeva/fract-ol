/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgrigorj <jgrigorj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 22:09:37 by jgrigorj          #+#    #+#             */
/*   Updated: 2025/03/03 22:46:18 by jgrigorj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_color	interpolate_color(t_color start, t_color end, float t)
{
	t_color	result;

	result.r = (unsigned char)(start.r + (end.r - start.r) * t);
	result.g = (unsigned char)(start.g + (end.g - start.g) * t);
	result.b = (unsigned char)(start.b + (end.b - start.b) * t);
	return (result);
}

// colors[0] = (t_color){255, 0, 0};    // Red
// colors[1] = (t_color){255, 127, 0};  // Orange
// colors[2] = (t_color){255, 255, 0};  // Yellow
// colors[3] = (t_color){0, 255, 0};    // Green
// colors[4] = (t_color){0, 255, 255};  // Cyan
// colors[5] = (t_color){0, 0, 255};    // Blue
// colors[6] = (t_color){128, 0, 128};  // Purple
void	define_colors(t_color *colors)
{
	colors[0] = (t_color){255, 0, 0};
	colors[1] = (t_color){255, 127, 0};
	colors[2] = (t_color){255, 255, 0};
	colors[3] = (t_color){0, 255, 0};
	colors[4] = (t_color){0, 255, 255};
	colors[5] = (t_color){0, 0, 255};
	colors[6] = (t_color){128, 0, 128};
}

// The pow(normalized, 3) expression changes the distribution from linear to exponential
t_color	get_gradient_color(float normalized, t_color *colors, t_frac *frac)
{
	float	section;
	float	t;
	int		color_index;
	t_color	start_color;
	t_color	end_color;

	section = pow(normalized, 3) * (frac->num_colors - 1);
	color_index = (int)section;
	t = section - color_index;
	start_color = colors[color_index];
	end_color = colors[color_index + 1];
	return (interpolate_color(start_color, end_color, t));
}

// Function to map the float value to ARGB
// values outside the (min, max) range are mapped to black and white
// values inside the (min, max) range are mapped onto rainbow colors
// Values are first normalized: min -> 0, max -> 1
// 0 corresponds to red, 1 corresponds to purple
// // alpha is constant 
unsigned int	float_to_argb(float value, float min, float max, t_frac *frac)
{
	float	normalized;
	t_color	colors[7];
	t_color	final_color;

	define_colors(colors);
	if (value < min)
		return (0xFFFFFFFF);
	if (value > max)
		return (0xFF000000);
	normalized = (value - min) / (max - min);
	final_color = get_gradient_color(normalized, colors, frac);
	return ((255 << 24) | (final_color.r << 16) \
	| (final_color.g << 8) | final_color.b);
}