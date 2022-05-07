/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_until.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 07:37:36 by bgenia            #+#    #+#             */
/*   Updated: 2022/05/07 14:51:45 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft/io/input.h>
#include <ft/memory/memory.h>
#include <ft/string/string.h>

static bool
	_extend_line(char **result, size_t *capacity)
{
	char	*temp;

	*capacity *= 2;
	temp = ft_strresize(*result, *capacity);
	if (!temp)
		return (false);
	*result = temp;
	return (true);
}

static bool
	_delimiter_reached(
		char *line,
		char *delimiter,
		size_t length,
		size_t delimiter_length
	)
{
	if (length < delimiter_length)
		return (false);
	return (ft_streq(line + length - delimiter_length, delimiter));
}

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
	if (!result)
		return (NULL);
	delimiter_length = ft_strlen(delimiter);
	while (!istream->eof && !istream->has_error)
	{
		result[length++] = ft_get_char(istream);
		if (_delimiter_reached(result, delimiter, length, delimiter_length))
		{
			result[length - delimiter_length] = '\0';
			break ;
		}
		if (length < capacity)
			continue ;
		if (!_extend_line(&result, &capacity))
			return (ft_free(result));
	}
	return (result);
}
