/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deref.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 00:26:47 by bgenia            #+#    #+#             */
/*   Updated: 2022/01/14 23:33:55 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void
	*ft_deref(void *ptr_ptr)
{
	return (*(void **)ptr_ptr);
}