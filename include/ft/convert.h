/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 00:15:46 by bgenia            #+#    #+#             */
/*   Updated: 2022/03/09 22:50:12 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERT_H
# define CONVERT_H

# include <stdint.h>

char
ft_basedigit(unsigned int n, unsigned int base);

intmax_t
ft_atoi(const char *str, size_t *out_length);

char
*ft_itoa(int n);

#endif
