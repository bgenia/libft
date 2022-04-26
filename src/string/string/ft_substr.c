/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 18:40:52 by bgenia            #+#    #+#             */
/*   Updated: 2022/04/15 20:02:19 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

#include <ft/string/string.h>
#include <ft/memory/memory.h>

static size_t
	_size_min(size_t a, size_t b)
{
	if (a < b)
		return (a);
	return (b);
}

static size_t
	_ft_strnlen(const char *str, size_t max_length)
{
	return (_size_min(max_length, ft_strlen(str)));
}

char
	*ft_substr(char const *str, unsigned int start, size_t length)
{
	size_t	substring_length;
	char	*substring;

	if (!str)
		return (ft_calloc(1, sizeof(char)));
	if (start > ft_strlen(str))
		substring_length = 0;
	else
		substring_length = _ft_strnlen(&str[start], length);
	substring = ft_malloc(sizeof(*substring) * substring_length + 1);
	if (!substring)
		return (NULL);
	ft_memcpy(substring, &str[start], substring_length);
	substring[substring_length] = '\0';
	return (substring);
}
