/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memswap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 17:26:43 by bgenia            #+#    #+#             */
/*   Updated: 2022/04/15 20:02:19 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>

#include <ft/string/string.h>

void
	*ft_memswap(void *dst, void *src, size_t size)
{
	uint8_t	temp;
	size_t	i;

	if (!src || !dst)
		return (NULL);
	i = 0;
	while (i < size)
	{
		temp = ((uint8_t *)dst)[i];
		((uint8_t *)dst)[i] = ((uint8_t *)src)[i];
		((uint8_t *)src)[i] = temp;
		i++;
	}
	return (dst);
}
