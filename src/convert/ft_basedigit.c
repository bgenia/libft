/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_basedigit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 18:40:58 by bgenia            #+#    #+#             */
/*   Updated: 2022/01/14 23:34:12 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char
	ft_basedigit(unsigned int n, unsigned int base)
{
	if (base > 36)
		base = 36;
	if (n % base < 10)
		return ('0' + (n % base));
	return ('a' + ((n % base) - 10));
}
