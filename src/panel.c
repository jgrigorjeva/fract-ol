/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   panel.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgrigorj <jgrigorj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 22:14:29 by jgrigorj          #+#    #+#             */
/*   Updated: 2025/03/09 22:52:28 by jgrigorj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	print_julia_text(t_frac *frac)
{
	char	*julia_str1;
	char	*julia_str2;
	char	*julia_str3;
	char	*julia_re;
	char	*julia_im;

	julia_re = ft_ftoa(frac->jul_cre, 3);
	julia_im = ft_ftoa(frac->jul_cim, 3);
	julia_str1 = ft_strjoin("Current Julia parameter c = ", julia_re);
	julia_str2 = ft_strjoin(julia_str1, " + i*");
	julia_str3 = ft_strjoin(julia_str2, julia_im);
	mlx_string_put(frac->mlx_ptr, frac->win_ptr, 820, frac->height - frac->panel_height + 15, 0xFFFFFF, julia_str3);
	mlx_string_put(frac->mlx_ptr, frac->win_ptr, 1100, frac->height - frac->panel_height + 15, 0xFFFFFF, "To change c value press:");
	mlx_string_put(frac->mlx_ptr, frac->win_ptr, 820, frac->height - frac->panel_height + 30, 0xFFFFFF, "Re: (r) +0.1   (e) +0.01   (w) +0.001");
	mlx_string_put(frac->mlx_ptr, frac->win_ptr, 820, frac->height - frac->panel_height + 45, 0xFFFFFF, "    (f) -0.1   (d) -0.01   (s) -0.001");
	mlx_string_put(frac->mlx_ptr, frac->win_ptr, 1070, frac->height - frac->panel_height + 30, 0xFFFFFF, "Im: (i) +0.1   (u) +0.01   (y) +0.001");
	mlx_string_put(frac->mlx_ptr, frac->win_ptr, 1070, frac->height - frac->panel_height + 45, 0xFFFFFF, "    (k) -0.1   (j) -0.01   (h) -0.001");
	free (julia_re);
	free (julia_im);
	free (julia_str1);
	free (julia_str2);
	free (julia_str3);
}

void	print_common_text(t_frac *frac)
{
	char	*frac_type;

	if (frac->frac_type == 1)
		frac_type = ft_strdup("Julia");
	else if (frac->frac_type == 2)
		frac_type = ft_strdup("Mandelbrot");
	else
		frac_type = ft_strdup("Burning ship");
	if (!frac_type)
		return ;
	mlx_string_put(frac->mlx_ptr, frac->win_ptr, 20, frac->height - frac->panel_height + 15, 0xFFFFFF, "Displaying fractal type:");
	mlx_string_put(frac->mlx_ptr, frac->win_ptr, 185, frac->height - frac->panel_height + 15, 0xFFFFFF, frac_type);
	mlx_string_put(frac->mlx_ptr, frac->win_ptr, 20, frac->height - frac->panel_height + 30, 0xFFFFFF, "To change fractal type, press:");
	mlx_string_put(frac->mlx_ptr, frac->win_ptr, 20, frac->height - frac->panel_height + 45, 0xFFFFFF, "(1) for Julia, (2) for Mandelbrot, (3) for Burning ship");
	mlx_string_put(frac->mlx_ptr, frac->win_ptr, 280, frac->height - frac->panel_height + 15, 0xFFFFFF, "To change color scheme, press: (c)");

	free (frac_type);
}


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
	mlx_put_image_to_window(frac->mlx_ptr, frac->win_ptr, frac->panel_img_ptr, 0, frac->height - frac->panel_height);
	if (frac->frac_type == 1)
		print_julia_text(frac);
	print_common_text(frac);
	(void)panel_addr;
	
}