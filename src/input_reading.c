/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_reading.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgrigorj <jgrigorj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 22:29:10 by jgrigorj          #+#    #+#             */
/*   Updated: 2025/03/19 22:09:29 by jgrigorj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	get_jul_cpart(t_frac *frac, char *text, char s)
{
	char	*input;

	ft_printf("Enter the %s(c)\n", text);
	input = get_next_line(0);
	if ((ft_atof(input) == 0 && !(input[0] == '0' || \
		input[0] == '+' || input[0] == '-')))
	{
		ft_printf("The parameter is invalid. Exiting program.\n");
		free (input);
		return (1);
	}
	if (s == 'r')
		frac->jul_cre = ft_atof(input);
	if (s == 'i')
		frac->jul_cim = ft_atof(input);
	free (input);
	return (0);
}

int	get_julia_param(t_frac *frac)
{
	ft_printf("Please, specify the c constant: c = Re(c) + i*Im(c)\n");
	if (get_jul_cpart(frac, "real part Re", 'r') == 1)
		ft_printf("The parameter is invalid, let's try 0.355 instead\n");
	if (get_jul_cpart(frac, "imaginary part Im", 'i') == 1)
		ft_printf("The parameter is invalid, let's try 0.355 instead\n");
	return (0);
}

int	choose_frac(t_frac *frac)
{
	char	*input;

	ft_printf("Please, select fractal. Press:\n");
	ft_printf("1 for Julia\n2 for Mandelbrot\n3 for Burning ship\n");
	ft_printf("Press any other key to exit\n");
	input = get_next_line(0);
	if ((ft_atoi(input) < 1 || ft_atoi(input) > 3))
	{
		ft_printf("No valid parameters provided (1 for Julia, 2 for Mandelbrot, \
			3 for Burning ship).\n Exiting program.\n");
		free (input);
		free (frac);
		exit (1);
	}
	frac->frac_type = ft_atoi(input);
	if (frac->frac_type == 1)
	{
		if (get_julia_param(frac))
		{
			free (input);
			free (frac);
			exit (1);
		}
	}
	free(input);
	return (0);
}
