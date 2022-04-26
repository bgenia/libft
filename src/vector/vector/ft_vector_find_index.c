/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_find_index.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 23:45:08 by bgenia            #+#    #+#             */
/*   Updated: 2022/04/15 20:02:19 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft/vector/vector.h>
#include <ft/array.h>

int
	ft_vector_find_index(void *vector, t_vpredicate predicate, void *arg)
{
	size_t	i;
	void	*value;

	i = 0;
	while (i < ft_vector_get_size(vector))
	{
		value = ft_vector_get(vector, i);
		if (predicate(value, i, arg))
			return (i);
		i++;
	}
	return (-1);
}
