/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stream_buffer_extract.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 19:34:46 by bgenia            #+#    #+#             */
/*   Updated: 2022/04/15 20:02:19 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft/io/stream/stream_buffer.h>
#include <ft/string/string.h>

bool
	ft_stream_buffer_extract(
		t_stream_buffer *buffer,
		void *data,
		size_t size
	)
{
	size_t	availabe_bytes;

	availabe_bytes = buffer->size - buffer->cursor;
	if (size > availabe_bytes)
		size = availabe_bytes;
	ft_memmove(data, buffer->data + buffer->cursor, size);
	buffer->cursor += size;
	return (buffer->cursor >= buffer->size);
}
