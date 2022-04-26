/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minmax_float.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 18:39:50 by bgenia            #+#    #+#             */
/*   Updated: 2022/01/14 23:42:43 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

float
	ft_minf(float a, float b)
{
	if (a < b)
		return (a);
	return (b);
}

float
	ft_maxf(float a, float b)
{
	if (a > b)
		return (a);
	return (b);
}

double
	ft_mind(double a, double b)
{
	if (a < b)
		return (a);
	return (b);
}

double
	ft_maxd(double a, double b)
{
	if (a > b)
		return (a);
	return (b);
}
