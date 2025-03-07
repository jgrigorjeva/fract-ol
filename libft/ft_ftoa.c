#include "libft.h"

char	*ft_ftoa(float num, int precision)
{
	int		int_part;
	float	frac_part;
	char	*int_str;
	char	*frac_str;
	char	*result;
	char	*dot;
	int		multiplier;

	// Handle integer part
	int_part = (int)num;
	int_str = ft_itoa(int_part);
	if (!int_str)
		return (NULL);

	// Handle fractional part
	if (num < 0)
		num = -num;
	frac_part = num - (float)int_part;
	multiplier = 1;
	for (int i = 0; i < precision; i++)
		multiplier *= 10;
	frac_str = ft_itoa((int)(frac_part * multiplier));
	if (!frac_str)
	{
		free(int_str);
		return (NULL);
	}

	// Join integer part, dot, and fraction
	dot = ft_strjoin(int_str, ".");
	result = ft_strjoin(dot, frac_str);
	free(int_str);
	free(frac_str);
	free(dot);

	return (result);
}
