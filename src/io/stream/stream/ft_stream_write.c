/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stream_write.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 10:41:38 by bgenia            #+#    #+#             */
/*   Updated: 2022/04/15 20:02:19 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>

#include <ft/io/stream/stream.h>
#include <ft/io/stream/stream_utils.h>
#include <ft/string/string.h>

static ssize_t
	_flush_and_direct_write(t_stream *stream, const char *buffer, size_t size)
{
	ssize_t	result;

	result = 0;
	ft_ioguard(ft_stream_flush(stream), &result);
	if (stream->has_error)
		return (result);
	ft_ioguard(ft_stream_direct_write(stream, buffer, size), &result);
	return (result);
}

static ssize_t
	_buffered_write(t_stream *stream, const char *buffer, size_t size)
{
	ssize_t	result;
	size_t	available_bytes;
	size_t	written_bytes;

	result = 0;
	available_bytes = stream->_write_buffer.size - stream->_write_buffer.cursor;
	written_bytes = 0;
	if (size > available_bytes + stream->_write_buffer.size)
		return (_flush_and_direct_write(stream, buffer, size));
	if (size > available_bytes)
	{
		ft_stream_buffer_append(&stream->_write_buffer,
			buffer, available_bytes);
		ft_ioguard(ft_stream_flush(stream), &result);
		if (stream->has_error)
			return (result);
		written_bytes = available_bytes;
	}
	ft_stream_buffer_append(&stream->_write_buffer,
		&buffer[written_bytes], size - written_bytes);
	return (result);
}

ssize_t
	ft_stream_write(t_stream *stream, const char *buffer, size_t size)
{
	ssize_t	result;

	if (!ft_stream_is_writable(stream))
		return (-1);
	if (size == 0)
		return (0);
	if (!stream->is_write_buffered)
		return (ft_stream_direct_write(stream, buffer, size));
	result = _buffered_write(stream, buffer, size);
	if (!stream->has_error)
	{
		stream->stats.bytes_sent += size;
		return (size);
	}
	return (result);
}
