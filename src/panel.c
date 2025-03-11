/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   panel.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgrigorj <jgrigorj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 22:14:29 by jgrigorj          #+#    #+#             */
/*   Updated: 2025/03/11 17:28:15 by jgrigorj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw_panel(t_frac *frac)
{
	char	*panel_addr;
	int		x;
	int		y;

	panel_addr = mlx_get_data_addr(frac->panel_img_ptr, \
		&frac->bpp, &frac->line_size, &frac->endian);
	y = -1;
	while (++y < frac->panel_height)
	{
		x = -1;
		while (++x < frac->width)
			put_pixel_to_panel(frac, x, y, 0x333333);
	}
	mlx_put_image_to_window(frac->mlx_ptr, frac->win_ptr,
		frac->panel_img_ptr, 0, frac->height - frac->panel_height);
	if (frac->frac_type == 1)
		print_julia_text(frac);
	print_common_text(frac);
	(void)panel_addr;
}
