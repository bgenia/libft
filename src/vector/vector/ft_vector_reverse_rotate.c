/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_reverse_rotate.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 21:11:59 by bgenia            #+#    #+#             */
/*   Updated: 2022/04/15 20:02:19 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft/vector/vector.h>
#include <ft/array.h>

void
	ft_vector_reverse_rotate(void *vector)
{
	t_vector_header	*header;

	header = ft_vector_get_header(vector);
	ft_arrmove(
		ft_vector_get_safe_space(vector),
		ft_vector_get_first(vector),
		header->info.element_size,
		1
		);
	ft_arrmove(
		ft_vector_get(vector, 0),
		ft_vector_get(vector, 1),
		header->info.element_size,
		header->size - 1
		);
	ft_arrmove(
		ft_vector_get_last(vector),
		ft_vector_get_safe_space(vector),
		header->info.element_size,
		1
		);
}
