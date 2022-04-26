/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stream_open_memory.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 13:06:39 by bgenia            #+#    #+#             */
/*   Updated: 2022/04/15 20:02:19 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft/io/stream/stream.h>
#include <ft/math.h>
#include <ft/string/string.h>

static ssize_t
	_memstream_read(t_stream_context *context, void *buffer, size_t size)
{
	size_t	remaining_size;
	size_t	read_size;

	remaining_size = context->size - context->cursor;
	read_size = ft_minu(size, remaining_size);
	ft_memmove(buffer, &context->data[context->cursor], read_size);
	context->cursor += read_size;
	return (read_size);
}

static ssize_t
	_memstream_write(t_stream_context *context, const char *buffer, size_t size)
{
	size_t	remaining_size;
	size_t	write_size;

	remaining_size = context->size - context->cursor;
	write_size = ft_minu(size, remaining_size);
	ft_memmove(&context->data[context->cursor], buffer, write_size);
	context->cursor += write_size;
	return (write_size);
}

t_stream
	ft_stream_open_memory(
		void *data,
		size_t offset,
		size_t size,
		t_stream_mode mode
	)
{
	t_stream	stream;

	stream = ft_stream_create(!!data, mode);
	if (!stream.is_valid)
		return (stream);
	stream._context = (t_stream_context){
		.data = data, .cursor = offset, .size = size, .fd = -1
	};
	stream._hread = _memstream_read;
	stream._hwrite = _memstream_write;
	stream._hclose = NULL;
	return (stream);
}
