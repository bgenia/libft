/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_placeholder.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 18:38:53 by bgenia            #+#    #+#             */
/*   Updated: 2022/04/15 20:02:19 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include <ft/io/printf/placeholder.h>
#include <ft/io/printf/parser.h>

void
	_ft_parse_placeholder(const char **str, t_placeholder *ph)
{
	ph->flags = 0;
	ph->type = 0;
	ph->width = -1;
	ph->precision = -1;
	*str += 1;
	_ft_parse_flags(str, ph);
	_ft_parse_width(str, ph);
	_ft_parse_precision(str, ph);
	_ft_parse_size(str, ph);
	_ft_parse_type(str, ph);
	if (ph->flags & FLAG_LEFT_ALIGN
		&& ph->flags & FLAG_ZERO_PAD)
		ph->flags -= FLAG_ZERO_PAD;
	if (ph->flags & FLAG_FORCE_SIGN
		&& ph->flags & FLAG_BLANK_PLUS)
		ph->flags -= FLAG_BLANK_PLUS;
}
