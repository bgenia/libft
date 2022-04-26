/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 18:39:59 by bgenia            #+#    #+#             */
/*   Updated: 2022/01/14 23:37:40 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdint.h>

int
	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	uint8_t	*a;
	uint8_t	*b;
	size_t	i;

	a = (uint8_t *)s1;
	b = (uint8_t *)s2;
	i = 0;
	while (i < n && a[i] == b[i])
		i++;
	if (i == n)
		return (0);
	return (a[i] - b[i]);
}
