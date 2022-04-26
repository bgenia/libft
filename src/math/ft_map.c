/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 10:28:42 by bgenia            #+#    #+#             */
/*   Updated: 2022/03/19 10:31:29 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int
	ft_map(int n, int max_from, int max_to)
{
	return (n * (max_to / max_from));
}

float
	ft_mapf(float n, float max_from, float max_to)
{
	return (n * (max_to / max_from));
}

double
	ft_mapd(double n, double max_from, double max_to)
{
	return (n * (max_to / max_from));
}
