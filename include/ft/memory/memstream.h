/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memstream.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 10:19:36 by bgenia            #+#    #+#             */
/*   Updated: 2022/04/15 20:02:19 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MEMSTREAM_H
# define MEMSTREAM_H

# include <ft/io/stream/stream.h>

t_stream
ft_stream_open_memory(
	void *data,
	size_t offset,
	size_t size,
	t_stream_mode mode
	);

#endif
