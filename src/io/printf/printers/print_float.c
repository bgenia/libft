/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_float.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 17:24:51 by bgenia            #+#    #+#             */
/*   Updated: 2022/04/15 20:02:19 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include <stdint.h>

#include <ft/io/printf/placeholder.h>
#include <ft/io/output.h>
#include <ft/io/stream/stream.h>

int
	_ft_print_float(
		t_stream *ostream,
		t_placeholder *ph,
		va_list args,
		ssize_t *n
	)
{
	int		precision;
	double	value;
	ssize_t	result;

	if (ph->flags & FLAG_ARG_PRECISION)
		precision = va_arg(args, int);
	else if (ph->precision < 0)
		precision = 6;
	else
		precision = ph->precision;
	value = va_arg(args, double);
	result = ft_put_float(ostream, value, precision);
	return (ft_ioguard(result, n));
}
