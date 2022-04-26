/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printers.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 18:38:47 by bgenia            #+#    #+#             */
/*   Updated: 2022/04/15 20:02:19 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTERS_H
# define PRINTERS_H

# include <stdarg.h>
# include <unistd.h>

# include <ft/io/stream/stream.h>

# include "placeholder.h"

int
_ft_print_value(
	t_stream *ostream,
	t_placeholder *pl,
	va_list args,
	ssize_t *n
	);

int
_ft_print_character(t_stream *ostream, va_list args, ssize_t *n);
int
_ft_print_string(
	t_stream *ostream,
	t_placeholder *ph,
	va_list args,
	ssize_t *n
	);
int
_ft_print_pointer(t_stream *ostream, va_list args, ssize_t *n);
int
_ft_print_signed(t_stream *ostream, va_list args, ssize_t *n);
int
_ft_print_unsigned(
	t_stream *ostream,
	t_placeholder *ph,
	va_list args,
	ssize_t *n
	);
int
_ft_print_float(
	t_stream *ostream,
	t_placeholder *ph,
	va_list args,
	ssize_t *n
	);

#endif
