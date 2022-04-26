/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_width.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 18:39:01 by bgenia            #+#    #+#             */
/*   Updated: 2022/04/15 20:02:19 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft/io/printf/placeholder.h>
#include <ft/io/printf/parser.h>

void
	_ft_parse_width(const char **str, t_placeholder *placeholder)
{
	const char		*s;
	char			c;
	unsigned int	width;

	s = *str;
	c = *s;
	if (c == '*')
	{
		placeholder->flags |= FLAG_ARG_WIDTH;
		c = *++s;
	}
	else
	{
		width = _ft_parse_uint(&s);
		placeholder->width = width;
	}
	*str = s;
}
