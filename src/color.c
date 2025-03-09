/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgrigorj <jgrigorj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 22:09:37 by jgrigorj          #+#    #+#             */
/*   Updated: 2025/03/09 22:54:43 by jgrigorj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	switch_colors(t_frac *frac)
{
	if (frac->color_switch == 2)
		frac->color_switch = 0;
	else
		frac->color_switch++;
}

t_color	interpolate_color(t_color start, t_color end, float t)
{
	t_color	result;

	result.r = (unsigned char)(start.r + (end.r - start.r) * t);
	result.g = (unsigned char)(start.g + (end.g - start.g) * t);
	result.b = (unsigned char)(start.b + (end.b - start.b) * t);
	return (result);
}

void	define_colors(t_color *colors, t_frac *frac)
{
	if (frac->color_switch == 0)
		define_col_rainbow(colors);
	if (frac->color_switch == 1)
		define_col_heatmap(colors);
	if (frac->color_switch == 2)
		define_col_ocean(colors);
}

// The pow(normalized, 3) expression changes the distribution from linear to exponential
t_color	get_gradient_color(float normalized, t_color *colors, t_frac *frac)
{
	float	section;
	float	t;
	int		color_index;
	t_color	start_color;
	t_color	end_color;

	section = pow(normalized, 2) * (frac->num_colors - 1);
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

	define_colors(colors, frac);
	if (value < min)
		return (0xFFFFFFFF);
	if (value > max)
		return (0xFF000000);
	normalized = (value - min) / (max - min);
	final_color = get_gradient_color(normalized, colors, frac);
	return ((255 << 24) | (final_color.r << 16) \
	| (final_color.g << 8) | final_color.b);
}