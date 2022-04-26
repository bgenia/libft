/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 18:39:54 by bgenia            #+#    #+#             */
/*   Updated: 2022/04/15 20:02:19 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include <ft/memory/memory.h>

void
	*ft_calloc(size_t count, size_t size)
{
	char	*ptr;
	size_t	i;

	ptr = ft_malloc(size * count);
	if (!ptr)
		return (ptr);
	i = 0;
	while (i < size * count)
		ptr[i++] = 0;
	return (ptr);
}
