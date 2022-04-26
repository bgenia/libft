/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrresize.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 23:44:35 by bgenia            #+#    #+#             */
/*   Updated: 2022/04/15 20:02:19 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft/memory/memory.h>
#include <ft/string/string.h>

bool
	ft_arrresize(
		void **array,
		size_t element_size,
		size_t size,
		size_t new_size
	)
{
	return (ft_nullguard(
			ft_reallocarray(*array, size, new_size, element_size),
			array
		));
}
