/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 18:40:01 by bgenia            #+#    #+#             */
/*   Updated: 2022/01/14 23:37:36 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdint.h>

void
	*ft_memccpy(void *dst, const void*src, int c, size_t n)
{
	size_t			i;
	uint8_t			*dst_str;
	const uint8_t	*src_str;

	i = 0;
	dst_str = (uint8_t *)dst;
	src_str = (const uint8_t *)src;
	while (i < n)
	{
		dst_str[i] = src_str[i];
		if (src_str[i] == (uint8_t) c)
			break ;
		i++;
	}
	if (i == n)
		return (NULL);
	return (dst + i + 1);
}
