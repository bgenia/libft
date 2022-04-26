/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vformat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 19:08:44 by bgenia            #+#    #+#             */
/*   Updated: 2022/04/15 20:02:19 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>

#include <ft/io/printf.h>
#include <ft/string/strstream.h>
#include <ft/math.h>

ssize_t
	ft_vformat(char *buffer, size_t size, const char *format, va_list args)
{
	t_stream	bufstream;
	ssize_t		result;

	if (size == 0)
		return (0);
	bufstream = ft_stream_open_string(buffer, 0, size, STREAM_MODE_O);
	if (!bufstream.is_valid)
		return (-1);
	result = ft_vsprintf(&bufstream, format, args);
	ft_stream_close(&bufstream);
	if (result != -1)
		buffer[ft_min(size - 1, result)] = '\0';
	return (result);
}
