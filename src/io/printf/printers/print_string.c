/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 18:39:05 by bgenia            #+#    #+#             */
/*   Updated: 2022/04/15 20:02:19 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>

#include <ft/io/output.h>

#include <ft/io/printf/placeholder.h>

int
	_ft_print_string(
		t_stream *ostream,
		t_placeholder *ph,
		va_list args,
		ssize_t *n
	)
{
	char	*value;
	ssize_t	result;

	value = va_arg(args, char *);
	result = ft_put_string(ostream, value);
	if (ph->type & TYPE_FS)
		free(value);
	return (ft_ioguard(result, n));
}
