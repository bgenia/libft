/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 18:39:03 by bgenia            #+#    #+#             */
/*   Updated: 2022/04/15 20:02:19 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include <stdint.h>

#include <ft/io/output.h>

#include <ft/io/printf/placeholder.h>

int
	_ft_print_pointer(t_stream *ostream, va_list args, ssize_t *n)
{
	uint64_t	value;
	ssize_t		result;

	value = (uint64_t)va_arg(args, void *);
	result = ft_putf_uint(ostream, value, 16, (t_integer_format){
			.prefix = "0x",
			.capitalize = 0
		});
	return (ft_ioguard(result, n));
}
