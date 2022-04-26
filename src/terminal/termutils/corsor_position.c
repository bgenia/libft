/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corsor_position.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 02:43:57 by bgenia            #+#    #+#             */
/*   Updated: 2022/04/15 20:02:19 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft/io/output.h>
#include <ft/terminal/termdefs.h>

ssize_t
	ft_term_cursor_set_column(t_stream *ostream, uint32_t column)
{
	ssize_t	result;

	result = 0;
	ft_iosequence(&result, 3,
		ft_put_string(ostream, TERM_CSI),
		ft_put_uint(ostream, column, 10),
		ft_put_string(ostream, TERM_CURSOR_SET_COLUMN_SUFFIX)
		);
	return (result);
}

ssize_t
	ft_term_cursor_set_position(
		t_stream *ostream,
		uint32_t line,
		uint32_t column
	)
{
	ssize_t	result;

	result = 0;
	ft_iosequence(&result, 5,
		ft_put_string(ostream, TERM_CSI),
		ft_put_uint(ostream, line, 10),
		ft_put_string(ostream, TERM_SEPARATOR),
		ft_put_uint(ostream, column, 10),
		ft_put_string(ostream, TERM_CURSOR_SET_POSITION_SUFFIX)
		);
	return (result);
}
