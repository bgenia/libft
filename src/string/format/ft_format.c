/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 15:40:10 by bgenia            #+#    #+#             */
/*   Updated: 2022/04/15 20:02:19 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft/string/format.h>
#include <ft/io/printf.h>

ssize_t
	ft_format(char *buffer, size_t size, const char *format, ...)
{
	va_list	args;
	ssize_t	result;

	va_start(args, format);
	result = ft_vformat(buffer, size, format, args);
	va_end(args);
	return (result);
}
