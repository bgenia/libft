/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 18:40:00 by bgenia            #+#    #+#             */
/*   Updated: 2022/01/14 23:37:38 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdint.h>

void
	*ft_memchr(const void *s, int c, size_t n)
{
	uint8_t	*start;
	size_t	i;

	start = (uint8_t *)s;
	i = 0;
	while (i < n)
	{
		if (start[i] == (uint8_t)c)
			return (start + i);
		i++;
	}
	return (NULL);
}
