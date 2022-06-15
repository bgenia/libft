/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_envinfo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 02:46:20 by bgenia            #+#    #+#             */
/*   Updated: 2022/06/15 20:20:46 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft/process/env.h>

volatile t_env_info
	*ft_envinfo(void)
{
	static volatile t_env_info	env_info = (t_env_info){};

	return (&env_info);
}
