/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stream_close.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 10:41:38 by bgenia            #+#    #+#             */
/*   Updated: 2022/04/30 12:48:40 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft/io/stream/stream.h>

void
	ft_stream_close(t_stream *stream)
{
	if (!ft_stream_is_valid(stream))
		return ;
	ft_stream_flush(stream);
	if (stream->is_write_buffered)
		ft_stream_buffer_destroy(&stream->_write_buffer);
	if (stream->is_read_buffered)
		ft_stream_buffer_destroy(&stream->_read_buffer);
	if (ft_stream_is_closable(stream))
		stream->_hclose(&stream->_context);
	stream->is_valid = false;
}
