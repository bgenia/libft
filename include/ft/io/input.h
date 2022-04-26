/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 07:31:26 by bgenia            #+#    #+#             */
/*   Updated: 2022/04/15 20:02:19 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_H
# define INPUT_H

# include <unistd.h>
# include <stdint.h>
# include <stdbool.h>

# include <ft/io/stream/stream.h>
# include <ft/io/stream/stream_utils.h>

# ifndef FT_INITIAL_INPUT_CAPACITY
#  define FT_INITIAL_INPUT_CAPACITY 8
# endif

char
ft_get_char(t_stream *istream);
char
*ft_get_string(t_stream *istream, size_t length);

char
*ft_get_until(t_stream *istream, char *delimiter);

char
*ft_get_line(t_stream *istream);

char
*ft_get_all(t_stream *istream);

#endif
