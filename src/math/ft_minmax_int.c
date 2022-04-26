/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minmax_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 18:39:53 by bgenia            #+#    #+#             */
/*   Updated: 2022/01/14 23:42:47 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<stdint.h>

intmax_t
	ft_min(intmax_t a, intmax_t b)
{
	if (a < b)
		return (a);
	return (b);
}

intmax_t
	ft_max(intmax_t a, intmax_t b)
{
	if (a > b)
		return (a);
	return (b);
}

uintmax_t
	ft_minu(uintmax_t a, uintmax_t b)
{
	if (a < b)
		return (a);
	return (b);
}

uintmax_t
	ft_maxu(uintmax_t a, uintmax_t b)
{
	if (a > b)
		return (a);
	return (b);
}
