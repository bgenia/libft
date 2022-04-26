/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_resize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 20:46:05 by bgenia            #+#    #+#             */
/*   Updated: 2022/04/15 20:02:19 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>

#include <ft/vector/vector.h>
#include <ft/array.h>
#include <ft/math.h>

static bool
	_check_flags(t_vector_header *header, size_t new_capacity)
{
	size_t			capacity;
	t_vector_flags	flags;
	bool			can_grow;
	bool			can_shrink;
	bool			is_fixed_base;

	capacity = header->capacity;
	flags = header->info.flags;
	can_grow = (bool)(flags & FT_VECTOR_GROWABLE);
	can_shrink = (bool)(flags & FT_VECTOR_SHRINKABLE);
	is_fixed_base = (bool)(flags & FT_VECTOR_FIXED_BASE);
	if (new_capacity > capacity)
		return (can_grow);
	if (new_capacity < capacity && new_capacity < header->info.initial_capacity)
		return (can_shrink && is_fixed_base);
	if (new_capacity < capacity)
		return (can_shrink);
	return (true);
}

bool
	ft_vector_resize(void *vector_ptr, size_t new_capacity)
{
	size_t			new_size;
	t_vector_header	*old;
	t_vector_header	*new;

	old = ft_vector_get_header(*(void **)vector_ptr);
	if (!_check_flags(old, new_capacity))
		return (false);
	if (old->size > new_capacity)
		new_size = new_capacity;
	else
		new_size = old->size;
	new = ft_hvector_alloc(old->info, new_size, new_capacity);
	if (new)
	{
		ft_arrmove(new->data, old->data, old->info.element_size, new_size);
		ft_hvector_free(old);
		*(void **)vector_ptr = ft_hvector_get_value(new);
		return (true);
	}
	old->error = errno;
	return (false);
}
