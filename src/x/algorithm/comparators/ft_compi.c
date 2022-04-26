/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_compi.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 22:35:01 by bgenia            #+#    #+#             */
/*   Updated: 2022/04/15 23:16:30 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

#include <ft/x/algorithm.h>
#include <ft/math.h>

static void
	_compare_i_asc(void *ctx, int *res, int *a, int *b)
{
	(void)ctx;
	*res = ft_zsign(*a - *b);
}

static void
	_compare_i_desc(void *ctx, int *res, int *a, int *b)
{
	(void)ctx;
	*res = ft_zsign(*b - *a);
}

t_lambda
	ft_compi(t_comparator_type comparator)
{
	if (comparator == COMP_ASC)
		return (ft_lambda((void *)_compare_i_asc, NULL));
	return (ft_lambda((void *)_compare_i_desc, NULL));
}
