/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_floatn.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 02:52:33 by bgenia            #+#    #+#             */
/*   Updated: 2022/04/15 20:02:19 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft/tuples.h>

t_float2
	ft_float2(float x, float y)
{
	return ((t_float2){.x = x, .y = y});
}

t_float3
	ft_float3(float x, float y, float z)
{
	return ((t_float3){.x = x, .y = y, .z = z});
}

t_float4
	ft_float4(float w, float x, float y, float z)
{
	return ((t_float4){.w = w, .x = x, .y = y, .z = z});
}
