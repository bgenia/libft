/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clearenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 02:49:19 by bgenia            #+#    #+#             */
/*   Updated: 2022/04/18 00:05:55 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include <ft/process/env.h>
#include <ft/array.h>
#include <ft/memory/memory.h>

void
	ft_clearenv(void)
{
	if (ft_envinfo()->last_env == environ && environ != NULL)
	{
		ft_free_array(
			(void *)environ,
			ft_arrlen(environ, sizeof(*environ))
			);
		ft_envinfo()->last_env = NULL;
	}
}
