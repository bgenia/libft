/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 00:56:41 by bgenia            #+#    #+#             */
/*   Updated: 2022/04/18 00:05:55 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdbool.h>
#include <stdlib.h>

#include <ft/memory/memory.h>
#include <ft/array.h>
#include <ft/string/string.h>
#include <ft/process/env.h>
#include <ft/string/format.h>

static int
	_set(char **address, const char *name, const char *value)
{
	size_t	length;
	char	*var;

	length = ft_strlen(name) + ft_strlen(value) + 1;
	var = ft_malloc(sizeof(*var) * (length + 1));
	if (!var)
		return (-1);
	if (ft_format(var, length + 1, "%s=%s", name, value) >= 0)
	{
		*address = var;
		return (0);
	}
	return (-1);
}

static int
	_setenv_create(const char *name, const char *value)
{
	environ = ft_calloc(2, sizeof(*environ));
	if (!environ)
		return (-1);
	ft_envinfo()->last_env = environ;
	return (_set(environ, name, value));
}

static int
	_setenv_update(const char *name, const char *value)
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
			break ;
		i++;
	}
	free(environ[i]);
	return (_set(&environ[i], name, value));
}

static int
	_setenv_append(const char *name, const char *value)
{
	size_t	env_size;
	char	**new_env;

	env_size = ft_arrlen(environ, sizeof(*environ));
	new_env = ft_reallocarray(
			environ,
			env_size,
			env_size + 2,
			sizeof(*environ)
			);
	if (!new_env)
		return (-1);
	new_env[env_size + 1] = NULL;
	ft_envinfo()->last_env = environ = new_env;
	return (_set(&environ[env_size], name, value));
}

int
	ft_setenv(const char *name, const char *value, int overwrite)
{
	bool	exists;

	if (!environ)
		return (_setenv_create(name, value));
	if (ft_reallocenv() < 0)
		return (-1);
	exists = !!ft_getenv(name);
	if (!exists)
		return (_setenv_append(name, value));
	if (overwrite)
		return (_setenv_update(name, value));
	return (0);
}
