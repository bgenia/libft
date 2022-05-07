/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gc_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 17:38:24 by bgenia            #+#    #+#             */
/*   Updated: 2022/05/07 14:23:41 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

#include <ft/memory/gc.h>
#include <ft/vector/vector.h>

bool
	ft_gc_init_with_capacity(t_gc *gc, size_t capacity, bool fixed)
{
	gc->vec_records = ft_vector_alloc_with_capacity(sizeof(*gc->vec_records), capacity);
	if (!gc->vec_records)
		return (false);
	if (fixed)
		ft_vector_set_flags(gc->vec_records, 0);
	else
		ft_vector_set_flags(gc->vec_records, FT_VECTOR_GROWABLE);
	return (true);
}

bool
	ft_gc_init(t_gc *gc)
{
	return (ft_gc_init_with_capacity(gc, 0, false));
}
