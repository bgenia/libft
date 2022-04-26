/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_comp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 23:24:00 by bgenia            #+#    #+#             */
/*   Updated: 2022/04/15 23:29:29 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdarg.h>

#include <ft/x/functional.h>
#include <ft/x/algorithm.h>

#include <ft/string/string.h>

static void
	_compare_asc(void *ctx, int *res, ...)
{
	va_list	args;
	void	*a;
	void	*b;
	size_t	element_size;

	(void)ctx;
	va_start(args, res);
	a = va_arg(args, typeof(a));
	b = va_arg(args, typeof(b));
	element_size = va_arg(args, typeof(element_size));
	*res = ft_memcmp(a, b, element_size);
	va_end(args);
}

static void
	_compare_desc(void *ctx, int *res, ...)
{
	va_list	args;
	void	*a;
	void	*b;
	size_t	element_size;

	(void)ctx;
	va_start(args, res);
	a = va_arg(args, typeof(a));
	b = va_arg(args, typeof(b));
	element_size = va_arg(args, typeof(element_size));
	*res = ft_memcmp(b, a, element_size);
	va_end(args);
}

t_lambda
	ft_comp(t_comparator_type comparator)
{
	if (comparator == COMP_ASC)
		return (ft_lambda((void *)_compare_asc, NULL));
	return (ft_lambda((void *)_compare_desc, NULL));
}
