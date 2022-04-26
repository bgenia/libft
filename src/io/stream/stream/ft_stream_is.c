/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stream_is.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 10:41:38 by bgenia            #+#    #+#             */
/*   Updated: 2022/04/15 20:02:19 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft/io/stream/stream.h>

bool
	ft_stream_is_valid(t_stream *stream)
{
	return (stream && stream->is_valid);
}

bool
	ft_stream_is_readable(t_stream *stream)
{
	return (
		ft_stream_is_valid(stream)
		&& (stream->mode == STREAM_MODE_IO || stream->mode == STREAM_MODE_I)
	);
}

bool
	ft_stream_is_writable(t_stream *stream)
{
	return (
		ft_stream_is_valid(stream)
		&& (stream->mode == STREAM_MODE_IO || stream->mode == STREAM_MODE_O)
	);
}

bool
	ft_stream_is_closable(t_stream *stream)
{
	return (
		ft_stream_is_valid(stream)
		&& stream->_hclose
	);
}
