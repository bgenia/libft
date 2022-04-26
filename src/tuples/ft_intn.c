/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intn.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 18:40:52 by bgenia            #+#    #+#             */
/*   Updated: 2022/04/15 20:02:19 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft/tuples.h>

t_int2
	ft_int2(int x, int y)
{
	return ((t_int2){.x = x, .y = y});
}

t_int3
	ft_int3(int x, int y, int z)
{
	return ((t_int3){.x = x, .y = y, .z = z});
}

t_int4
	ft_int4(int w, int x, int y, int z)
{
	return ((t_int4){.w = w, .x = x, .y = y, .z = z});
}
