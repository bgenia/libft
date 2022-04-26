/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termutils.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 02:44:24 by bgenia            #+#    #+#             */
/*   Updated: 2022/04/15 20:02:19 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TERMUTILS_H
# define TERMUTILS_H

# include <unistd.h>
# include <stdint.h>

# include <ft/io/stream/stream.h>

ssize_t
ft_term_f_x256(t_stream *ostream, uint8_t color);
ssize_t
ft_term_b_x256(t_stream *ostream, uint8_t color);

ssize_t
ft_term_f_rgb(t_stream *ostream, uint8_t r, uint8_t g, uint8_t b);
ssize_t
ft_term_b_rgb(t_stream *ostream, uint8_t r, uint8_t g, uint8_t b);

ssize_t
ft_term_cursor_up(t_stream *ostream, uint32_t distance);
ssize_t
ft_term_cursor_down(t_stream *ostream, uint32_t distance);
ssize_t
ft_term_cursor_right(t_stream *ostream, uint32_t distance);
ssize_t
ft_term_cursor_left(t_stream *ostream, uint32_t distance);

ssize_t
ft_term_cursor_next_line(t_stream *ostream, uint32_t distance);
ssize_t
ft_term_cursor_prev_line(t_stream *ostream, uint32_t distance);

ssize_t
ft_term_cursor_set_column(t_stream *ostream, uint32_t column);
ssize_t
ft_term_cursor_set_position(t_stream *ostream, uint32_t line, uint32_t column);

#endif
