/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 18:40:20 by bgenia            #+#    #+#             */
/*   Updated: 2022/04/15 20:02:19 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

#include <ft/string/string.h>
#include <ft/memory/memory.h>

char
	*ft_strdup(const char *str)
{
	char	*copy;
	size_t	length;

	length = ft_strlen(str);
	copy = ft_malloc(sizeof(*copy) * length + 1);
	if (!copy)
		return (NULL);
	ft_memcpy(copy, str, length);
	copy[length] = '\0';
	return (copy);
}
