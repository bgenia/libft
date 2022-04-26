/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_execute_for_each.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 23:44:56 by bgenia            #+#    #+#             */
/*   Updated: 2022/04/15 20:02:19 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft/vector/vector.h>

void
	ft_vector_execute_for_each(void *vector, t_vconsumer consumer, void *arg)
{
	size_t	i;
	size_t	size;

	i = 0;
	size = ft_vector_get_size(vector);
	while (i < size)
	{
		consumer(ft_vector_get(vector, i), i, arg);
		i++;
	}
}
