/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 23:44:53 by bgenia            #+#    #+#             */
/*   Updated: 2022/04/15 20:02:19 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft/vector/vector.h>
#include <ft/array.h>

void
	ft_vector_sort(void *vector, t_vcomparator comparator, void *arg)
{
	t_vector_header	*header;

	header = ft_vector_get_header(vector);
	ft_qsort(
		header->data,
		header->info.element_size,
		header->size,
		(t_qsort_comparator){.comaprator = comparator, .arg = arg}
		);
}
