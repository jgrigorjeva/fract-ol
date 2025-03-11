/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgrigorj <jgrigorj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 22:09:38 by jgrigorj          #+#    #+#             */
/*   Updated: 2025/03/11 17:31:08 by jgrigorj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// Image data are stored in a 1D array. The pixel_index represents pixel 
// position in this 1D array (in bytes) given the width and height
//  of the image and the pixel position in a 2D array.
// bpp: bits per pixel (4 bytes in ARGB format)
void	put_pixel_to_img(t_frac *frac, int x, int y, int color)
{
	int		pixel_index;
	char	*img_data;

	img_data = mlx_get_data_addr(frac->img_ptr, &frac->bpp, \
		&frac->line_size, &frac->endian);
	pixel_index = (y * frac->line_size) + (x * frac->bpp / 8);
	*(unsigned int *)(img_data + pixel_index) = color;
}

void	put_pixel_to_panel(t_frac *frac, int x, int y, int color)
{
	int		pixel_index;
	char	*img_data;

	img_data = mlx_get_data_addr(frac->panel_img_ptr, &frac->bpp, \
		&frac->line_size, &frac->endian);
	pixel_index = (y * frac->line_size) + (x * frac->bpp / 8);
	*(unsigned int *)(img_data + pixel_index) = color;
}
