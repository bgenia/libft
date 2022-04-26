/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_until.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 07:37:36 by bgenia            #+#    #+#             */
/*   Updated: 2022/04/15 20:34:47 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft/io/input.h>
#include <ft/memory/memory.h>
#include <ft/string/string.h>

char
	*ft_get_until(t_stream *istream, char *delimiter)
{
	char	*result;
	size_t	length;
	size_t	capacity;
	size_t	delimiter_length;

	length = 0;
	capacity = FT_INITIAL_INPUT_CAPACITY;
	result = ft_calloc(capacity + 1, sizeof(*result));
	delimiter_length = ft_strlen(delimiter);
	while (!istream->eof && !istream->has_error)
	{
		result[length] = ft_get_char(istream);
		length++;
		if (length >= delimiter_length
			&& ft_streq(result + length - delimiter_length, delimiter))
		{
			result[length - delimiter_length] = '\0';
			break ;
		}
		if (length < capacity)
			continue ;
		capacity *= 2;
		result = ft_strresize(result, capacity);
	}
	return (result);
}
