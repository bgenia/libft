/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 02:44:00 by bgenia            #+#    #+#             */
/*   Updated: 2022/04/15 20:02:19 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft/io/output.h>
#include <ft/terminal/termdefs.h>

ssize_t
	ft_term_f_x256(t_stream *ostream, uint8_t color)
{
	ssize_t	result;

	result = 0;
	ft_iosequence(&result, 3,
		ft_put_string(ostream, TERM_F_X256_PREFIX),
		ft_put_uint(ostream, color, 10),
		ft_put_string(ostream, TERM_STYLE_SUFFIX)
		);
	return (result);
}

ssize_t
	ft_term_b_x256(t_stream *ostream, uint8_t color)
{
	ssize_t	result;

	result = 0;
	ft_iosequence(&result, 3,
		ft_put_string(ostream, TERM_B_X256_PREFIX),
		ft_put_uint(ostream, color, 10),
		ft_put_string(ostream, TERM_STYLE_SUFFIX)
		);
	return (result);
}

ssize_t
	ft_term_f_rgb(t_stream *ostream, uint8_t r, uint8_t g, uint8_t b)
{
	ssize_t	result;

	result = 0;
	ft_iosequence(&result, 7,
		ft_put_string(ostream, TERM_F_RGB_PREFIX),
		ft_put_uint(ostream, r, 10),
		ft_put_string(ostream, TERM_SEPARATOR),
		ft_put_uint(ostream, g, 10),
		ft_put_string(ostream, TERM_SEPARATOR),
		ft_put_uint(ostream, b, 10),
		ft_put_string(ostream, TERM_STYLE_SUFFIX)
		);
	return (result);
}

ssize_t
	ft_term_b_rgb(t_stream *ostream, uint8_t r, uint8_t g, uint8_t b)
{
	ssize_t	result;

	result = 0;
	ft_iosequence(&result, 7,
		ft_put_string(ostream, TERM_B_RGB_PREFIX),
		ft_put_uint(ostream, r, 10),
		ft_put_string(ostream, TERM_SEPARATOR),
		ft_put_uint(ostream, g, 10),
		ft_put_string(ostream, TERM_SEPARATOR),
		ft_put_uint(ostream, b, 10),
		ft_put_string(ostream, TERM_STYLE_SUFFIX)
		);
	return (result);
}
