/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gc_untrack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 02:22:38 by bgenia            #+#    #+#             */
/*   Updated: 2022/04/15 20:02:19 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdint.h>

#include <ft/memory/gc.h>
#include <ft/vector/vector.h>

static bool
	_record_seach_predicate(t_gc_record *value, size_t index, void *target)
{
	(void) index;
	return (value->pointer == (uint64_t)target);
}

// Doesn't actually remove the record from the vector to avoid reallocs
bool
	ft_gc_untrack(t_gc *gc, void *pointer)
{
	int	record_index;

	if (pointer == NULL)
		return (false);
	record_index = ft_vector_find_index(
			gc->records,
			(void *)_record_seach_predicate,
			pointer
			);
	if (record_index == -1)
		return (false);
	((t_gc_record *)ft_vector_get(gc->records, record_index))->pointer = 0;
	return (true);
}
