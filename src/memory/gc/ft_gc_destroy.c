/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gc_destroy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 13:19:17 by bgenia            #+#    #+#             */
/*   Updated: 2022/05/07 13:20:49 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft/memory/gc.h>
#include <ft/vector/vector.h>

void
	ft_gc_destroy(t_gc *gc)
{
	if (!ft_gc_is_valid(gc))
		return ;
	ft_gc_release(gc);
	gc->vec_records = ft_vector_free(gc->vec_records);
}
