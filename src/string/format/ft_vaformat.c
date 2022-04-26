/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vaformat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 00:26:56 by bgenia            #+#    #+#             */
/*   Updated: 2022/04/15 20:02:19 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>

#include <ft/string/string.h>
#include <ft/memory/memory.h>
#include <ft/array.h>
#include <ft/io/stream/stream.h>
#include <ft/io/printf.h>

#define _FT_AFORMAT_INITIAL_BUFSIZE 8
#define _FT_AFORMAT_BUF_GROWTH_FACTOR 1.5

static ssize_t
	_buf_write(t_stream_context *ctx, const char *data, size_t data_size)
{
	size_t	remaining_size;
	size_t	new_size;

	if (data_size == 0)
		return (0);
	remaining_size = ctx->size - ctx->cursor;
	if (remaining_size < data_size || !*(char **)ctx->data)
	{
		new_size = ctx->size * _FT_AFORMAT_BUF_GROWTH_FACTOR;
		if (data_size > new_size - ctx->cursor)
			new_size = ctx->size + data_size;
		if (new_size < _FT_AFORMAT_INITIAL_BUFSIZE)
			new_size = _FT_AFORMAT_INITIAL_BUFSIZE;
		if (!ft_arrresize(
				(void *)ctx->data, sizeof(char), ctx->size, new_size + 1
			))
			return (-1);
		ctx->size = new_size;
	}
	ft_memmove(&(*(char **)ctx->data)[ctx->cursor], data, data_size);
	ctx->cursor += data_size;
	(*(char **)ctx->data)[ctx->cursor] = '\0';
	return (data_size);
}

static t_stream
	_create_bufstream(char **buffer_ptr)
{
	t_stream	stream;

	*buffer_ptr = NULL;
	stream = ft_stream_create(true, STREAM_MODE_O);
	stream._hwrite = _buf_write;
	stream._context = (t_stream_context){
		.data = (void *)buffer_ptr,
		.size = 0
	};
	return (stream);
}

char
	*ft_vaformat(const char *format, va_list args)
{
	t_stream	bufstream;
	char		*result;
	ssize_t		bytes_printed;

	result = NULL;
	bufstream = _create_bufstream(&result);
	if (!bufstream.is_valid)
		return (NULL);
	bytes_printed = ft_vsprintf(&bufstream, format, args);
	ft_stream_close(&bufstream);
	if (bytes_printed == -1 || bufstream.has_error)
		return (NULL);
	if (result == NULL)
		return (ft_strdup(""));
	return (result);
}
