/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freepass.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 18:41:09 by bgenia            #+#    #+#             */
/*   Updated: 2022/01/14 23:33:38 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int
	ft_free1pass(void *ptr, int pass)
{
	free(ptr);
	return (pass);
}

int
	ft_free2pass(void *ptr1, void *ptr2, int pass)
{
	free(ptr1);
	free(ptr2);
	return (pass);
}
