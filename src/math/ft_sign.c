/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sign.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 04:36:10 by bgenia            #+#    #+#             */
/*   Updated: 2022/03/12 06:09:41 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>

intmax_t
	ft_sign(intmax_t n)
{
	if (n < 0)
		return (-1);
	return (1);
}

float
	ft_signf(float n)
{
	if (n < 0)
		return (-1);
	return (1);
}

double
	ft_signd(double n)
{
	if (n < 0)
		return (-1);
	return (1);
}
