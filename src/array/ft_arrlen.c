/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 23:44:17 by bgenia            #+#    #+#             */
/*   Updated: 2022/01/14 23:48:26 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>

static bool
	_is_null_element(uint8_t *ptr, size_t element_size)
{
	size_t	i;

	i = 0;
	while (i < element_size)
		if (ptr[i++] != 0)
			return (false);
	return (true);
}

size_t
	ft_arrlen(void *array, size_t element_size)
{
	uint8_t	*value;
	size_t	size;

	if (!array)
		return (0);
	value = array;
	size = 0;
	while (!_is_null_element(value, element_size))
	{
		size++;
		value += element_size;
	}
	return (size);
}
