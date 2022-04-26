/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 23:44:14 by bgenia            #+#    #+#             */
/*   Updated: 2022/04/15 20:02:19 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include <ft/memory/memory.h>

static int
	_get_digit_count(long n)
{
	int	digits;

	digits = 0;
	while (n > 0)
	{
		n /= 10;
		digits++;
	}
	return (digits);
}

static int
	_get_number_length(int n)
{
	if (n == 0)
		return (1);
	if (n < 0)
		return (_get_digit_count(-(long)n) + 1);
	return (_get_digit_count(n));
}

static void
	_stringify_positive(char *s, long n, int length)
{
	if (n >= 10)
	{
		_stringify_positive(s, n / 10, length - 1);
		_stringify_positive(s, n % 10, length);
	}
	else
	{
		s[length - 1] = n + '0';
	}
}

// ft_itoa is deprecated, use ft_aformat insead
char
	*ft_itoa(int n)
{
	char	*result;
	int		length;

	length = _get_number_length(n);
	result = ft_malloc(sizeof(*result) * (length + 1));
	if (!result)
		return (NULL);
	if (n < 0)
		result[0] = '-';
	if (n < 0)
		_stringify_positive(&result[1], -(long)n, length - 1);
	else
		_stringify_positive(result, n, length);
	result[length] = '\0';
	return (result);
}
