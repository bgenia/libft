/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_concat.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 23:44:49 by bgenia            #+#    #+#             */
/*   Updated: 2022/04/15 20:02:19 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft/vector/vector.h>
#include <ft/array.h>

void
	*ft_vector_concat(void *v1, void *v2)
{
	size_t			size1;
	size_t			size2;
	t_vector_info	info;
	void			*result;

	if (!v1 && !v2)
		return (NULL);
	if (!v1 && v2)
		return (ft_vector_clone(v2));
	if (v1 && !v2)
		return (ft_vector_clone(v1));
	size1 = ft_vector_get_size(v1);
	size2 = ft_vector_get_size(v2);
	info = ft_vector_get_header(v1)->info;
	result = ft_vector_alloc_with_size(info.element_size, size1 + size2);
	if (!result)
		return (NULL);
	ft_arrmove(ft_vector_get(result, 0), ft_vector_get(v1, 0),
		info.element_size, size1);
	ft_arrmove(ft_vector_get(result, size1), ft_vector_get(v2, 0),
		info.element_size, size2);
	return (result);
}
