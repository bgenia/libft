/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_compd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 22:35:01 by bgenia            #+#    #+#             */
/*   Updated: 2022/04/15 23:09:27 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

#include <ft/x/algorithm.h>
#include <ft/math.h>

static void
	_compare_d_asc(void *ctx, int *res, double *a, double *b)
{
	(void)ctx;
	*res = ft_zsignd(*a - *b);
}

static void
	_compare_d_desc(void *ctx, int *res, double *a, double *b)
{
	(void)ctx;
	*res = ft_zsignd(*b - *a);
}

t_lambda
	ft_compd(t_comparator_type comparator)
{
	if (comparator == COMP_ASC)
		return (ft_lambda((void *)_compare_d_asc, NULL));
	return (ft_lambda((void *)_compare_d_desc, NULL));
}
