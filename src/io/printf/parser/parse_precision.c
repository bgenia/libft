/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_precision.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 18:38:54 by bgenia            #+#    #+#             */
/*   Updated: 2022/04/15 20:02:19 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft/io/printf/placeholder.h>
#include <ft/io/printf/parser.h>

void
	_ft_parse_precision(const char **str, t_placeholder *placeholder)
{
	const char		*s;
	char			c;
	unsigned int	precision;

	s = *str;
	c = *s;
	if (c != '.')
		return ;
	c = *++s;
	if (c == '*')
	{
		placeholder->flags |= FLAG_ARG_PRECISION;
		c = *++s;
	}
	else
	{
		precision = _ft_parse_uint(&s);
		placeholder->precision = precision;
	}
	*str = s;
}
