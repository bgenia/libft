/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 21:11:42 by bgenia            #+#    #+#             */
/*   Updated: 2022/04/17 22:10:08 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALGORITHM_H
# define ALGORITHM_H

# include <stdbool.h>
# include <stdint.h>
# include <stddef.h>

# include <ft/x/functional.h>

typedef enum e_comparator_type
{
	COMP_ASC,
	COMP_DESC
}	t_comparator_type;

typedef void	(*t_comparator) \
	(void *ctx, int *res, void *a, void *b, size_t element_size);

// Compares raw bytes
t_lambda
ft_comp(t_comparator_type comparator);

typedef void	(*t_int_comparator) \
	(void *ctx, int *res, int *a, int *b);
typedef void	(*t_double_comparator) \
	(void *ctx, int *res, double *a, double *b);
typedef void	(*t_string_comparator) \
	(void *ctx, int *res, char **a, char **b);

// Compares 32 bit integers
t_lambda
ft_compi(t_comparator_type comparator);
// Compares doubles
t_lambda
ft_compd(t_comparator_type comparator);
// Compares C-strings lexicographically
t_lambda
ft_comps(t_comparator_type comparator);

// Experimental array/ft_qsort implementation using lambdas
void
ft_sort(void *array, size_t element_size, size_t size, t_lambda comparator);

#endif
