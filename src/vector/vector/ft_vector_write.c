/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_write.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 19:27:25 by bgenia            #+#    #+#             */
/*   Updated: 2022/04/15 20:02:19 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft/vector/vector.h>
#include <ft/string/string.h>
#include <ft/io/stream/stream.h>
#include <ft/debug/assert.h>

// FIXME: Maybe find a more elegant way to make this work without assertion
ssize_t
	ft_vector_write(void *vector_ptr, const char *buffer, size_t size)
{
	size_t	vector_size;
	size_t	element_size;
	char	*result;

	if (!buffer)
		return (-1);
	if (size == 0)
		return (0);
	vector_size = ft_vector_get_size(*(void **)vector_ptr);
	element_size = ft_vector_get_header(
			*(void **)vector_ptr
			)->info.element_size;
	ft_assert(size % element_size == 0);
	result = ft_vector_insert_many_at(
			vector_ptr,
			vector_size,
			size / element_size
			);
	if (!result || ft_vector_get_error(*(void **)vector_ptr))
		return (-1);
	ft_memmove(result, buffer, size);
	return (size);
}
