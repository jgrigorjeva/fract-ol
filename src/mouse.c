/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgrigorj <jgrigorj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 22:36:43 by jgrigorj          #+#    #+#             */
/*   Updated: 2025/03/10 00:06:05 by jgrigorj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// The resize zone is defined around the right and bottom edges
// The mouse cursor should be within the EDGE_TRESHOLD from the edge
// Return values:
// 3 for the Bottom-right corner
// 1 for Right edge
// 2 for Bottom edge
// 0 for Not in resize zone
int	is_in_resize_zone(int x, int y, t_frac *frac)
{
	int	near_right;
	int	near_bottom;

	near_right = (x >= frac->width - EDGE_THRESHOLD \
		&& x <= frac->width + EDGE_THRESHOLD);
	near_bottom = (y >= frac->height - EDGE_THRESHOLD \
		&& y <= frac->height + EDGE_THRESHOLD);
	if (near_right && near_bottom)
		return (3);
	if (near_right)
		return (1);
	if (near_bottom)
		return (2);
	return (0);
}

// button == 1 // Left click
int	mouse_press(int button, int x, int y, t_frac *frac)
{
	int	zone;

	if (button == 1)
	{
		zone = is_in_resize_zone(x, y, frac);
		if (zone > 0)
		{
			frac->drag_start_x = x;
			frac->drag_start_y = y;
			frac->resize_dir_x = (zone == 1 || zone == 3);
			frac->resize_dir_y = (zone == 2 || zone == 3);
			frac->resizing = 1;
		}
	}
	return (0);
}

// When mouse is released, finalize the new size
// Prevent negative sizes: if (new_width < 50) new_width = 50;
//      					if (new_height < 50) new_height = 50;
int	mouse_release(int button, int x, int y, t_frac *frac)
{
	int	new_width;
	int	new_height;

	new_width = frac->width;
	new_height = frac->height;
	if (button == 1 && frac->resizing)
	{
		if (frac->resize_dir_x)
			new_width = frac->width + (x - frac->drag_start_x);
		if (frac->resize_dir_y)
			new_height = frac->height + (y - frac->drag_start_y);
		if (new_width < 50)
			new_width = 50;
		if (new_height < 50)
			new_height = 50;
		resize_window(frac, new_width, new_height);
		frac->resizing = 0;
	}
	return (0);
}

int	mouse_move(int x, int y, t_frac *frac)
{
	int	new_width;
	int	new_height;

	if (!frac->resizing)
		return (0);
	new_width = frac->width;
	new_height = frac->height;
	if (frac->resize_dir_x)
		new_width = frac->width + (x - frac->drag_start_x);
	if (frac->resize_dir_y)
		new_height = frac->height + (y - frac->drag_start_y);
	if (new_width < 50)
		new_width = 50;
	if (new_height < 50)
		new_height = 50;
	if (new_width != frac->width || new_height != frac->height)
		resize_window(frac, new_width, new_height);
	return (0);
}

void	resize_window(t_frac *frac, int new_width, int new_height)
{
	int	old_width;
	int	old_height;

	old_width = frac->width;
	old_height = frac->height;
	// frac->scale *= (double)frac->width / (double)new_width;
	frac->width = new_width;
	frac->height = new_height;
	copy_image(frac, old_width, old_height);
	// mlx_destroy_image(frac->mlx_ptr, frac->img_ptr);
	mlx_destroy_window(frac->mlx_ptr, frac->win_ptr);
	frac->win_ptr = mlx_new_window(frac->mlx_ptr, frac->width, \
		frac->height, "Resizable Window");
	// frac->img_ptr = mlx_new_image(frac->mlx_ptr, frac->width, frac->height);
	mlx_hook(frac->win_ptr, 17, 0, &exit_fractal, frac);  // Close window
	mlx_key_hook(frac->win_ptr, &handle_input, frac);     // Key press
	mlx_hook(frac->win_ptr, 4, 1L << 2, &mouse_press, frac);  // Mouse press
	mlx_hook(frac->win_ptr, 5, 1L << 3, &mouse_release, frac);  // Mouse release
	mlx_mouse_hook(frac->win_ptr, &mouse_zoom, frac); // Zooming
	ft_printf("resizing\n");
	draw_fractal(frac);
}

int handle_resize(t_frac *frac)
{
    int new_width;
    int new_height;

    mlx_get_screen_size(frac->mlx_ptr, &new_width, &new_height);  // Get new size

    // Only update if size changed
    if (new_width != frac->width || new_height != frac->height)
    {
        frac->width = new_width;
        frac->height = new_height;
        
        // Destroy old image
        mlx_destroy_image(frac->mlx_ptr, frac->img_ptr);
		mlx_destroy_image(frac->mlx_ptr, frac->panel_img_ptr);
        
        // Create new image with updated size
        frac->img_ptr = mlx_new_image(frac->mlx_ptr, frac->width, frac->height);
        frac->panel_img_ptr = mlx_new_image(frac->mlx_ptr, frac->width, frac->panel_height);
        // Redraw the fractal
        draw_fractal(frac);
		mlx_put_image_to_window(frac->mlx_ptr, frac->win_ptr, frac->img_ptr, 0, 0);
		draw_panel(frac);
    }
    return (0);
}