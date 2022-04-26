/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 18:39:17 by bgenia            #+#    #+#             */
/*   Updated: 2022/04/15 20:02:19 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft/io/output.h>

ssize_t
	ft_put_line(t_stream *ostream, char *line)
{
	ssize_t	result;

	result = 0;
	ft_ioguard(ft_put_string(ostream, line), &result);
	ft_ioguard(ft_put_character(ostream, '\n'), &result);
	return (result);
}
