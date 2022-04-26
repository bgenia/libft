/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 02:43:52 by bgenia            #+#    #+#             */
/*   Updated: 2022/04/15 20:02:19 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft/io/output.h>
#include <ft/terminal/termdefs.h>

ssize_t
	ft_term_cursor_next_line(t_stream *ostream, uint32_t distance)
{
	ssize_t	result;

	result = 0;
	ft_iosequence(&result, 3,
		ft_put_string(ostream, TERM_CSI),
		ft_put_uint(ostream, distance, 10),
		ft_put_string(ostream, TERM_CURSOR_NEXT_LINE_SUFFIX)
		);
	return (result);
}

ssize_t
	ft_term_cursor_prev_line(t_stream *ostream, uint32_t distance)
{
	ssize_t	result;

	result = 0;
	ft_iosequence(&result, 3,
		ft_put_string(ostream, TERM_CSI),
		ft_put_uint(ostream, distance, 10),
		ft_put_string(ostream, TERM_CURSOR_PREV_LINE_SUFFIX)
		);
	return (result);
}
