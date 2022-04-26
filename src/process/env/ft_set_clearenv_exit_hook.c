/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_clearenv_exit_hook.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 02:38:20 by bgenia            #+#    #+#             */
/*   Updated: 2022/04/18 00:05:55 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdbool.h>

#include <ft/process/env.h>

void
	ft_set_clearenv_exit_hook(void)
{
	static bool	is_set = false;

	if (is_set)
		return ;
	is_set = true;
	atexit(ft_clearenv);
}
