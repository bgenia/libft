/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_clone.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 23:45:12 by bgenia            #+#    #+#             */
/*   Updated: 2022/04/15 20:02:19 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft/vector/vector.h>
#include <ft/array.h>

void
	*ft_vector_clone(void *vector)
{
	size_t			size;
	t_vector_info	info;
	void			*result;

	size = ft_vector_get_size(vector);
	info = ft_vector_get_header(vector)->info;
	result = ft_vector_alloc(info, size);
	if (!result)
		return (NULL);
	ft_arrmove(
		ft_vector_get(result, 0),
		ft_vector_get(vector, 0),
		info.element_size,
		size
		);
	return (result);
}
