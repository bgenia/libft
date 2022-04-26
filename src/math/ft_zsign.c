/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zsign.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 04:36:10 by bgenia            #+#    #+#             */
/*   Updated: 2022/04/15 22:53:34 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>

intmax_t
	ft_zsign(intmax_t n)
{
	if (n < 0)
		return (-1);
	if (n == 0)
		return (0);
	return (1);
}

float
	ft_zsignf(float n)
{
	if (n < 0)
		return (-1);
	if (n == 0)
		return (0);
	return (1);
}

double
	ft_zsignd(double n)
{
	if (n < 0)
		return (-1);
	if (n == 0)
		return (0);
	return (1);
}
