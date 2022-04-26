/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 18:39:19 by bgenia            #+#    #+#             */
/*   Updated: 2022/04/15 20:02:19 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include <ft/string/string.h>
#include <ft/io/stream/stream.h>

ssize_t
	ft_put_string(t_stream *ostream, char *string)
{
	if (!string)
		return (ft_stream_write(ostream, "(null)", 6));
	return (ft_stream_write(ostream, string, ft_strlen(string)));
}
