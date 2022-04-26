/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strresize.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 22:21:43 by bgenia            #+#    #+#             */
/*   Updated: 2022/04/15 20:02:19 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft/memory/memory.h>
#include <ft/string/string.h>

char
	*ft_strresize(char *str, size_t new_length)
{
	char	*result;
	size_t	length;

	length = ft_strlen(str);
	result = ft_realloc(str, length, sizeof(*str) * (new_length + 1));
	if (new_length > length)
		ft_memset(result + length, 0, new_length - length);
	result[new_length] = '\0';
	return (result);
}
