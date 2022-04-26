/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reallocenv.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 06:27:04 by bgenia            #+#    #+#             */
/*   Updated: 2022/04/18 00:05:55 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft/memory/memory.h>
#include <ft/string/string.h>
#include <ft/array.h>
#include <ft/process/env.h>

int
	ft_reallocenv(void)
{
	size_t	env_size;
	char	**new_env;
	int		i;

	ft_try_set_clearenv_exit_hook();
	if (!environ || ft_envinfo()->last_env == environ)
		return (0);
	env_size = ft_arrlen(environ, sizeof(*environ));
	new_env = ft_calloc(env_size + 1, sizeof(*new_env));
	if (!new_env)
		return (-1);
	i = 0;
	while (environ[i])
	{
		new_env[i] = ft_strdup(environ[i]);
		if (!new_env[i])
		{
			ft_free_array((void *)new_env, i);
			return (-1);
		}
		i++;
	}
	ft_clearenv();
	ft_envinfo()->last_env = environ = new_env;
	return (0);
}
