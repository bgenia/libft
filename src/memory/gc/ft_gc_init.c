/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gc_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 17:38:24 by bgenia            #+#    #+#             */
/*   Updated: 2022/04/15 20:02:19 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

#include <ft/memory/gc.h>
#include <ft/vector/vector.h>

bool
	ft_gc_init_with_capacity(t_gc *gc, size_t capacity, bool fixed)
{
	gc->records = ft_vector_alloc_with_capacity(sizeof(*gc->records), capacity);
	if (fixed)
		ft_vector_set_flags(gc->records, 0);
	else
		ft_vector_set_flags(gc->records, FT_VECTOR_GROWABLE);
	return (!!gc->records);
}

bool
	ft_gc_init(t_gc *gc)
{
	return (ft_gc_init_with_capacity(gc, 0, false));
}
