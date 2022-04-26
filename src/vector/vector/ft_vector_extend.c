/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_extend.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 23:45:46 by bgenia            #+#    #+#             */
/*   Updated: 2022/04/15 20:02:19 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>

#include <ft/vector/vector.h>

bool
	ft_vector_extend(void *vector_ptr)
{
	t_vector_header	*header;

	header = ft_vector_get_header(*(void **)vector_ptr);
	return (
		ft_vector_resize(vector_ptr, header->capacity * FT_VECTOR_GROWTH_FACTOR)
	);
}
