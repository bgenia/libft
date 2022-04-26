/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_alloc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 23:45:51 by bgenia            #+#    #+#             */
/*   Updated: 2022/04/15 20:02:19 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft/vector/vector.h>

void
	*ft_vector_alloc(t_vector_info info, size_t size)
{
	return (ft_hvector_get_value(
			ft_hvector_alloc(info, size, info.initial_capacity)
		));
}

void
	*ft_vector_alloc_with_size(size_t element_size, size_t size)
{
	t_vector_info	info;

	info = (t_vector_info){
		.element_size = element_size,
		.initial_capacity = size,
		.flags = FT_VECTOR_DEFAULT
	};
	return (ft_vector_alloc(info, size));
}

void
	*ft_vector_alloc_with_capacity(size_t element_size, size_t capacity)
{
	t_vector_info	info;

	info = (t_vector_info){
		.element_size = element_size,
		.initial_capacity = capacity,
		.flags = FT_VECTOR_DEFAULT
	};
	return (ft_vector_alloc(info, 0));
}

void
	*ft_vector_alloc_empty(size_t element_size)
{
	return (ft_vector_alloc_with_capacity(
			element_size,
			FT_VECTOR_DEFAULT_CAPACITY
		));
}
