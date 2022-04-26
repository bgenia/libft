/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stream_open_string.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 00:21:47 by bgenia            #+#    #+#             */
/*   Updated: 2022/04/15 20:02:19 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft/io/stream/stream.h>
#include <ft/string/string.h>
#include <ft/math.h>

static ssize_t	_strstream_read(
	t_stream_context *context,
	void *buffer,
	size_t size
)
{
	size_t	remaining_size;
	size_t	read_size;

	remaining_size = context->size - context->cursor;
	read_size = ft_minu(size, remaining_size);
	ft_memmove(buffer, &context->data[context->cursor], read_size);
	context->cursor += read_size;
	return (read_size);
}

static ssize_t	_strstream_write(
	t_stream_context *context,
	const char *buffer,
	size_t size
)
{
	size_t	remaining_size;
	size_t	write_size;

	remaining_size = context->size - context->cursor - 1;
	write_size = ft_minu(size, remaining_size);
	ft_memmove(&context->data[context->cursor], buffer, write_size);
	context->cursor += write_size;
	context->data[context->cursor] = 0;
	return (write_size);
}

t_stream	ft_stream_open_string(
	char *string,
	size_t offset,
	size_t size,
	t_stream_mode mode
)
{
	t_stream	stream;

	stream = ft_stream_create(!!string, mode);
	if (!stream.is_valid)
		return (stream);
	stream._context = (t_stream_context){
		.data = string,
		.cursor = offset, .size = size, .fd = -1
	};
	stream._hread = _strstream_read;
	stream._hwrite = _strstream_write;
	stream._hclose = NULL;
	return (stream);
}
