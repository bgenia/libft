/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 18:38:44 by bgenia            #+#    #+#             */
/*   Updated: 2021/08/21 20:56:12 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "placeholder.h"

unsigned int
_ft_parse_uint(const char **str);

void
_ft_parse_flags(const char **str, t_placeholder *ph);
void
_ft_parse_width(const char **str, t_placeholder *ph);
void
_ft_parse_precision(const char **str, t_placeholder *ph);
void
_ft_parse_size(const char **str, t_placeholder *ph);
void
_ft_parse_type(const char **str, t_placeholder *ph);

void
_ft_parse_placeholder(const char **format, t_placeholder *ph);

#endif
