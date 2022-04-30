/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdstream.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 03:41:21 by bgenia            #+#    #+#             */
/*   Updated: 2022/04/30 13:15:43 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDSTREAM_H
# define FDSTREAM_H

# include <stdbool.h>

# include <ft/io/stream/stream.h>

t_stream
ft_stream_open_fd(int fd, t_stream_mode mode, bool auto_close);

// Standard descriptor streams, use ft_cclose to properly close them at the end
// of the program or define the FT_CCLEAN_EXIT_HOOK option.

t_stream
*ft_cin(void);
t_stream
*ft_cout(void);
t_stream
*ft_cerr(void);
t_stream
*ft_clog(void);

void
ft_cclose(void);

#endif
