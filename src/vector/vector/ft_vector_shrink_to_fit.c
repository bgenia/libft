/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_shrink_to_fit.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 23:45:46 by bgenia            #+#    #+#             */
/*   Updated: 2022/04/15 20:02:19 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>

#include <ft/vector/vector.h>
#include <ft/memory/memory.h>
#include <ft/array.h>
#include <ft/math.h>

bool
	ft_vector_shrink_to_fit(void *vector_ptr)
{
	t_vector_header	*header;

	header = ft_vector_get_header(*(void **)vector_ptr);
	return (ft_vector_resize(vector_ptr, header->size));
}
