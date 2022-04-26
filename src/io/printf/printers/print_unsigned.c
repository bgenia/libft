/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 18:39:06 by bgenia            #+#    #+#             */
/*   Updated: 2022/04/15 20:02:19 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include <stdint.h>

#include <ft/io/output.h>

#include <ft/io/printf/placeholder.h>

int
	_ft_print_unsigned(
		t_stream *ostream,
		t_placeholder *ph,
		va_list args,
		ssize_t *n
	)
{
	uint32_t			value;
	ssize_t				result;
	int					base;
	t_integer_format	format;

	value = va_arg(args, uint32_t);
	if (ph->type & (TYPE_XL | TYPE_XU))
		base = 16;
	else if (ph->type & TYPE_O)
		base = 8;
	else if (ph->type & TYPE_B)
		base = 2;
	else
		base = 10;
	if (ph->type & TYPE_XU)
		format.capitalize = 1;
	else
		format.capitalize = 0;
	format.prefix = NULL;
	result = ft_putf_uint(ostream, value, base, format);
	return (ft_ioguard(result, n));
}
