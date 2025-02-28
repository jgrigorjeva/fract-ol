/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgrigorj <jgrigorj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 22:22:45 by jgrigorj          #+#    #+#             */
/*   Updated: 2025/02/27 18:12:54 by jgrigorj         ###   ########.fr       */
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
	frac->frac_type = 0;
	frac->jul_cim = 0;
	frac->jul_cre = 0;
	return (frac);
}
