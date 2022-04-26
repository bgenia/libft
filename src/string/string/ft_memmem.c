/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmem.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 02:04:01 by bgenia            #+#    #+#             */
/*   Updated: 2022/04/15 20:02:19 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdint.h>

#include <ft/string/string.h>

void
	*ft_memmem(
		const void *haystack,
		size_t haystack_length,
		const void *needle,
		size_t needle_length
	)
{
	size_t			i;

	i = 0;
	if (needle_length <= 0)
		return ((void *)haystack);
	while (i < haystack_length && haystack_length - i >= needle_length)
	{
		if (ft_memcmp(&haystack[i], needle, needle_length) == 0)
			return ((void *)&haystack[i]);
		i++;
	}
	return (NULL);
}
