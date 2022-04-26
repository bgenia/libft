/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_clear.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 23:45:46 by bgenia            #+#    #+#             */
/*   Updated: 2022/04/15 20:02:19 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft/vector/vector.h>
#include <ft/memory/memory.h>
#include <ft/array.h>
#include <ft/string/string.h>
#include <ft/math.h>

void
	ft_vector_clear(void *vector)
{
	t_vector_header	*header;

	header = ft_vector_get_header(vector);
	header->size = 0;
	if (header->capacity > 0)
		ft_memset(header->data, 0, header->info.element_size);
}
