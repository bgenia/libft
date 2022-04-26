/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 23:45:28 by bgenia            #+#    #+#             */
/*   Updated: 2021/09/25 20:05:55 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_H
# define ARRAY_H

# include <stddef.h>
# include <stdbool.h>

// Generic array utils

// Computes length of a null-terminated array
size_t
ft_arrlen(void *array, size_t element_size);

void
*ft_arrmove(void *dst, void *src, size_t element_size, size_t n);

void
*ft_arrcpy(void *dst, void *src, size_t element_size, size_t n);

void
*ft_arrswap(void *dst, void *src, size_t element_size, size_t n);

void
*ft_arrget(void *array, size_t element_size, size_t index);

bool
ft_arrresize(void **array, size_t element_size, size_t size, size_t new_size);

typedef int	(*t_arrcomparator)(
	void *a,
	void *b,
	void *arg,
	size_t element_size
	);

typedef struct s_qsort_comparator
{
	t_arrcomparator	comaprator;
	void			*arg;
}	t_qsort_comparator;

void
ft_qsort(
	void *array,
	size_t element_size,
	size_t size,
	t_qsort_comparator comparator
	);

#endif
