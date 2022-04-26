/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_value.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 18:39:07 by bgenia            #+#    #+#             */
/*   Updated: 2022/04/15 20:02:19 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>

#include <ft/io/stream/stream.h>

#include <ft/io/printf/placeholder.h>
#include <ft/io/printf/printers.h>

int
	_ft_print_value(
		t_stream *ostream,
		t_placeholder *ph,
		va_list args,
		ssize_t *n
	)
{
	if (ph->type & TYPE_C)
		return (_ft_print_character(ostream, args, n));
	if (ph->type & (TYPE_S | TYPE_FS))
		return (_ft_print_string(ostream, ph, args, n));
	if (ph->type & TYPE_DI)
		return (_ft_print_signed(ostream, args, n));
	if (ph->type & (TYPE_U | TYPE_B | TYPE_O | TYPE_XL | TYPE_XU))
		return (_ft_print_unsigned(ostream, ph, args, n));
	if (ph->type & TYPE_P)
		return (_ft_print_pointer(ostream, args, n));
	if (ph->type & TYPE_F)
		return (_ft_print_float(ostream, ph, args, n));
	return (0);
}
