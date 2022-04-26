/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 18:40:55 by bgenia            #+#    #+#             */
/*   Updated: 2022/04/15 20:02:19 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stdint.h>
#include <errno.h>
#include <stdbool.h>

#include <ft/ctype.h>

static intmax_t
	_add_digit(intmax_t value, int digit, bool *overflow)
{
	if (__builtin_mul_overflow(value, 10, &value)
		|| __builtin_add_overflow(value, digit, &value))
	{
		*overflow = true;
		errno = ERANGE;
		if (digit < 0)
			return (INTMAX_MIN);
		return (INTMAX_MAX);
	}
	return (value);
}

static intmax_t
	_return(size_t *out_length, size_t i, intmax_t value, int err)
{
	if (out_length)
		*out_length = i;
	errno = err;
	return (value);
}

// Modified non-standard atoi (Works much like strtoll).
// The function will match any \\s*[+-]\\d+ string,
// capping the return value at [INTMAX_MIN / INTMAX_MAX].
// The out_length arg is for when you want to know the exact length of a string
// that ft_atoi matched, can be set to NULL if it's not used.
intmax_t
	ft_atoi(const char *str, size_t *out_legnth)
{
	size_t		i;
	int			sign;
	intmax_t	value;
	bool		overflow;

	i = 0;
	sign = 1;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-')
		sign *= -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	value = 0;
	overflow = false;
	if (!ft_isdigit(str[i]))
		return (_return(out_legnth, i, 0, EINVAL));
	while (ft_isdigit(str[i]))
	{
		if (!overflow)
			value = _add_digit(value, sign * (str[i] - '0'), &overflow);
		i++;
	}
	return (_return(out_legnth, i, value, errno));
}
