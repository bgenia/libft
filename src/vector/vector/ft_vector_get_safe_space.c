/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_get_safe_space.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 04:09:18 by bgenia            #+#    #+#             */
/*   Updated: 2022/04/15 20:02:19 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft/vector/vector.h>
#include <ft/array.h>

void
	*ft_vector_get_safe_space(void *vector)
{
	t_vector_header	*header;

	header = ft_vector_get_header(vector);
	return (ft_arrget(
			header->data,
			header->info.element_size,
			header->capacity + 1
		));
}
