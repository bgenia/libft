/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ioguard.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 18:39:23 by bgenia            #+#    #+#             */
/*   Updated: 2022/04/14 04:03:42 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdbool.h>

bool
	ft_ioguard(ssize_t value, ssize_t *result)
{
	if (*result < 0)
		return (false);
	if (value >= 0)
		*result += value;
	else
		*result = value;
	return (*result >= 0);
}
