/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 18:40:45 by bgenia            #+#    #+#             */
/*   Updated: 2022/04/15 20:02:19 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include <ft/string/string.h>
#include <ft/memory/memory.h>

char
	*ft_strmapi(char const *str, char (*f)(unsigned int, char))
{
	size_t	str_length;
	char	*result;
	size_t	i;

	if (!str)
		str_length = 0;
	else
		str_length = ft_strlen(str);
	result = ft_malloc(sizeof(*result) * (str_length + 1));
	if (!result)
		return (NULL);
	i = 0;
	while (str && str[i])
	{
		result[i] = f(i, str[i]);
		i++;
	}
	result[i] = '\0';
	return (result);
}
