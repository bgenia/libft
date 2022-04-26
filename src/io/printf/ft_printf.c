/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 23:40:36 by bgenia            #+#    #+#             */
/*   Updated: 2022/04/15 20:02:19 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>

#include <ft/io/printf.h>

ssize_t
	ft_printf(const char *format, ...)
{
	va_list	args;
	ssize_t	result;

	va_start(args, format);
	result = ft_vprintf(format, args);
	va_end(args);
	return (result);
}

ssize_t
	ft_dprintf(int fd, const char *format, ...)
{
	va_list	args;
	ssize_t	result;

	va_start(args, format);
	result = ft_vdprintf(fd, format, args);
	va_end(args);
	return (result);
}

ssize_t
	ft_xprintf(const char *format, ...)
{
	va_list	args;
	ssize_t	result;

	va_start(args, format);
	result = ft_xvprintf(format, args);
	va_end(args);
	return (result);
}

ssize_t
	ft_xdprintf(int fd, const char *format, ...)
{
	va_list	args;
	ssize_t	result;

	va_start(args, format);
	result = ft_xvdprintf(fd, format, args);
	va_end(args);
	return (result);
}
