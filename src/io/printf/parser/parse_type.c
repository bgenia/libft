/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_type.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 18:38:57 by bgenia            #+#    #+#             */
/*   Updated: 2022/04/15 20:02:19 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft/io/printf/placeholder.h>
#include <ft/string/string.h>

static bool
	_consume(const char **str, const char *token)
{
	size_t	token_length;

	token_length = ft_strlen(token);
	if (ft_strneq(*str, token, token_length))
	{
		*str += token_length;
		return (true);
	}
	return (false);
}

static t_type_field
	__parse_basic_type_names(const char **str)
{
	if (_consume(str, "c"))
		return (TYPE_C);
	if (_consume(str, "s"))
		return (TYPE_S);
	if (_consume(str, "p"))
		return (TYPE_P);
	if (_consume(str, "d") || _consume(str, "i"))
		return (TYPE_DI);
	if (_consume(str, "u"))
		return (TYPE_U);
	if (_consume(str, "x"))
		return (TYPE_XL);
	if (_consume(str, "X"))
		return (TYPE_XU);
	if (_consume(str, "%"))
		return (TYPE_PERCENT);
	return (TYPE_INVALID);
}

static t_type_field
	__parse_advanced_type_names(const char **str)
{
	if (_consume(str, "b"))
		return (TYPE_B);
	if (_consume(str, "o"))
		return (TYPE_O);
	if (_consume(str, "n"))
		return (TYPE_N);
	if (_consume(str, "S"))
		return (TYPE_FS);
	if (_consume(str, "f"))
		return (TYPE_F);
	if (_consume(str, "e"))
		return (TYPE_E);
	if (_consume(str, "g"))
		return (TYPE_G);
	return (TYPE_INVALID);
}

static t_type_field
	_parse_type_name(const char **str)
{
	t_type_field	result;

	result = __parse_basic_type_names(str);
	if (result == TYPE_INVALID)
		result = __parse_advanced_type_names(str);
	return (result);
}

void
	_ft_parse_type(const char **str, t_placeholder *placeholder)
{
	placeholder->type |= _parse_type_name(str);
}
