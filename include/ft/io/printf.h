/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 18:37:33 by bgenia            #+#    #+#             */
/*   Updated: 2022/04/15 20:02:19 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <stdarg.h>
# include <unistd.h>

# include <ft/io/stream/stream.h>

// Stream (not string) printfs
// NOTE:
// There is an equivalent of libc's sprintf
// called ft_format (ft/string/format)

ssize_t
ft_sprintf(t_stream *ostream, const char *format, ...);
ssize_t
ft_vsprintf(t_stream *ostream, const char *format, va_list args);

// Classic printfs for STDOUT and an arbitrary fd
// Implemented using dynamic stream buffers of size FT_PRINTF_BUFFER_SIZE

# ifndef FT_PRINTF_BUFFER_SIZE
#  define FT_PRINTF_BUFFER_SIZE	1024
# endif

ssize_t
ft_printf(const char *format, ...);
ssize_t
ft_dprintf(int fd, const char *format, ...);

ssize_t
ft_vprintf(const char *format, va_list args);
ssize_t
ft_vdprintf(int fd, const char *format, va_list args);

// Alternative versions of printf that
// use static buffers of size FT_XPRINTF_BUFFER_SIZE

# ifndef FT_XPRINTF_BUFFER_SIZE
#  define FT_XPRINTF_BUFFER_SIZE	512
# endif

ssize_t
ft_xprintf(const char *format, ...);
ssize_t
ft_xdprintf(int fd, const char *format, ...);

ssize_t
ft_xvprintf(const char *format, va_list args);
ssize_t
ft_xvdprintf(int fd, const char *format, va_list args);

#endif
