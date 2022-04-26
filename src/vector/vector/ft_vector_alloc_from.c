/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_alloc_from.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 23:45:54 by bgenia            #+#    #+#             */
/*   Updated: 2022/04/15 20:02:19 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft/vector/vector.h>
#include <ft/array.h>

void
	*ft_vector_alloc_from_array(size_t element_size, size_t n, void *array)
{
	void	*vector;

	vector = ft_vector_alloc_with_size(element_size, n);
	if (vector)
		return (ft_arrmove(vector, array, element_size, n));
	return (NULL);
}

void
	*ft_vector_alloc_from_nt_array(size_t element_size, void *array)
{
	void	*vector;
	size_t	n;

	n = ft_arrlen(array, element_size);
	vector = ft_vector_alloc_with_size(element_size, n);
	if (vector)
		return (ft_arrmove(vector, array, element_size, n));
	return (NULL);
}
