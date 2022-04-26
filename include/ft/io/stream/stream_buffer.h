/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stream_buffer.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 15:24:40 by bgenia            #+#    #+#             */
/*   Updated: 2022/04/14 09:17:23 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STREAM_BUFFER_H
# define STREAM_BUFFER_H

# include <stdlib.h>
# include <stdbool.h>

typedef void	(*t_sbhdestroy)(char *data);

# define SB_UNLIMITED 0

typedef struct s_stream_buffer
{
	bool			is_valid;
	size_t			capacity;
	size_t			limit;
	size_t			size;
	size_t			cursor;
	bool			is_initialized;
	char			*data;
	t_sbhdestroy	_hdestroy;
}	t_stream_buffer;

t_stream_buffer
ft_stream_buffer_create(char *data, size_t size, t_sbhdestroy hdestroy);

void
ft_stream_buffer_set_limit(t_stream_buffer *buffer, size_t limit);

t_stream_buffer
ft_stream_buffer_create_static(char *data, size_t size);

t_stream_buffer
ft_stream_buffer_create_dynamic(size_t size);

bool
ft_stream_buffer_append(t_stream_buffer *buffer, const char *data, size_t size);
bool
ft_stream_buffer_extract(t_stream_buffer *buffer, void *data, size_t size);

void
ft_stream_buffer_destroy(t_stream_buffer *buffer);

#endif
