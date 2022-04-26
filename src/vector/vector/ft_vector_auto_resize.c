/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_auto_resize.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 23:45:46 by bgenia            #+#    #+#             */
/*   Updated: 2022/04/15 20:02:19 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>

#include <ft/vector/vector.h>
#include <ft/memory/memory.h>
#include <ft/string/string.h>
#include <ft/array.h>
#include <ft/math.h>
#include <ft/utils.h>

static void
	_null_terminate(t_vector_header *header)
{
	ft_memset(
		ft_arrget(header->data, header->info.element_size, header->size),
		0,
		header->info.element_size
		);
}

bool
	ft_vector_auto_resize(void *vector_ptr, int size_change)
{
	t_vector_header	*header;
	double			size;
	double			capacity;
	bool			result;

	header = ft_vector_get_header(ft_deref(vector_ptr));
	size = header->size + size_change;
	capacity = header->capacity;
	result = true;
	if (capacity > header->info.initial_capacity
		&& capacity / size > FT_VECTOR_SHRINK_FACTOR)
		ft_vector_shrink_to_fit(vector_ptr);
	else if (size > capacity * FT_VECTOR_GROWTH_FACTOR)
		result = ft_vector_resize(vector_ptr, size);
	else if (size > capacity)
		result = ft_vector_extend(vector_ptr);
	header = ft_vector_get_header(ft_deref(vector_ptr));
	if (header->error)
		return (false);
	header->size += size_change;
	_null_terminate(header);
	return (result);
}
