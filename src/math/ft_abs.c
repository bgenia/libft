/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 18:39:49 by bgenia            #+#    #+#             */
/*   Updated: 2022/01/14 23:42:31 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>

intmax_t
	ft_abs(intmax_t n)
{
	if (n < 0)
		return (-n);
	return (n);
}

float
	ft_absf(float n)
{
	if (n < 0)
		return (-n);
	return (n);
}

double
	ft_absd(double n)
{
	if (n < 0)
		return (-n);
	return (n);
}
