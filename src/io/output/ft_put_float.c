/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_float.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 17:19:32 by bgenia            #+#    #+#             */
/*   Updated: 2022/04/15 20:02:19 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>

#include <ft/io/output.h>
#include <ft/string/string.h>
#include <ft/math.h>

static ssize_t
	_print_fraction(t_stream *ostream, double n, uint32_t precision)
{
	ssize_t		result;
	int			digit;
	uint32_t	i;

	result = 0;
	if (!ft_ioguard(ft_put_string(ostream, "."), &result))
		return (result);
	i = 0;
	while (i < precision)
	{
		n *= 10;
		digit = (int)n;
		n -= digit;
		if (i == precision - 1 && (int)(n * 10) % 10 >= 5)
			digit++;
		if (!ft_ioguard(ft_put_int(ostream, digit, 10), &result))
			break ;
		i++;
	}
	return (result);
}

static double
	_get_fraction(double n)
{
	int64_t	integer;
	double	fraction;

	integer = ft_abs((int64_t)n);
	if (n > 0)
		fraction = n - (double)integer;
	else
		fraction = (n + (double)integer) * -1;
	return (fraction);
}

// FIXME: Bad implementation, works good enough
// Does not work properly near LONGMAX+ values
ssize_t
	ft_put_float(t_stream *ostream, double value, uint32_t precision)
{
	ssize_t	result;
	int64_t	integer;
	double	fraction;

	if (value == INFINITY)
		return (ft_put_string(ostream, "inf"));
	if (value == -INFINITY)
		return (ft_put_string(ostream, "-inf"));
	if (isnan(value) && signbit(value) == 1)
		return (ft_put_string(ostream, "-nan"));
	if (isnan(value))
		return (ft_put_string(ostream, "nan"));
	result = 0;
	integer = (int64_t)value;
	fraction = _get_fraction(value);
	if (!ft_ioguard(ft_put_int(ostream, integer, 10), &result))
		return (result);
	if (precision == 0)
		return (result);
	if (!ft_ioguard(_print_fraction(ostream, fraction, precision), &result))
		return (result);
	return (result);
}
