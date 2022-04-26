/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 18:40:04 by bgenia            #+#    #+#             */
/*   Updated: 2022/04/15 20:02:19 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include <ft/string/string.h>
#include <ft/math.h>
#include <ft/memory/memory.h>

void
	*ft_realloc(void *ptr, size_t old_size, size_t new_size)
{
	void	*result;

	result = NULL;
	if (new_size > 0)
	{
		result = ft_malloc(new_size);
		if (result)
			ft_memcpy(result, ptr, ft_minu(old_size, new_size));
	}
	if (new_size == 0 || result)
		free(ptr);
	return (result);
}
