/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_signed.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 18:39:04 by bgenia            #+#    #+#             */
/*   Updated: 2022/04/15 20:02:19 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>

#include <ft/io/printf/placeholder.h>

#include <ft/io/output.h>

int
	_ft_print_signed(t_stream *ostream, va_list args, ssize_t *n)
{
	int		value;
	ssize_t	result;

	value = va_arg(args, int);
	result = ft_put_int(ostream, value, 10);
	return (ft_ioguard(result, n));
}
