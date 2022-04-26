/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_insert_many_at.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 23:45:35 by bgenia            #+#    #+#             */
/*   Updated: 2022/04/15 20:02:19 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft/vector/vector.h>
#include <ft/array.h>
#include <ft/math.h>
#include <ft/utils.h>

// FIXME: Idk why this works, needs refactoring
void
	*ft_vector_insert_many_at(void *vector_ptr, size_t index, size_t n)
{
	size_t			old_size;
	size_t			new_size;
	size_t			last_insert_index;
	t_vector_header	*header;

	old_size = ft_vector_get_size(ft_deref(vector_ptr));
	if (index >= old_size)
		new_size = index + n;
	else
		new_size = old_size + n;
	last_insert_index = index + n - 1;
	if (!ft_vector_auto_resize(vector_ptr, new_size - old_size))
		return (NULL);
	header = ft_vector_get_header(ft_deref(vector_ptr));
	if (header->error)
		return (NULL);
	if (index < header->size - 1)
		ft_arrmove(
			ft_vector_get(ft_deref(vector_ptr), last_insert_index + 1),
			ft_vector_get(ft_deref(vector_ptr), index),
			header->info.element_size,
			old_size - index
			);
	return (ft_arrget(header->data, header->info.element_size, index));
}
