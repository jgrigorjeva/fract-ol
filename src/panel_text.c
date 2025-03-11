/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   panel_text.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgrigorj <jgrigorj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 17:27:54 by jgrigorj          #+#    #+#             */
/*   Updated: 2025/03/11 17:28:23 by jgrigorj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	julia_text(char *julia_str, t_frac *frac)
{
	mlx_string_put(frac->mlx_ptr, frac->win_ptr, 820,
		frac->height - frac->panel_height + 15, 0xFFFFFF, julia_str);
	mlx_string_put(frac->mlx_ptr, frac->win_ptr, 1150,
		frac->height - frac->panel_height + 15, 0xFFFFFF,
		"To change c value press:");
	mlx_string_put(frac->mlx_ptr, frac->win_ptr, 820,
		frac->height - frac->panel_height + 30, 0xFFFFFF,
		"Re: (r) +0.1   (e) +0.01   (w) +0.001");
	mlx_string_put(frac->mlx_ptr, frac->win_ptr, 820,
		frac->height - frac->panel_height + 45, 0xFFFFFF,
		"    (f) -0.1   (d) -0.01   (s) -0.001");
	mlx_string_put(frac->mlx_ptr, frac->win_ptr, 1070,
		frac->height - frac->panel_height + 30, 0xFFFFFF,
		"Im: (i) +0.1   (u) +0.01   (y) +0.001");
	mlx_string_put(frac->mlx_ptr, frac->win_ptr, 1070,
		frac->height - frac->panel_height + 45, 0xFFFFFF,
		"    (k) -0.1   (j) -0.01   (h) -0.001");
}

void	print_julia_text(t_frac *frac)
{
	char	*julia_str1;
	char	*julia_str2;
	char	*julia_str3;
	char	*julia_re;
	char	*julia_im;

	julia_re = ft_ftoa(frac->jul_cre, 4);
	julia_im = ft_ftoa(frac->jul_cim, 4);
	julia_str1 = ft_strjoin("Current Julia parameter c = ", julia_re);
	julia_str2 = ft_strjoin(julia_str1, " + i*");
	julia_str3 = ft_strjoin(julia_str2, julia_im);
	julia_text(julia_str3, frac);
	free (julia_re);
	free (julia_im);
	free (julia_str1);
	free (julia_str2);
	free (julia_str3);
}

void	fractal_text(char *frac_type, t_frac *frac)
{
	mlx_string_put(frac->mlx_ptr, frac->win_ptr, 20,
		frac->height - frac->panel_height + 15, 0xFFFFFF,
		"Displaying fractal type:");
	mlx_string_put(frac->mlx_ptr, frac->win_ptr, 185,
		frac->height - frac->panel_height + 15, 0xFFFFFF, frac_type);
	mlx_string_put(frac->mlx_ptr, frac->win_ptr, 20,
		frac->height - frac->panel_height + 30, 0xFFFFFF,
		"To change fractal type, press:");
	mlx_string_put(frac->mlx_ptr, frac->win_ptr, 20,
		frac->height - frac->panel_height + 45, 0xFFFFFF,
		"(1) for Julia, (2) for Mandelbrot, (3) for Burning ship");
	mlx_string_put(frac->mlx_ptr, frac->win_ptr, 400,
		frac->height - frac->panel_height + 15, 0xFFFFFF,
		"To change color scheme, press: (c)");
}

void	iteration_text(char *iter_num, t_frac *frac)
{
	mlx_string_put(frac->mlx_ptr, frac->win_ptr, 400,
		frac->height - frac->panel_height + 30, 0xFFFFFF, "Max iterations: ");
	mlx_string_put(frac->mlx_ptr, frac->win_ptr, 500,
		frac->height - frac->panel_height + 30, 0xFFFFFF, iter_num);
	mlx_string_put(frac->mlx_ptr, frac->win_ptr, 500,
		frac->height - frac->panel_height + 45, 0xFFFFFF,
		"press (9) or (0) to change by 50");
}

void	print_common_text(t_frac *frac)
{
	char	*frac_type;
	char	*iter_num;

	if (frac->frac_type == 1)
		frac_type = ft_strdup("Julia");
	else if (frac->frac_type == 2)
		frac_type = ft_strdup("Mandelbrot");
	else
		frac_type = ft_strdup("Burning ship");
	if (!frac_type)
		return ;
	fractal_text(frac_type, frac);
	free (frac_type);
	iter_num = ft_itoa(frac->max_iter);
	if (!iter_num)
		return ;
	iteration_text(iter_num, frac);
	free (iter_num);
	mlx_string_put(frac->mlx_ptr, frac->win_ptr, 1370,
		frac->height - frac->panel_height + 15, 0xFFFFFF,
		"Restore zoom level: (z)");
}
