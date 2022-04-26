/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_uint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 23:45:31 by bgenia            #+#    #+#             */
/*   Updated: 2022/04/15 20:02:19 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft/ctype.h>

unsigned int
	_ft_parse_uint(const char **str)
{
	unsigned int	result;
	const char		*s;
	char			c;

	result = 0;
	s = *str;
	c = *s;
	while (ft_isdigit(c))
	{
		result *= 10;
		result += c - '0';
		c = *++s;
	}
	*str = s;
	return (result);
}
