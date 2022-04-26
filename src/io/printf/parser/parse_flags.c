/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 18:38:49 by bgenia            #+#    #+#             */
/*   Updated: 2022/04/15 20:02:19 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft/string/string.h>

#include <ft/io/printf/placeholder.h>

void
	_ft_parse_flags(const char **str, t_placeholder *placeholder)
{
	while (1)
	{
		if (ft_strncmp(*str, "-", 1) == 0)
			placeholder->flags |= FLAG_LEFT_ALIGN;
		else if (ft_strncmp(*str, "0", 1) == 0)
			placeholder->flags |= FLAG_ZERO_PAD;
		else if (ft_strncmp(*str, " ", 1) == 0)
			placeholder->flags |= FLAG_BLANK_PLUS;
		else if (ft_strncmp(*str, "+", 1) == 0)
			placeholder->flags |= FLAG_FORCE_SIGN;
		else if (ft_strncmp(*str, "#", 1) == 0)
			placeholder->flags |= FLAG_ALT_FORM;
		else
			break ;
		*str += 1;
	}
}
