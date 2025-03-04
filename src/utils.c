/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgrigorj <jgrigorj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 22:09:38 by jgrigorj          #+#    #+#             */
/*   Updated: 2025/03/04 22:02:12 by jgrigorj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// Image data are stored in a 1D array. The pixel_index represents pixel 
// position in this 1D array (in bytes) given the width and height
//  of the image and the pixel position in a 2D array.
// bpp: bits per pixel (4 bytes in ARGB format)
void	put_pixel_to_img(t_frac *frac, int x, int y, int color)
{
	// int		bpp;
	// int		line_size;
	// int		endian;
	int		pixel_index;
	char	*img_data;

	img_data = mlx_get_data_addr(frac->img_ptr, &frac->bpp, &frac->line_size, &frac->endian);
	pixel_index = (y * frac->line_size) + (x * frac->bpp / 8);
	*(unsigned int *)(img_data + pixel_index) = color;
}

void	copy_image(t_frac *frac, int old_width, int old_height)
{
	int		*old_pixels;
	int		*new_pixels;
	int		x;
	int		y;
	void	*img_copy;

	// Get the pixel data of the original image
	old_pixels = (int *)mlx_get_data_addr(frac->img_ptr, &frac->bpp, &frac->line_size, &frac->endian);

	// Create a new image with the new dimensions
	img_copy = mlx_new_image(frac->mlx_ptr, frac->width, frac->height);
	if (!img_copy)
		return ;

	// Get the pixel data of the new image
	new_pixels = (int *)mlx_get_data_addr(img_copy, &frac->bpp, &frac->line_size, &frac->endian);

	// Copy the pixels from the original image to the new image (preserving coordinates)
	y = -1;
	while (++y < frac->height)
	{
		x = -1;
		while (++x < frac->width)
		{
			if (x < old_width && y < old_height)
			{
				// Copy the pixel value from the original image to the new image
				new_pixels[y * frac->width + x] = old_pixels[y * old_width + x];
			}
			else
				new_pixels[y * frac->width + x] = 0x00000000;  // Transparent black

		}
	}
	mlx_destroy_image(frac->mlx_ptr, frac->img_ptr);
	frac->img_ptr = img_copy;
	draw_fractal_part(frac, old_width, old_height);
}
