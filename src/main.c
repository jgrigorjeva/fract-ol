/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgrigorj <jgrigorj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 20:44:55 by jgrigorj          #+#    #+#             */
/*   Updated: 2025/02/28 01:09:22 by jgrigorj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	handle_no_event(void *frac)
{
    /* This function needs to exist, but it is useless for the moment */
	(void)frac;
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
	frac->win_ptr = mlx_new_window(frac->mlx_ptr, WINDOW_WIDTH,
			WINDOW_HEIGHT, "My first window!");
	if (frac->win_ptr == NULL)
	{
		exit_fractal(frac);
		return (1);
	}
	// exit_fractal(frac);
    /* Setup hooks */ 
	mlx_hook(frac->win_ptr, 17, 0, &exit_fractal, frac);
	mlx_loop_hook(frac->mlx_ptr, &handle_no_event, frac);
	mlx_key_hook(frac->win_ptr, &handle_input, frac);
	mlx_loop(frac->mlx_ptr);
}
