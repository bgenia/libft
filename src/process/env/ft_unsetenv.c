/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsetenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 03:03:20 by bgenia            #+#    #+#             */
/*   Updated: 2022/04/18 00:05:55 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

#include <ft/process/env.h>
#include <ft/memory/memory.h>
#include <ft/array.h>
#include <ft/string/string.h>

static int
	_find_var(const char *name)
{
	size_t	name_length;
	int		i;

	name_length = ft_strlen(name);
	i = 0;
	while (environ[i])
	{
		if (
			ft_strneq(environ[i], name, name_length)
			&& environ[i][name_length] == '='
			)
			return (i);
		i++;
	}
	return (-1);
}

int
	ft_unsetenv(const char *name)
{
	int		var_index;
	size_t	env_size;
	char	**new_env;

	if (ft_reallocenv() < 0)
		return (-1);
	if (!environ)
		return (0);
	var_index = _find_var(name);
	if (var_index == -1)
		return (0);
	env_size = ft_arrlen(environ, sizeof(*environ));
	new_env = ft_calloc(env_size, sizeof(*environ));
	if (!new_env)
		return (-1);
	ft_arrmove(new_env, environ, sizeof(*environ), var_index);
	ft_arrmove(&new_env[var_index], &environ[var_index + 1],
		sizeof(*environ), env_size - (var_index + 1));
	new_env[env_size - 1] = NULL;
	free(environ[var_index]);
	free(environ);
	ft_envinfo()->last_env = environ = new_env;
	return (0);
}
