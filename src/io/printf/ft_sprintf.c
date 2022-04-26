/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 18:39:09 by bgenia            #+#    #+#             */
/*   Updated: 2022/04/15 20:02:19 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>

#include <ft/io/output.h>
#include <ft/string/string.h>

#include <ft/io/printf/placeholder.h>
#include <ft/io/printf/parser.h>
#include <ft/io/printf/printers.h>

static int
	_print_argument(
		t_stream *ostream,
		const char **format,
		va_list args,
		ssize_t *n
	)
{
	const char		*s;
	t_placeholder	placeholder;

	s = *format;
	_ft_parse_placeholder(format, &placeholder);
	if (placeholder.type == 0)
	{
		if (!ft_ioguard(ft_stream_write(ostream, s, *format - s), n))
			return (0);
	}
	else if (placeholder.type & TYPE_PERCENT)
	{
		if (!ft_ioguard(ft_put_character(ostream, '%'), n))
			return (0);
	}
	else
	{
		if (!_ft_print_value(ostream, &placeholder, args, n))
			return (0);
	}
	return (1);
}

ssize_t
	ft_vsprintf(t_stream *ostream, const char *format, va_list args)
{
	ssize_t	n;
	int		length;
	char	*next;

	if (!format)
		return (-1);
	n = 0;
	while (*format)
	{
		next = ft_strchr(format, '%');
		if (!next)
			next = ft_strchr(format, '\0');
		length = next - format;
		if (!ft_ioguard(ft_stream_write(ostream, format, length), &n))
			return (-1);
		format = next;
		if (*format == '%')
			if (!_print_argument(ostream, &format, args, &n))
				return (-1);
	}
	return (n);
}

ssize_t
	ft_sprintf(t_stream *ostream, const char *format, ...)
{
	va_list	args;
	ssize_t	result;

	va_start(args, format);
	result = ft_vsprintf(ostream, format, args);
	va_end(args);
	return (result);
}
