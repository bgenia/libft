/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 10:28:42 by bgenia            #+#    #+#             */
/*   Updated: 2022/04/15 20:02:19 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft/math.h>

int
	ft_xmap(int n, t_int2 from, t_int2 to)
{
	int	max_from;
	int	max_to;
	int	result;

	max_from = ft_abs(-from.x + from.y);
	max_to = ft_abs(-to.x + to.y);
	result = ft_map(n + ft_abs(from.x), max_from, max_to);
	return (result - ft_abs(to.x));
}

float
	ft_xmapf(float n, t_float2 from, t_float2 to)
{
	float	max_from;
	float	max_to;
	float	result;

	max_from = ft_absf(-from.x + from.y);
	max_to = ft_absf(-to.x + to.y);
	result = ft_mapf(n + ft_absf(from.x), max_from, max_to);
	return (result - ft_absf(to.x));
}

double
	ft_xmapd(double n, t_double2 from, t_double2 to)
{
	double	max_from;
	double	max_to;
	double	result;

	max_from = ft_absd(-from.x + from.y);
	max_to = ft_absd(-to.x + to.y);
	result = ft_mapd(n + ft_absd(from.x), max_from, max_to);
	return (result - ft_absd(to.x));
}
