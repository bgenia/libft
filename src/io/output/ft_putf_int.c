/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putf_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 18:39:20 by bgenia            #+#    #+#             */
/*   Updated: 2022/04/15 20:02:19 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdint.h>
#include <stdbool.h>

#include <ft/ctype.h>
#include <ft/convert.h>
#include <ft/io/stream/stream.h>
#include <ft/io/output.h>
#include <ft/string/string.h>

static ssize_t
	_put_digit(
		t_stream *ostream,
		uint32_t digit,
		uint32_t base,
		bool capitalize
	)
{
	char	character;

	character = ft_basedigit(digit, base);
	if (capitalize)
		character = ft_toupper(character);
	return (ft_stream_write(ostream, &character, 1));
}

ssize_t
	ft_putf_uint(
		t_stream *ostream,
		uint64_t n,
		uint32_t base,
		t_integer_format format
	)
{
	ssize_t	result;

	result = 0;
	if (format.prefix)
	{
		ft_ioguard(ft_put_string(ostream, format.prefix), &result);
		format.prefix = NULL;
	}
	if (n >= base)
	{
		ft_ioguard(ft_putf_uint(ostream, n / base, base, format), &result);
		ft_ioguard(ft_putf_uint(ostream, n % base, base, format), &result);
	}
	else
	{
		ft_ioguard(_put_digit(ostream, n, base, format.capitalize), &result);
	}
	return (result);
}

ssize_t
	ft_putf_int(
		t_stream *ostream,
		int64_t n,
		uint32_t base,
		t_integer_format format
	)
{
	if (n < 0)
	{
		format.prefix = format.minus_sign;
		return (ft_putf_uint(ostream, ~(uint64_t)n + 1, base, format));
	}
	return (ft_putf_uint(ostream, n, base, format));
}
