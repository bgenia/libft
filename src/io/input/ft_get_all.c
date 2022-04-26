/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_all.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 22:19:12 by bgenia            #+#    #+#             */
/*   Updated: 2022/04/15 20:34:50 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft/io/input.h>
#include <ft/string/string.h>
#include <ft/memory/memory.h>

char
	*ft_get_all(t_stream *istream)
{
	char	*result;
	size_t	length;
	size_t	capacity;

	length = 0;
	capacity = FT_INITIAL_INPUT_CAPACITY;
	result = ft_calloc(capacity + 1, sizeof(*result));
	while (!istream->eof && !istream->has_error)
	{
		result[length] = ft_get_char(istream);
		length++;
		if (length < capacity)
			continue ;
		capacity *= 2;
		result = ft_strresize(result, capacity);
	}
	return (result);
}
