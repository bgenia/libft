/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stream_open_vector.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 03:41:02 by bgenia            #+#    #+#             */
/*   Updated: 2022/04/15 20:02:19 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include <ft/io/stream/stream.h>
#include <ft/vector/vector.h>
#include <ft/string/string.h>
#include <ft/math.h>

static ssize_t
	_vecstream_write(t_stream_context *context, const char *buffer, size_t size)
{
	return (ft_vector_write(context->data, buffer, size));
}

t_stream
	ft_stream_open_vector(void *vector_ptr)
{
	t_stream	stream;

	stream = ft_stream_create(
			!!vector_ptr && !!*(void **)vector_ptr,
			STREAM_MODE_O
			);
	if (!stream.is_valid)
		return (stream);
	stream._context = (t_stream_context){
		.data = (char *)vector_ptr,
		.cursor = 0, .size = 0, .fd = -1
	};
	stream._hread = NULL;
	stream._hwrite = _vecstream_write;
	stream._hclose = NULL;
	return (stream);
}
