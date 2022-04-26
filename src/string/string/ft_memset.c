/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 18:40:07 by bgenia            #+#    #+#             */
/*   Updated: 2022/01/14 23:37:58 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdint.h>

void
	*ft_memset(void *dst, uint8_t value, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
		((uint8_t *)dst)[i++] = value;
	return (dst);
}
