/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 18:40:19 by bgenia            #+#    #+#             */
/*   Updated: 2022/04/15 20:02:19 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

#include <ft/string/string.h>
#include <ft/memory/memory.h>

static char
	*_find_next_separator(char *str, char separator)
{
	char	*next_separator;

	next_separator = ft_strchr(str, separator);
	if (!next_separator)
		next_separator = ft_strchr(str, '\0');
	return (next_separator);
}

static char
	*_find_next_word(char *str, char separator)
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
	_get_word_count(char *str, char separator)
{
	size_t	word_count;
	size_t	word_length;

	word_count = 0;
	if (!str)
		return (word_count);
	str = _find_next_word(str, separator);
	while (str)
	{
		word_count++;
		word_length = _find_next_separator(str, separator) - str;
		str = _find_next_word(str + word_length, separator);
	}
	return (word_count);
}

static void
	*_free_result(char **result, size_t word_count)
{
	size_t	j;

	j = word_count;
	while (j-- > 0)
		free(result[j]);
	free(result);
	return (NULL);
}

char
	**ft_split(char const *str, char separator)
{
	char	**result;
	char	*word;
	size_t	i;
	size_t	word_length;

	result = ft_malloc(sizeof(*result)
			* (_get_word_count((char *) str, separator) + 1));
	if (!result)
		return (NULL);
	i = 0;
	if (str)
		str = _find_next_word((char *) str, separator);
	while (str)
	{
		word_length = _find_next_separator((char *) str, separator) - str;
		word = ft_malloc(sizeof(*word) * (word_length + 1));
		if (!word)
			return (_free_result(result, i));
		ft_memcpy(word, str, word_length);
		word[word_length] = '\0';
		result[i++] = word;
		str = _find_next_word((char *) &str[word_length], separator);
	}
	result[i] = NULL;
	return (result);
}
