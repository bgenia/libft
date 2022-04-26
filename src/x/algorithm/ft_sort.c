/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 23:01:54 by bgenia            #+#    #+#             */
/*   Updated: 2022/04/15 23:10:00 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft/x/algorithm.h>

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
	_partition(t_array array, int low, int high, t_lambda comparator)
{
	void	*pivot;
	int		i;
	int		j;
	void	*current;
	int		res;

	pivot = ft_arrget(array.data, array.element_size, high);
	i = (low - 1);
	j = low;
	while (j <= high - 1)
	{
		current = ft_arrget(array.data, array.element_size, j);
		comparator.invoke(comparator.ctx, &res,
			current, pivot, array.element_size);
		if (res < 0)
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
	_quick_sort(t_array array, int low, int high, t_lambda comparator)
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
	ft_sort(void *array, size_t element_size, size_t size, t_lambda comparator)
{
	t_array	_array;

	_array = (t_array){.data = array, .element_size = element_size};
	_quick_sort(_array, 0, size - 1, comparator);
}
