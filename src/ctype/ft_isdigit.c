/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 18:41:02 by bgenia            #+#    #+#             */
/*   Updated: 2022/01/14 23:34:25 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int
	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}