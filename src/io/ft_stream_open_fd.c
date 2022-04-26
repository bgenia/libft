/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stream_open_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 18:57:09 by bgenia            #+#    #+#             */
/*   Updated: 2022/04/15 20:02:19 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft/io/stream/stream.h>

static ssize_t
	_fdstream_read(t_stream_context *context, void *buffer, size_t size)
{
	return (read(context->fd, buffer, size));
}

static ssize_t
	_fdstream_write(t_stream_context *context, const char *buffer, size_t size)
{
	return (write(context->fd, buffer, size));
}

static void
	_fdstream_close(t_stream_context *context)
{
	close(context->fd);
}

t_stream
	ft_stream_open_fd(int fd, t_stream_mode mode, bool auto_close)
{
	t_stream	stream;

	stream = ft_stream_create(fd != -1, mode);
	if (!stream.is_valid)
		return (stream);
	stream._context = (t_stream_context){.fd = fd};
	stream._hread = _fdstream_read;
	stream._hwrite = _fdstream_write;
	stream._hclose = NULL;
	if (auto_close)
		stream._hclose = _fdstream_close;
	return (stream);
}
