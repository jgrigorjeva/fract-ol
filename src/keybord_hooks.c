/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_and_keys.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgrigorj <jgrigorj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 16:53:49 by jgrigorj          #+#    #+#             */
/*   Updated: 2025/03/11 16:54:19 by jgrigorj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	change_jul_const(int keysym, t_frac *frac)
{
	if (keysym == XK_r)
		frac->jul_cre += 0.1;
	else if (keysym == XK_e)
		frac->jul_cre += 0.01;
	else if (keysym == XK_w)
		frac->jul_cre += 0.001;
	else if (keysym == XK_f)
		frac->jul_cre -= 0.1;
	else if (keysym == XK_d)
		frac->jul_cre -= 0.01;
	else if (keysym == XK_s)
		frac->jul_cre -= 0.001;
	else if (keysym == XK_i)
		frac->jul_cim += 0.1;
	else if (keysym == XK_u)
		frac->jul_cim += 0.01;
	else if (keysym == XK_y)
		frac->jul_cim += 0.001;
	else if (keysym == XK_k)
		frac->jul_cim -= 0.1;
	else if (keysym == XK_j)
		frac->jul_cim -= 0.01;
	else if (keysym == XK_h)
		frac->jul_cim -= 0.001;
}

void	move_view(int keysym, t_frac *frac)
{
	double	move_step;

	move_step = frac->scale * 42;
	if (keysym == XK_Left)
		frac->center_x -= move_step;
	else if (keysym == XK_Right)
		frac->center_x += move_step;
	else if (keysym == XK_Up)
		frac->center_y -= move_step;
	else if (keysym == XK_Down)
		frac->center_y += move_step;
}

void	change_frac_type(int keysym, t_frac *frac)
{
	if (keysym == XK_1)
		frac->frac_type = 1;
	else if (keysym == XK_2)
		frac->frac_type = 2;
	else if (keysym == XK_3)
		frac->frac_type = 3;
}

int	handle_input(int keysym, t_frac *frac)
{
	if (keysym == XK_Escape)
	{
		exit_fractal(frac);
		exit (0);
	}
	change_jul_const(keysym, frac);
	move_view(keysym, frac);
	change_frac_type(keysym, frac);
	if (keysym == XK_c)
		switch_colors(frac);
	else if (keysym == XK_9)
		frac->max_iter += 50;
	else if (keysym == XK_0 && frac->max_iter > 50)
		frac->max_iter -= 50;
	else if (keysym == XK_z)
	{
		frac->scale = 4.0 / frac->width;
		frac->center_x = -0.5;
		frac->center_y = 0.0;
	}
	draw_fractal(frac);
	return (0);
}
