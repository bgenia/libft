/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_swap_at.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 23:45:16 by bgenia            #+#    #+#             */
/*   Updated: 2022/04/15 20:02:19 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft/vector/vector.h>
#include <ft/array.h>

void
	ft_vector_swap_at(void *vector, size_t a, size_t b)
{
	t_vector_header	*header;

	header = ft_vector_get_header(vector);
	ft_arrswap(
		ft_vector_get(vector, a),
		ft_vector_get(vector, b),
		header->info.element_size,
		1
		);
}
