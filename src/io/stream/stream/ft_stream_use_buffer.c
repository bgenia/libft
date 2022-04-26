/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stream_use_buffer.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 15:24:45 by bgenia            #+#    #+#             */
/*   Updated: 2022/04/15 20:02:19 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft/io/stream/stream.h>

void
	ft_stream_use_write_buffer(t_stream *stream, t_stream_buffer buffer)
{
	if (!stream->is_valid || !buffer.is_valid)
		return ;
	stream->_write_buffer = buffer;
	stream->is_write_buffered = true;
}

void
	ft_stream_use_read_buffer(t_stream *stream, t_stream_buffer buffer)
{
	if (!stream->is_valid || !buffer.is_valid)
		return ;
	stream->_read_buffer = buffer;
	stream->is_read_buffered = true;
}
