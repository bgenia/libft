/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_remove_at.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 23:45:44 by bgenia            #+#    #+#             */
/*   Updated: 2022/04/15 20:02:19 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft/vector/vector.h>
#include <ft/array.h>

void
	ft_vector_remove_at(void *vector_ptr, size_t index)
{
	t_vector_header	*header;

	header = ft_vector_get_header(*(void **)vector_ptr);
	if (index < header->size - 1)
		ft_arrmove(
			ft_arrget(header->data, header->info.element_size, index),
			ft_arrget(header->data, header->info.element_size, index + 1),
			header->info.element_size,
			header->size - index - 1
			);
	ft_vector_auto_resize(vector_ptr, -1);
}
