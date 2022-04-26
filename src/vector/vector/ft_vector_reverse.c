/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_reverse.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 23:44:51 by bgenia            #+#    #+#             */
/*   Updated: 2022/04/15 20:02:19 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft/vector/vector.h>

void
	ft_vector_reverse(void *vector)
{
	size_t	size;
	size_t	i;

	size = ft_vector_get_size(vector);
	i = 0;
	while (i < size / 2)
	{
		ft_vector_swap_at(vector, i, size - i - 1);
		i++;
	}
}
