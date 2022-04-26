/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stream.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 19:54:13 by bgenia            #+#    #+#             */
/*   Updated: 2022/04/15 20:02:19 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STREAM_H
# define STREAM_H

# include <unistd.h>
# include <stdbool.h>

# include <ft/io/stream/stream_buffer.h>

typedef enum e_stream_mode
{
	STREAM_MODE_I = 1 << 0,
	STREAM_MODE_O = 1 << 1,
	STREAM_MODE_IO = STREAM_MODE_I | STREAM_MODE_O
}	t_stream_mode;

typedef struct s_stream_context
{
	int		fd;
	size_t	cursor;
	size_t	size;
	char	*data;
}	t_stream_context;

typedef struct s_stream_stats
{
	size_t	bytes_written;
	size_t	bytes_read;
	size_t	bytes_sent;
	size_t	bytes_received;
}	t_stream_stats;

typedef ssize_t	(*t_shread)(
	t_stream_context *context,
	void *buffer,
	size_t size
	);

typedef ssize_t	(*t_shwrite)(
	t_stream_context *context,
	const char *buffer,
	size_t size
	);

typedef void	(*t_shclose)(
	t_stream_context *context
	);

typedef struct s_stream
{
	bool				is_valid;
	bool				is_write_buffered;
	bool				is_read_buffered;
	bool				has_error;
	bool				eof;
	int					error_code;
	t_stream_mode		mode;
	t_stream_stats		stats;
	t_stream_context	_context;
	t_stream_buffer		_write_buffer;
	t_stream_buffer		_read_buffer;
	t_shwrite			_hwrite;
	t_shread			_hread;
	t_shclose			_hclose;
}	t_stream;

t_stream
ft_stream_create(bool is_valid, t_stream_mode mode);

void
ft_stream_raise_error(t_stream *stream, int code);
void
ft_stream_clear_error(t_stream *stream);

void
ft_stream_use_write_buffer(t_stream *stream, t_stream_buffer buffer);
void
ft_stream_use_read_buffer(t_stream *stream, t_stream_buffer buffer);

bool
ft_stream_is_valid(t_stream *stream);

bool
ft_stream_is_readable(t_stream *stream);
bool
ft_stream_is_writable(t_stream *stream);
bool
ft_stream_is_closable(t_stream *stream);

ssize_t
ft_stream_read(t_stream *stream, void *buffer, size_t size);
ssize_t
ft_stream_write(t_stream *stream, const char *buffer, size_t size);

// Direct stream I/O for bypassing the stream buffer.
// NOTE: Do not mix these with buffered I/O functions as they do not account
// for already buffered data.

ssize_t
ft_stream_direct_read(t_stream *stream, void *buffer, size_t size);
ssize_t
ft_stream_direct_write(t_stream *stream, const char *buffer, size_t size);

ssize_t
ft_stream_flush(t_stream *stream);

void
ft_stream_close(t_stream *stream);

#endif
