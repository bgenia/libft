/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 00:49:38 by bgenia            #+#    #+#             */
/*   Updated: 2022/04/18 00:05:55 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include <ft/string/string.h>
#include <ft/process/env.h>

char
	*ft_getenv(const char *name)
{
	size_t	name_length;
	int		i;

	if (!environ)
		return (NULL);
	name_length = ft_strlen(name);
	i = 0;
	while (environ[i])
	{
		if (
			ft_strneq(environ[i], name, name_length)
			&& environ[i][name_length] == '='
			)
			return (&environ[i][name_length + 1]);
		i++;
	}
	return (NULL);
}
