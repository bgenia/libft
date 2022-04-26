/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hvector_alloc.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 17:38:34 by bgenia            #+#    #+#             */
/*   Updated: 2022/04/15 20:02:19 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include <ft/vector/vector.h>
#include <ft/memory/memory.h>
#include <ft/string/string.h>
#include <ft/array.h>

t_vector_header
	*ft_hvector_alloc(t_vector_info info, size_t size, size_t capacity)
{
	t_vector_header	*header;

	ft_vector_info_normalize(&info);
	header = ft_malloc(
			sizeof(*header) + (info.element_size * (capacity + 2))
			);
	if (!header)
		return (NULL);
	header->data = header + 1;
	ft_memset(
		header->data + size, 0, info.element_size * (capacity - size)
		);
	ft_memset(
		header->data + (info.element_size * capacity), 0, info.element_size
		);
	header->info = info;
	header->capacity = capacity;
	header->error = 0;
	header->size = size;
	return (header);
}
