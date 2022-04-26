/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_comps.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 22:35:01 by bgenia            #+#    #+#             */
/*   Updated: 2022/04/15 23:09:30 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

#include <ft/x/algorithm.h>
#include <ft/string/string.h>

static void
	_compare_s_asc(void *ctx, int *res, char **a, char **b)
{
	(void)ctx;
	*res = ft_strcmp(*a, *b);
}

static void
	_compare_s_desc(void *ctx, int *res, char **a, char **b)
{
	(void)ctx;
	*res = ft_strcmp(*b, *a);
}

t_lambda
	ft_comps(t_comparator_type comparator)
{
	if (comparator == COMP_ASC)
		return (ft_lambda((void *)_compare_s_asc, NULL));
	return (ft_lambda((void *)_compare_s_desc, NULL));
}
