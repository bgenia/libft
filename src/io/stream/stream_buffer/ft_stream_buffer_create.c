/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stream_buffer_create.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 14:21:59 by bgenia            #+#    #+#             */
/*   Updated: 2022/04/15 20:02:19 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft/io/stream/stream_buffer.h>
#include <ft/memory/memory.h>

t_stream_buffer
	ft_stream_buffer_create(char *data, size_t size, t_sbhdestroy hdestroy)
{
	t_stream_buffer	buffer;

	buffer = (t_stream_buffer){};
	buffer.is_valid = !!data;
	buffer.data = data;
	buffer.capacity = size;
	buffer.size = size;
	buffer._hdestroy = hdestroy;
	return (buffer);
}

t_stream_buffer
	ft_stream_buffer_create_static(char *data, size_t size)
{
	return (ft_stream_buffer_create(data, size, NULL));
}

t_stream_buffer
	ft_stream_buffer_create_dynamic(size_t size)
{
	return (ft_stream_buffer_create(ft_malloc(size), size, (void *)free));
}
