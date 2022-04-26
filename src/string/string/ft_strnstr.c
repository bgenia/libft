/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 18:40:48 by bgenia            #+#    #+#             */
/*   Updated: 2022/04/15 20:02:19 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include <ft/string/string.h>

char
	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	needle_length;

	i = 0;
	if (!*needle)
		return ((char *)haystack);
	needle_length = ft_strlen(needle);
	while (haystack[i] && i < len && len - i >= needle_length)
	{
		if (ft_strncmp(&haystack[i], needle, needle_length) == 0)
			return ((char *)&haystack[i]);
		i++;
	}
	return (NULL);
}
