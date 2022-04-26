/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 18:38:31 by bgenia            #+#    #+#             */
/*   Updated: 2022/04/15 22:53:54 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATH_H
# define MATH_H

# include <stdint.h>

# include <ft/tuples.h>

intmax_t
ft_min(intmax_t a, intmax_t b);
intmax_t
ft_max(intmax_t a, intmax_t b);

uintmax_t
ft_minu(uintmax_t a, uintmax_t b);
uintmax_t
ft_maxu(uintmax_t a, uintmax_t b);

float
ft_minf(float a, float b);
float
ft_maxf(float a, float b);

double
ft_mind(double a, double b);
double
ft_maxd(double a, double b);

intmax_t
ft_clamp(intmax_t n, intmax_t min, intmax_t max);
uintmax_t
ft_clampu(uintmax_t n, uintmax_t min, uintmax_t max);
float
ft_clampf(float n, float min, float max);
double
ft_clampd(double n, double min, double max);

intmax_t
ft_abs(intmax_t n);
float
ft_absf(float n);
double
ft_absd(double n);

intmax_t
ft_sign(intmax_t n);
float
ft_signf(float n);
double
ft_signd(double n);

intmax_t
ft_zsign(intmax_t n);
float
ft_zsignf(float n);
double
ft_zsignd(double n);

double
ft_rad2deg(double rad);
double
ft_deg2rad(double deg);

int
ft_map(int n, int max_from, int max_to);
float
ft_mapf(float n, float max_from, float max_to);
double
ft_mapd(double n, double max_from, double max_to);

int
ft_xmap(int n, t_int2 from, t_int2 to);
float
ft_xmapf(float n, t_float2 from, t_float2 to);
double
ft_xmapd(double n, t_double2 from, t_double2 to);

#endif
