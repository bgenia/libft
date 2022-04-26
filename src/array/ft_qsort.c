/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_qsort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 02:43:43 by bgenia            #+#    #+#             */
/*   Updated: 2022/04/15 20:02:19 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft/array.h>
#include <ft/string/string.h>

typedef struct s_array
{
	void	*data;
	size_t	element_size;
}	t_array;

static void
	_swap(t_array array, size_t a, size_t b)
{
	ft_memswap(
		ft_arrget(array.data, array.element_size, a),
		ft_arrget(array.data, array.element_size, b),
		array.element_size
		);
}

static int
	_partition(t_array array, int low, int high, t_qsort_comparator comparator)
{
	void	*pivot;
	int		i;
	int		j;
	void	*current;

	pivot = ft_arrget(array.data, array.element_size, high);
	i = (low - 1);
	j = low;
	while (j <= high - 1)
	{
		current = ft_arrget(array.data, array.element_size, j);
		if (comparator.comaprator(
				current, pivot, comparator.arg, array.element_size) < 0)
		{
			i++;
			_swap(array, i, j);
		}
		j++;
	}
	_swap(array, i + 1, high);
	return (i + 1);
}

static void
	_quick_sort(t_array array, int low, int high, t_qsort_comparator comparator)
{
	int	pivot;

	if (low < high)
	{
		pivot = _partition(array, low, high, comparator);
		_quick_sort(array, low, pivot - 1, comparator);
		_quick_sort(array, pivot + 1, high, comparator);
	}
}

void
	ft_qsort(
		void *array,
		size_t element_size,
		size_t n,
		t_qsort_comparator comparator
	)
{
	_quick_sort(
		(t_array){.data = array, .element_size = element_size},
		0,
		n - 1,
		comparator
		);
}
