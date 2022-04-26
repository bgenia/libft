/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stream_read.c                                   :+:      :+:    :+:   */
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
	_fill_read_buffer(t_stream *stream)
{
	ssize_t	result;

	result = ft_stream_direct_read(stream,
			stream->_read_buffer.data,
			stream->_read_buffer.capacity);
	if (result > 0 && (size_t)result < stream->_read_buffer.capacity)
		ft_stream_buffer_set_limit(&stream->_read_buffer, result);
	else
		ft_stream_buffer_set_limit(&stream->_read_buffer, SB_UNLIMITED);
	return (result);
}

static ssize_t
	_extract_and_direct_read(t_stream *stream, void *buffer, size_t size)
{
	t_stream_buffer	*read_buffer;
	ssize_t			available_bytes;

	read_buffer = &stream->_read_buffer;
	available_bytes = 0;
	if (read_buffer->cursor > 0)
	{
		available_bytes = read_buffer->size - read_buffer->cursor;
		ft_stream_buffer_extract(read_buffer, buffer, available_bytes);
		read_buffer->cursor = 0;
	}
	return (ft_stream_direct_read(stream,
			buffer + available_bytes,
			size - available_bytes));
}

static size_t
	_extract_available_and_fill(t_stream *stream, void *buffer)
{
	size_t	available_bytes;

	available_bytes = stream->_read_buffer.size - stream->_read_buffer.cursor;
	ft_stream_buffer_extract(&stream->_read_buffer, buffer, available_bytes);
	stream->_read_buffer.cursor = 0;
	return (_fill_read_buffer(stream));
}

static ssize_t
	_buffered_read(t_stream *stream, void *buffer, size_t size)
{
	ssize_t			result;
	size_t			available_bytes;
	size_t			read_bytes;

	result = 0;
	available_bytes = stream->_read_buffer.size - stream->_read_buffer.cursor;
	read_bytes = 0;
	if (size > available_bytes + stream->_read_buffer.size)
		return (_extract_and_direct_read(stream, buffer, size));
	if (stream->_read_buffer.cursor == 0)
		ft_ioguard(_fill_read_buffer(stream), &result);
	if (stream->has_error || stream->eof)
		return (result);
	if (size > available_bytes)
	{
		ft_ioguard(_extract_available_and_fill(stream, buffer), &result);
		if (stream->has_error || stream->eof)
			return (result);
		read_bytes = available_bytes;
	}
	ft_stream_buffer_extract(&stream->_read_buffer,
		buffer + read_bytes, size - read_bytes);
	stream->_read_buffer.cursor %= stream->_read_buffer.size;
	return (result);
}

ssize_t
	ft_stream_read(t_stream *stream, void *buffer, size_t size)
{
	ssize_t	result;

	if (!ft_stream_is_readable(stream))
		return (-1);
	if (size == 0)
		return (0);
	if (!stream->is_read_buffered)
		return (ft_stream_direct_read(stream, buffer, size));
	result = _buffered_read(stream, buffer, size);
	if (!stream->has_error)
	{
		stream->stats.bytes_received += size;
		return (size);
	}
	return (result);
}
