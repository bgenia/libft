/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gc_release.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 17:41:44 by bgenia            #+#    #+#             */
/*   Updated: 2022/05/07 13:20:49 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft/memory/gc.h>
#include <ft/vector/vector.h>

void
	ft_gc_release(t_gc *gc)
{
	t_gc_record	*record;

	record = ft_vector_get_last(gc->vec_records);
	while (record)
	{
		if (record->pointer)
		{
			if (record->indirect)
				record->destructor(*(void **)record->pointer);
			else
				record->destructor((void *)record->pointer);
		}
		ft_vector_pop_back(&gc->vec_records);
		record = ft_vector_get_last(gc->vec_records);
	}
}
