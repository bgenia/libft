/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stream_direct_write.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 03:45:05 by bgenia            #+#    #+#             */
/*   Updated: 2022/04/15 20:02:19 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>

#include <ft/io/stream/stream.h>

ssize_t
	ft_stream_direct_write(t_stream *stream, const char *buffer, size_t size)
{
	ssize_t	result;

	if (!ft_stream_is_writable(stream))
		return (-1);
	if (size == 0)
		return (0);
	result = stream->_hwrite(&stream->_context, buffer, size);
	if (result < 0)
		ft_stream_raise_error(stream, errno);
	else
		stream->stats.bytes_written += result;
	return (result);
}
