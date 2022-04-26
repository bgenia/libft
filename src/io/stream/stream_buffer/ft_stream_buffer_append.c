/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stream_buffer_append.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 03:04:27 by bgenia            #+#    #+#             */
/*   Updated: 2022/04/15 20:02:19 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft/io/stream/stream_buffer.h>
#include <ft/string/string.h>

bool
	ft_stream_buffer_append(
		t_stream_buffer *buffer,
		const char *data,
		size_t size
	)
{
	if (size > buffer->size)
		size = buffer->size;
	ft_memmove(
		&buffer->data[buffer->cursor],
		data,
		size
		);
	buffer->cursor += size;
	return (buffer->cursor >= buffer->size);
}
