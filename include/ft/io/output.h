/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 14:31:34 by bgenia            #+#    #+#             */
/*   Updated: 2022/04/15 20:02:19 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OUTPUT_H
# define OUTPUT_H

# include <unistd.h>
# include <stdint.h>
# include <stdbool.h>

# include <ft/io/stream/stream.h>
# include <ft/io/stream/stream_utils.h>

ssize_t
ft_put_character(t_stream *ostream, char c);
ssize_t
ft_put_string(t_stream *ostream, char *string);
ssize_t
ft_put_line(t_stream *ostream, char *line);

typedef struct s_integer_format
{
	char	*prefix;
	char	*minus_sign;
	bool	capitalize;
}	t_integer_format;

ssize_t
ft_putf_uint(
	t_stream *ostream,
	uint64_t n,
	uint32_t base,
	t_integer_format format
	);
ssize_t
ft_putf_int(
	t_stream *ostream,
	int64_t n,
	uint32_t base,
	t_integer_format format
	);

ssize_t
ft_put_uint(t_stream *ostream, uint64_t n, uint32_t base);
ssize_t
ft_put_int(t_stream *ostream, int64_t n, uint32_t base);

ssize_t
ft_put_float(t_stream *ostream, double value, uint32_t precision);

#endif
