/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 07:36:00 by bgenia            #+#    #+#             */
/*   Updated: 2022/04/15 20:02:19 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft/io/input.h>
#include <ft/memory/memory.h>

char
	*ft_get_string(t_stream *istream, size_t length)
{
	char	*result;

	result = ft_malloc(sizeof(*result) * (length + 1));
	result[length] = '\0';
	ft_stream_read(istream, &result, length);
	return (result);
}
