/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgrigorj <jgrigorj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 21:56:27 by jgrigorj          #+#    #+#             */
/*   Updated: 2025/03/09 22:05:16 by jgrigorj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// colors[0] = (t_color){255, 0, 0};    // Red
// colors[1] = (t_color){255, 127, 0};  // Orange
// colors[2] = (t_color){255, 255, 0};  // Yellow
// colors[3] = (t_color){0, 255, 0};    // Green
// colors[4] = (t_color){0, 255, 255};  // Cyan
// colors[5] = (t_color){0, 0, 255};    // Blue
// colors[6] = (t_color){128, 0, 128};  // Purple
void	define_col_rainbow(t_color *colors)
{
	colors[0] = (t_color){255, 0, 0};
	colors[1] = (t_color){255, 127, 0};
	colors[2] = (t_color){255, 255, 0};
	colors[3] = (t_color){0, 255, 0};
	colors[4] = (t_color){0, 255, 255};
	colors[5] = (t_color){0, 0, 255};
	colors[6] = (t_color){128, 0, 128};
}

// colors[0] = (t_color){0, 0, 0};       // Black
// colors[1] = (t_color){0, 0, 128};     // Dark Blue
// colors[2] = (t_color){75, 0, 130};    // Indigo
// colors[3] = (t_color){255, 0, 0};     // Red
// colors[4] = (t_color){255, 165, 0};   // Orange
// colors[5] = (t_color){255, 255, 0};   // Yellow
// colors[6] = (t_color){255, 255, 255}; // White
void	define_col_heatmap(t_color *colors)
{
	colors[0] = (t_color){0, 0, 0};
	colors[1] = (t_color){0, 0, 128};
	colors[2] = (t_color){75, 0, 130};
	colors[3] = (t_color){255, 0, 0};
	colors[4] = (t_color){255, 165, 0};
	colors[5] = (t_color){255, 255, 0};
	colors[6] = (t_color){255, 255, 255};
}

// colors[0] = (t_color){0, 0, 64};      // Deep Navy
// colors[1] = (t_color){0, 64, 128};    // Teal
// colors[2] = (t_color){0, 128, 128};   // Sea Green
// colors[3] = (t_color){0, 192, 192};   // Aqua
// colors[4] = (t_color){64, 224, 208};  // Turquoise
// colors[5] = (t_color){128, 255, 255}; // Light Cyan
// colors[6] = (t_color){255, 255, 255}; // White
void	define_col_ocean(t_color *colors)
{
	colors[0] = (t_color){0, 0, 64};
	colors[1] = (t_color){0, 64, 128};
	colors[2] = (t_color){0, 128, 128};
	colors[3] = (t_color){0, 192, 192};
	colors[4] = (t_color){64, 224, 208};
	colors[5] = (t_color){128, 255, 255};
	colors[6] = (t_color){255, 255, 255};
}
