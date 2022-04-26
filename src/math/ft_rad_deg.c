/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rad_deg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 00:00:37 by bgenia            #+#    #+#             */
/*   Updated: 2022/03/17 00:01:51 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

double
	ft_rad2deg(double rad)
{
	return (rad * (180 / M_PI));
}

double
	ft_deg2rad(double deg)
{
	return (deg * (M_PI / 180));
}
