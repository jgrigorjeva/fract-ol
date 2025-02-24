/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgrigorj <jgrigorj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 22:28:26 by jgrigorj          #+#    #+#             */
/*   Updated: 2025/02/24 20:24:37 by jgrigorj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	exit_fractal(t_frac *frac)
{
	// mlx_destroy_image(frac->mlx_ptr, frac->image);
	mlx_destroy_window(frac->mlx_ptr, frac->win_ptr);
	mlx_destroy_display(frac->mlx_ptr);
	free(frac->mlx_ptr);
	free(frac);
	exit(0);
}