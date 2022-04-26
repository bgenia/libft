/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exitf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 01:05:41 by bgenia            #+#    #+#             */
/*   Updated: 2022/04/15 20:02:19 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>

#include <ft/io/printf.h>

void
	ft_exitf(int fd, int status, char *format, ...)
{
	va_list	args;

	va_start(args, format);
	ft_vdprintf(fd, format, args);
	va_end(args);
	exit(status);
}
