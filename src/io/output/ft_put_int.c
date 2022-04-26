/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 18:39:18 by bgenia            #+#    #+#             */
/*   Updated: 2022/04/15 20:02:19 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdint.h>

#include <ft/io/output.h>

ssize_t
	ft_put_uint(t_stream *ostream, uint64_t n, uint32_t base)
{
	t_integer_format	format;

	format = (t_integer_format){
		.capitalize = 0,
		.prefix = NULL
	};
	return (ft_putf_uint(ostream, n, base, format));
}

ssize_t
	ft_put_int(t_stream *ostream, int64_t n, uint32_t base)
{
	t_integer_format	format;

	format = (t_integer_format){
		.capitalize = 0,
		.prefix = NULL,
		.minus_sign = "-"
	};
	return (ft_putf_int(ostream, n, base, format));
}
