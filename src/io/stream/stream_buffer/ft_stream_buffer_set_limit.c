/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stream_buffer_set_limit.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 08:47:04 by bgenia            #+#    #+#             */
/*   Updated: 2022/04/15 20:02:19 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft/io/stream/stream_buffer.h>
#include <ft/math.h>

void
	ft_stream_buffer_set_limit(t_stream_buffer *buffer, size_t limit)
{
	buffer->limit = limit;
	if (limit == 0)
		buffer->size = buffer->capacity;
	else
		buffer->size = ft_min(buffer->limit, buffer->capacity);
}
