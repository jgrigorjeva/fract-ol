/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgrigorj <jgrigorj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 16:00:31 by jgrigorj          #+#    #+#             */
/*   Updated: 2025/03/11 17:29:26 by jgrigorj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../libft/libft.h"
# include <mlx.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <X11/keysym.h>
# include <math.h>

// Varibles	center_x, center_y represent the center of the visible area
//  in the complex plane (i. e. in the fractal coordinates).
// The variable scale represents the current zoom level.
// A smaller scale means a more zoomed-in view.
typedef struct s_frac
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	void	*panel_img_ptr;
	int		bpp;
	int		line_size;
	int		endian;
	int		color_switch;
	int		frac_type;
	double	jul_cre;
	double	jul_cim;
	int		width;
	int		height;
	int		panel_height;
	int		num_colors;
	int		max_iter;
	double	x0;
	double	y0;
	double	center_x;	
	double	center_y;
	double	scale;
}	t_frac;

typedef struct s_color
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
}	t_color;

// init
t_frac			*init_frac(void);

// cleanup
int				exit_fractal(t_frac *frac);

// input handling
int				choose_frac(t_frac *frac);
int				handle_input(int keysym, t_frac *frac);

// utils
void			put_pixel_to_img(t_frac *frac, int x, int y, int color);
void			put_pixel_to_panel(t_frac *frac, int x, int y, int color);
void			draw_panel(t_frac *frac);
void			print_common_text(t_frac *frac);
void			print_julia_text(t_frac *frac);

// colors
unsigned int	float_to_argb(float value, float min, float max, t_frac *frac);
void			switch_colors(t_frac *frac);
void			define_col_rainbow(t_color *colors);
void			define_col_heatmap(t_color *colors);
void			define_col_ocean(t_color *colors);

// fractal
int				draw_fractal(t_frac *frac);
void			calc_mandel(t_frac *frac, int px, int py);
void			calc_julia(t_frac *frac, int px, int py);
void			calc_ship(t_frac *frac, int px, int py);

// zooming
int				mouse_zoom(int mouse_code, int x, int y, t_frac *frac);

// keybord hooks
int				handle_input(int keysym, t_frac *frac);

#endif