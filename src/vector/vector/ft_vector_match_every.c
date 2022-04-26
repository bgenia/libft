/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_match_every.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 23:44:58 by bgenia            #+#    #+#             */
/*   Updated: 2022/04/15 20:02:19 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft/vector/vector.h>

bool
	ft_vector_match_every(void *vector, t_vpredicate predicate, void *arg)
{
	size_t	i;

	i = 0;
	while (i < ft_vector_get_size(vector))
	{
		if (!predicate(ft_vector_get(vector, i), i, arg))
			return (false);
		i++;
	}
	return (true);
}
