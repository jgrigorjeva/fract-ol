/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgrigorj <jgrigorj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 20:44:55 by jgrigorj          #+#    #+#             */
/*   Updated: 2025/03/11 17:08:41 by jgrigorj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	draw_fractal(t_frac *frac)
{
	int	x;
	int	y;

	x = -1;
	while (++x < frac->width)
	{
		y = -1;
		while (++y < frac->height)
		{
			if (frac->frac_type == 1)
				calc_julia(frac, x, y);
			if (frac->frac_type == 2)
				calc_mandel(frac, x, y);
			if (frac->frac_type == 3)
				calc_ship(frac, x, y);
		}
	}
	mlx_put_image_to_window(frac->mlx_ptr, frac->win_ptr, frac->img_ptr, 0, 0);
	draw_panel(frac);
	ft_printf("draw\n");
	return (0);
}

int	handle_expose(t_frac *frac)
{
	draw_fractal(frac);
	draw_panel(frac);
	return (0);
}

void	init_mlx_win_img(t_frac *frac)
{
	frac->mlx_ptr = mlx_init();
	if (frac->mlx_ptr == NULL)
		exit (1);
	frac->win_ptr = mlx_new_window(frac->mlx_ptr, frac->width,
			frac->height, "Let's explore some fractals!");
	if (frac->win_ptr == NULL)
	{
		exit_fractal(frac);
		exit (1);
	}
	frac->img_ptr = mlx_new_image(frac->mlx_ptr, frac->width, frac->height);
	if (frac->img_ptr == NULL)
	{
		exit_fractal(frac);
		exit (1);
	}
	frac->panel_img_ptr = mlx_new_image(frac->mlx_ptr, frac->width, \
		frac->panel_height);
	if (frac->panel_img_ptr == NULL)
	{
		exit_fractal(frac);
		exit (1);
	}
}

int	main(void)
{
	t_frac	*frac;

	frac = init_frac();
	if (!frac)
		return (1);
	choose_frac(frac);
	init_mlx_win_img(frac);
	mlx_hook(frac->win_ptr, 17, 0, &exit_fractal, frac);
	mlx_key_hook(frac->win_ptr, &handle_input, frac);
	mlx_mouse_hook(frac->win_ptr, &mouse_zoom, frac);
	mlx_hook(frac->win_ptr, 12, (1L << 15), &handle_expose, frac);
	draw_fractal(frac);
	mlx_loop(frac->mlx_ptr);
}
