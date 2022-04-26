/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stream_create.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 02:18:45 by bgenia            #+#    #+#             */
/*   Updated: 2022/04/15 20:02:19 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include <ft/io/stream/stream.h>

t_stream
	ft_stream_create(bool is_valid, t_stream_mode mode)
{
	t_stream	stream;

	stream = (t_stream){0};
	stream.is_valid = is_valid;
	if (!stream.is_valid)
		return (stream);
	stream.mode = mode;
	stream.is_write_buffered = false;
	stream.is_read_buffered = false;
	stream.has_error = false;
	stream.error_code = 0;
	stream.stats.bytes_read = 0;
	stream.stats.bytes_written = 0;
	return (stream);
}
