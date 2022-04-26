/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clamp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 18:39:51 by bgenia            #+#    #+#             */
/*   Updated: 2022/04/15 20:02:19 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <ft/math.h>

intmax_t
	ft_clamp(intmax_t n, intmax_t min, intmax_t max)
{
	return (ft_max(min, ft_min(n, max)));
}

uintmax_t
	ft_clampu(uintmax_t n, uintmax_t min, uintmax_t max)
{
	return (ft_maxu(min, ft_minu(n, max)));
}

float
	ft_clampf(float n, float min, float max)
{
	return (ft_maxf(min, ft_minf(n, max)));
}

double
	ft_clampd(double n, double min, double max)
{
	return (ft_maxd(min, ft_mind(n, max)));
}
