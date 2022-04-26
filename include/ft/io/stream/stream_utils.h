/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stream_utils.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 03:20:30 by bgenia            #+#    #+#             */
/*   Updated: 2022/04/14 04:02:40 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STREAM_UTILS_H
# define STREAM_UTILS_H

# include <stdbool.h>
# include <unistd.h>
# include <limits.h>

bool
ft_ioguard(ssize_t value, ssize_t *result);
bool
ft_iosequence(ssize_t *result, unsigned int length, ...);

#endif
