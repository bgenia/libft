/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_try_set_clearenv_exit_hook.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 02:42:20 by bgenia            #+#    #+#             */
/*   Updated: 2022/04/18 00:05:55 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft/process/env.h>

#if defined FT_ENV_CLEARENV_EXIT_HOOK

void
	ft_try_set_clearenv_exit_hook(void)
{
	ft_set_clearenv_exit_hook();
}

#else

void
	ft_try_set_clearenv_exit_hook(void)
{
}

#endif
