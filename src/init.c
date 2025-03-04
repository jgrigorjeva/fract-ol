/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgrigorj <jgrigorj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 22:22:45 by jgrigorj          #+#    #+#             */
/*   Updated: 2025/03/04 16:55:23 by jgrigorj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_frac	*init_frac(void)
{
	t_frac	*frac;

	frac = (t_frac *)malloc(sizeof(t_frac));
	if (!frac)
		return (NULL);
	frac->mlx_ptr = NULL;
	frac->win_ptr = NULL;
	frac->img_ptr = NULL;
	frac->resize_dir_x = 0;
	frac->resize_dir_y = 0;
	frac->resizing = 0;
	frac->drag_start_x = 0;
	frac->drag_start_y = 0;
	frac->frac_type = 0;
	frac->jul_cim = 0;
	frac->jul_cre = 0;
	frac->width = 900;
	frac->height = 600;
	frac->num_colors = 7;
	frac->max_iter = 100;
	frac->scale = 4.0 / frac->width;
	frac->center_x = -0.5;
	frac->center_y = 0.0;
	return (frac);
}
