/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_smsplit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 11:57:31 by bgenia            #+#    #+#             */
/*   Updated: 2022/04/15 20:02:19 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include <ft/string/string.h>
#include <ft/memory/memory.h>

static const char
	*_find_next_separator(const char *str, char separator)
{
	char	*next_separator;

	next_separator = ft_strchr(str, separator);
	if (!next_separator)
		next_separator = ft_strchr(str, '\0');
	return (next_separator);
}

static const char
	*_find_next_word(const char *str, char separator)
{
	while (*str)
	{
		if (_find_next_separator(str, separator) - str > 0)
			return (str);
		str++;
	}
	return (NULL);
}

static size_t
	_compute_result_size(const char *str, char separator, size_t *word_count)
{
	size_t	_word_count;
	size_t	word_length;
	size_t	total_length;

	_word_count = 0;
	word_length = 0;
	total_length = 0;
	if (!str)
		return (_word_count);
	str = _find_next_word(str, separator);
	while (str)
	{
		_word_count++;
		word_length = _find_next_separator(str, separator) - str;
		total_length += word_length;
		str = _find_next_word(str + word_length, separator);
	}
	*word_count = _word_count;
	return (
		(sizeof(char *) * (_word_count + 1))
		+ (sizeof(char) * (total_length + (_word_count * sizeof(char))))
	);
}

// Single Malloc Split:
// An alternative implementation of ft_split that calls malloc only once.
// Words are storred in the same memory segment as pointers,
// so only the resulting pointer should be freed.
// Memory structure: >w1ptr,w2ptr,w3ptr,NULL,w1,0,w2,0,w3,0<
char
	**ft_smsplit(const char *str, char separator)
{
	char	**result;
	char	*word_ptr;
	size_t	i;
	size_t	word_length;
	size_t	word_count;

	if (!str)
		return (NULL);
	result = ft_malloc(_compute_result_size(str, separator, &word_count));
	if (!result)
		return (NULL);
	i = 0;
	str = _find_next_word(str, separator);
	word_ptr = (void *)result + (sizeof(char *) * (word_count + 1));
	while (i < word_count)
	{
		word_length = _find_next_separator(str, separator) - str;
		ft_memcpy(word_ptr, str, word_length);
		word_ptr[word_length] = '\0';
		result[i++] = word_ptr;
		str = _find_next_word((char *) &str[word_length], separator);
		word_ptr += sizeof(char) * (word_length + 1);
	}
	result[i] = NULL;
	return (result);
}
