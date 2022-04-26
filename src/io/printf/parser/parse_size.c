/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_size.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 18:38:55 by bgenia            #+#    #+#             */
/*   Updated: 2022/04/15 20:02:19 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft/string/string.h>

#include <ft/io/printf/placeholder.h>

void
	_ft_parse_size(const char **str, t_placeholder *placeholder)
{
	if (ft_strncmp(*str, "ll", 2) == 0)
	{
		placeholder->type |= TYPE_SIZE_LL;
		*str += 2;
	}
	else if (ft_strncmp(*str, "l", 1) == 0)
	{
		placeholder->type |= TYPE_SIZE_L;
		*str += 1;
	}
	else if (ft_strncmp(*str, "hh", 2) == 0)
	{
		placeholder->type |= TYPE_SIZE_HH;
		*str += 2;
	}
	else if (ft_strncmp(*str, "h", 1) == 0)
	{
		placeholder->type |= TYPE_SIZE_H;
		*str += 1;
	}
}
