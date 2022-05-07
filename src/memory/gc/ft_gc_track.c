/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gc_track.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 22:41:23 by bgenia            #+#    #+#             */
/*   Updated: 2022/05/07 13:20:49 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>

#include <ft/memory/gc.h>
#include <ft/vector/vector.h>

static void
	*_track(t_gc *gc, void *pointer, void *destructor, bool indirect)
{
	t_gc_record		*record;

	if (!pointer)
		return (NULL);
	record = ft_vector_push_back(&gc->vec_records);
	record->pointer = (uint64_t)pointer;
	record->indirect = indirect;
	if (destructor)
		record->destructor = destructor;
	else
		record->destructor = free;
	if (ft_vector_get_error(gc->vec_records))
	{
		if (indirect && pointer)
			record->destructor(*(void **)pointer);
		else
			record->destructor(pointer);
		pointer = NULL;
	}
	return (pointer);
}

// Frees pointer and returns NULL if gc's address vector cannot be expanded
void
	*ft_gc_track(t_gc *gc, void *pointer, void *destructor)
{
	return (_track(gc, pointer, destructor, false));
}

void
	*ft_gc_track_indirect(t_gc *gc, void *pointer_ptr, void *destructor)
{
	return (_track(gc, pointer_ptr, destructor, true));
}
