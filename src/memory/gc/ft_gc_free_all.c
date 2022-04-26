/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gc_free_all.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 17:41:44 by bgenia            #+#    #+#             */
/*   Updated: 2022/04/15 20:02:19 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft/memory/gc.h>
#include <ft/vector/vector.h>

void
	ft_gc_free_all(t_gc *gc)
{
	size_t	i;

	i = 0;
	while (i < ft_vector_get_size(gc->records))
	{
		if (gc->records[i].pointer)
		{
			if (gc->records[i].indirect)
				gc->records[i].destructor(*(void **)gc->records[i].pointer);
			else
				gc->records[i].destructor((void *)gc->records[i].pointer);
		}
		i++;
	}
	gc->records = ft_vector_free(gc->records);
}
