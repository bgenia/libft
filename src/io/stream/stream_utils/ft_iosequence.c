/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iosequence.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 04:11:36 by bgenia            #+#    #+#             */
/*   Updated: 2022/04/14 04:03:52 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdbool.h>
#include <stdint.h>
#include <unistd.h>

bool
	ft_iosequence(ssize_t *result, unsigned int length, ...)
{
	va_list		args;
	intmax_t	current;

	va_start(args, length);
	while (length && *result >= 0)
	{
		current = va_arg(args, typeof(current));
		if (current >= 0)
			*result += current;
		else
			*result = current;
		length--;
	}
	va_end(args);
	return (*result >= 0);
}
