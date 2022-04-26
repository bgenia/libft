/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stream_flush.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 00:28:02 by bgenia            #+#    #+#             */
/*   Updated: 2022/04/15 20:34:40 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>

#include <ft/io/stream/stream.h>
#include <ft/io/stream/stream_utils.h>

ssize_t
	ft_stream_flush(t_stream *stream)
{
	size_t	buffered_bytes;
	ssize_t	result;

	if (!stream->is_write_buffered)
		return (-1);
	buffered_bytes = stream->_write_buffer.cursor;
	result = ft_stream_direct_write(stream,
			stream->_write_buffer.data, buffered_bytes);
	if (!stream->has_error)
		stream->_write_buffer.cursor = 0;
	return (result);
}
