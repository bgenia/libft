/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 18:40:23 by bgenia            #+#    #+#             */
/*   Updated: 2022/04/15 20:02:19 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

#include <ft/string/string.h>
#include <ft/memory/memory.h>

static size_t
	_protected_strlen(char *str)
{
	if (str)
		return (ft_strlen(str));
	return (0);
}

char
	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_length;
	size_t	s2_length;
	char	*result;

	s1_length = _protected_strlen((char *) s1);
	s2_length = _protected_strlen((char *) s2);
	result = ft_malloc(sizeof(*result) * (s1_length + s2_length + 1));
	if (!result)
		return (NULL);
	if (s1)
		ft_memcpy(result, s1, s1_length);
	if (s2)
		ft_memcpy(&result[s1_length], s2, s2_length + 1);
	if (!s1 && !s2)
		result[0] = '\0';
	return (result);
}
