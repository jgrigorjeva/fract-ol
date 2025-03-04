/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgrigorj <jgrigorj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 20:44:55 by jgrigorj          #+#    #+#             */
/*   Updated: 2025/03/04 22:08:50 by jgrigorj         ###   ########.fr       */
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
			calc_mandel(frac, x, y);
	}
	mlx_put_image_to_window(frac->mlx_ptr, frac->win_ptr, frac->img_ptr, 0, 0);
	ft_printf("draw\n");
	return (0);
}

int	draw_fractal_part(t_frac *frac, int old_width, int old_height)
{
	int	x;
	int	y;

	x = -1;
	while (++x < frac->width)
	{
		y = -1;
		while (++y < frac->height)
		{
			if (x >= old_width || y >= old_height)
				calc_mandel(frac, x, y);
		}
	}
	mlx_put_image_to_window(frac->mlx_ptr, frac->win_ptr, frac->img_ptr, 0, 0);
	ft_printf("draw\n");
	return (0);
}

int	handle_input(int keysym, t_frac *frac)
{
	if (keysym == XK_Escape)
	{
		exit_fractal(frac);
		exit (0);
	}
	return (0);
}

int	main(void)
{
	t_frac	*frac;

	frac = init_frac();
	if (!frac)
		return (1);
	choose_frac(frac);
	frac->mlx_ptr = mlx_init();
	if (frac->mlx_ptr == NULL)
		return (1);
	frac->win_ptr = mlx_new_window(frac->mlx_ptr, frac->width,
			frac->height, "My first window!");
	if (frac->win_ptr == NULL)
	{
		exit_fractal(frac);
		return (1);
	}
	frac->img_ptr = mlx_new_image(frac->mlx_ptr, frac->width, frac->height);
	if (frac->img_ptr == NULL)
	{
		exit_fractal(frac);
		return (1);
	}

	
	mlx_hook(frac->win_ptr, 17, 0, &exit_fractal, frac);
	mlx_key_hook(frac->win_ptr, &handle_input, frac);
	mlx_hook(frac->win_ptr, 4, 1L << 2, &mouse_press, frac);
	mlx_hook(frac->win_ptr, 5, 1L << 3, &mouse_release, frac);
	mlx_hook(frac->win_ptr, 6, 1L << 6, &mouse_move, frac);
	mlx_mouse_hook(frac->win_ptr, &mouse_zoom, frac);

	// Draw fractal initially
	draw_fractal(frac);

	mlx_loop(frac->mlx_ptr);
}
