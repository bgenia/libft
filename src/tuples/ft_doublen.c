/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_doublen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 18:40:51 by bgenia            #+#    #+#             */
/*   Updated: 2022/04/15 20:02:19 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft/tuples.h>

t_double2
	ft_double2(double x, double y)
{
	return ((t_double2){.x = x, .y = y});
}

t_double3
	ft_double3(double x, double y, double z)
{
	return ((t_double3){.x = x, .y = y, .z = z});
}

t_double4
	ft_double4(double w, double x, double y, double z)
{
	return ((t_double4){.w = w, .x = x, .y = y, .z = z});
}
