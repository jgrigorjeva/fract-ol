/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgrigorj <jgrigorj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 22:28:26 by jgrigorj          #+#    #+#             */
/*   Updated: 2025/03/07 22:12:38 by jgrigorj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	exit_fractal(t_frac *frac)
{
	if (frac->img_ptr)
		mlx_destroy_image(frac->mlx_ptr, frac->img_ptr);
	if (frac->panel_img_ptr)
		mlx_destroy_image(frac->mlx_ptr, frac->panel_img_ptr);
	mlx_destroy_window(frac->mlx_ptr, frac->win_ptr);
	mlx_destroy_display(frac->mlx_ptr);
	free(frac->mlx_ptr);
	free(frac);
	exit(0);
	return (0);
}
