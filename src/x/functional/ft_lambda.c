/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lambda.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 21:10:12 by bgenia            #+#    #+#             */
/*   Updated: 2022/04/15 22:48:56 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft/x/functional.h>

t_lambda
	ft_lambda(t_function function, void *ctx)
{
	return ((t_lambda){.invoke = function, .ctx = ctx});
}
