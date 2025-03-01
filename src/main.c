/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgrigorj <jgrigorj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 20:44:55 by jgrigorj          #+#    #+#             */
/*   Updated: 2025/03/01 23:14:51 by jgrigorj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	draw_fractal(t_frac *frac)
{
	int	i;

	i = -1;
	while (++i < 200)
		put_pixel_to_img(frac, i, 10, float_to_argb(i, 0, 200, frac));
	mlx_put_image_to_window(frac->mlx_ptr, frac->win_ptr, frac->img_ptr, 0, 0);
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
	// exit_fractal(frac);
    /* Setup hooks */ 
	mlx_hook(frac->win_ptr, 17, 0, &exit_fractal, frac);
	// mlx_loop_hook(frac->mlx_ptr, &draw_fractal, frac);
	mlx_key_hook(frac->win_ptr, &handle_input, frac);
	draw_fractal(frac);
	mlx_loop(frac->mlx_ptr);
}
