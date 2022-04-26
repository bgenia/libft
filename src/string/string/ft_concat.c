/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_concat.c                                        :+:      :+:    :+:   */
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
	*ft_concat(char *str1, char *str2)
{
	char	*result;
	size_t	len1;
	size_t	len2;

	len1 = ft_strlen(str1);
	len2 = ft_strlen(str2);
	result = ft_malloc(sizeof(*result) * (len1 + len2 + 1));
	ft_memcpy(result, str1, len1);
	ft_memcpy(result + len1, str2, len2);
	result[len1 + len2] = '\0';
	return (result);
}
