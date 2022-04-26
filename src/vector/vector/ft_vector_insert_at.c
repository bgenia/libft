/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_insert_at.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 23:45:35 by bgenia            #+#    #+#             */
/*   Updated: 2022/04/15 20:02:19 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft/vector/vector.h>

void
	*ft_vector_insert_at(void *vector_ptr, size_t index)
{
	void	*result;

	result = ft_vector_insert_many_at(vector_ptr, index, 1);
	if (!result)
		return (ft_vector_get_safe_space(*(void **)vector_ptr));
	return (result);
}
