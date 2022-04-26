/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 23:40:36 by bgenia            #+#    #+#             */
/*   Updated: 2022/04/15 20:02:19 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include <ft/io/printf.h>
#include <ft/io/output.h>
#include <ft/io/fdstream.h>

ssize_t
	ft_vprintf(const char *format, va_list args)
{
	return (ft_vdprintf(STDOUT_FILENO, format, args));
}

ssize_t
	ft_vdprintf(int fd, const char *format, va_list args)
{
	ssize_t		result;
	t_stream	sout;

	sout = ft_stream_open_fd(fd, STREAM_MODE_O, false);
	if (!sout.is_valid)
		return (-1);
	ft_stream_use_write_buffer(
		&sout,
		ft_stream_buffer_create_dynamic(FT_PRINTF_BUFFER_SIZE)
		);
	result = ft_vsprintf(&sout, format, args);
	ft_stream_close(&sout);
	if (sout.has_error)
		return (-1);
	return (result);
}

ssize_t
	ft_xvprintf(const char *format, va_list args)
{
	return (ft_xvdprintf(STDOUT_FILENO, format, args));
}

ssize_t
	ft_xvdprintf(int fd, const char *format, va_list args)
{
	char		buffer[FT_XPRINTF_BUFFER_SIZE];
	t_stream	sout;
	ssize_t		result;

	sout = ft_stream_open_fd(fd, STREAM_MODE_O, false);
	if (!sout.is_valid)
		return (-1);
	ft_stream_use_write_buffer(
		&sout,
		ft_stream_buffer_create_static(buffer, FT_XPRINTF_BUFFER_SIZE)
		);
	result = ft_vsprintf(&sout, format, args);
	ft_stream_close(&sout);
	if (sout.has_error)
		return (-1);
	return (result);
}
