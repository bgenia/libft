/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuples.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 18:38:38 by bgenia            #+#    #+#             */
/*   Updated: 2021/09/26 02:51:23 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TUPLES_H
# define TUPLES_H

typedef struct s_int2
{
	int	x;
	int	y;
}	t_int2;

typedef struct s_int3
{
	int	x;
	int	y;
	int	z;
}	t_int3;

typedef struct s_int4
{
	int	w;
	int	x;
	int	y;
	int	z;
}	t_int4;

typedef struct s_float2
{
	float	x;
	float	y;
}	t_float2;

typedef struct s_float3
{
	float	x;
	float	y;
	float	z;
}	t_float3;

typedef struct s_float4
{
	float	w;
	float	x;
	float	y;
	float	z;
}	t_float4;

typedef struct s_double2
{
	double	x;
	double	y;
}	t_double2;

typedef struct s_double3
{
	double	x;
	double	y;
	double	z;
}	t_double3;

typedef struct s_double4
{
	double	w;
	double	x;
	double	y;
	double	z;
}	t_double4;

t_int2
ft_int2(int x, int y);

t_int3
ft_int3(int x, int y, int z);

t_int4
ft_int4(int w, int x, int y, int z);

t_float2
ft_float2(float x, float y);

t_float3
ft_float3(float x, float y, float z);

t_float4
ft_float4(float w, float x, float y, float z);

t_double2
ft_double2(double x, double y);

t_double3
ft_double3(double x, double y, double z);

t_double4
ft_double4(double w, double x, double y, double z);

#endif
