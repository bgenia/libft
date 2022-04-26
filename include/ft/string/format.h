/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 15:40:03 by bgenia            #+#    #+#             */
/*   Updated: 2021/09/17 00:32:54 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORMAT_H
# define FORMAT_H

# include <unistd.h>
# include <stdarg.h>
# include <stddef.h>

// Works with given buffer of defined size, does not allocate memory
ssize_t
ft_format(char *buffer, size_t size, const char *format, ...);

ssize_t
ft_vformat(char *buffer, size_t size, const char *format, va_list args);

// Mallocs/reallocs memory as needed, the result must be freed
char
*ft_aformat(const char *format, ...);

char
*ft_vaformat(const char *format, va_list args);

#endif
