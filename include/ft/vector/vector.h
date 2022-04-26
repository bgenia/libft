/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 13:25:55 by bgenia            #+#    #+#             */
/*   Updated: 2022/03/22 17:49:20 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// ft/vector module rewrite

#ifndef VECTOR_H
# define VECTOR_H

# include <stddef.h>
# include <unistd.h>
# include <stdbool.h>
# include <stdint.h>

# ifndef FT_VECTOR_DEFAULT_CAPACITY
#  define FT_VECTOR_DEFAULT_CAPACITY 8
# endif

# ifndef FT_VECTOR_GROWTH_FACTOR
#  define FT_VECTOR_GROWTH_FACTOR 1.5f
# endif

# ifndef FT_VECTOR_SHRINK_FACTOR
#  define FT_VECTOR_SHRINK_FACTOR 1.5f
# endif

/**
 * Vector flags bit field (->):
 * CAN_SHRINK CAN_GROW IS_FIXED_BASE IS_EXPONENTIAL
 */
typedef enum e_vector_flags
{
	FT_VECTOR_SHRINKABLE	= (1 << 0),
	FT_VECTOR_GROWABLE		= (1 << 1),
	FT_VECTOR_FIXED_BASE	= (1 << 2),
	FT_VECTOR_DEFAULT		=
		FT_VECTOR_FIXED_BASE	| \
		FT_VECTOR_SHRINKABLE	| \
		FT_VECTOR_GROWABLE
}	t_vector_flags;

// Static vector data, should not change between reallocs
typedef struct s_vector_info
{
	t_vector_flags	flags;
	size_t			initial_capacity;
	size_t			element_size;
}	t_vector_info;

void
ft_vector_info_normalize(t_vector_info *info);

typedef struct s_vector_header
{
	t_vector_info	info;
	size_t			size;
	size_t			capacity;
	int				error;
	void			*data;
}	t_vector_header;

/**
 * Vector memory map:
 *
 * <-low         |<-- vector pointer                                       high->
 * vector_header element1 element2 ... elementn NULL unused_space NULL safe_space
 *               ^--- size -------------------^
 *               ^--- capacity ---------------------------------^
 *                                                    element_size -> ^---------^
 */

t_vector_header
*ft_hvector_alloc(t_vector_info info, size_t size, size_t capacity);
void
*ft_hvector_free(t_vector_header *vector);

void
*ft_hvector_get_value(t_vector_header *header);
t_vector_header
*ft_vector_get_header(void *vector);
void
*ft_vector_get_safe_space(void *vector);

t_vector_flags
ft_vector_get_flags(void *vector);
void
*ft_vector_set_flags(void *vector, t_vector_flags flags);

// TODO: Find better signatures for vector constructors

void
*ft_vector_alloc(t_vector_info info, size_t size);
void
*ft_vector_alloc_with_capacity(size_t element_size, size_t capacity);
void
*ft_vector_alloc_with_size(size_t element_size, size_t size);
void
*ft_vector_alloc_empty(size_t element_size);

void
*ft_vector_free(void *vector);

void
*ft_vector_alloc_from_array(size_t element_size, size_t n, void *array);
void
*ft_vector_alloc_from_nt_array(size_t element_size, void *array);

int
ft_vector_get_error(void *vector);
size_t
ft_vector_get_size(void *vector);

void
*ft_vector_get_first(void *vector);
void
*ft_vector_get_last(void *vector);

void
*ft_vector_get(void *vector, size_t index);
void
*ft_vector_safe_get(void *vector, size_t index);

bool
ft_vector_is_empty(void *vector);

void
ft_vector_clear(void *vector);

bool
ft_vector_shrink_to_fit(void *vector_ptr);
bool
ft_vector_extend(void *vector_ptr);
bool
ft_vector_resize(void *vector_ptr, size_t new_capacity);
bool
ft_vector_erase(void *vector_ptr);

bool
ft_vector_auto_resize(void *vector_ptr, int size_change);

void
*ft_vector_push_back(void *vector_ptr);
void
*ft_vector_push_front(void *vector_ptr);
void
*ft_vector_insert_at(void *vector_ptr, size_t index);
void
*ft_vector_insert_many_at(void *vector_ptr, size_t index, size_t n);

void
ft_vector_pop_back(void *vector_ptr);
void
ft_vector_pop_front(void *vector_ptr);
void
ft_vector_remove_at(void *vector_ptr, size_t index);

typedef int		(*t_vcomparator)	(
	void *a,
	void *b,
	void *arg,
	size_t element_size
	);
typedef void	(*t_vconsumer)		(void *value, size_t index, void *arg);
typedef bool	(*t_vpredicate)		(void *value, size_t index, void *arg);

int
ft_vector_find_index(void *vector, t_vpredicate predicate, void *arg);
int
ft_vector_find_last_index(void *vector, t_vpredicate predicate, void *arg);
void
*ft_vector_find(void *vector, t_vpredicate predicate, void *arg);
void
*ft_vector_find_last(void *vector, t_vpredicate predicate, void *arg);

bool
ft_vector_match_some(void *vector, t_vpredicate predicate, void *arg);
bool
ft_vector_match_every(void *vector, t_vpredicate predicate, void *arg);

void
ft_vector_swap_at(void *vector, size_t index1, size_t index2);

void
ft_vector_execute_for_each(void *vector, t_vconsumer consumer, void *arg);

void
ft_vector_sort(void *vector, t_vcomparator comparator, void *arg);
void
ft_vector_reverse(void *vector);
void
ft_vector_rotate(void *vector);
void
ft_vector_reverse_rotate(void *vector);

void
*ft_vector_concat(void *v1, void *v2);

void
*ft_vector_clone(void *vector);

ssize_t
ft_vector_write(void *vector_ptr, const char *buffer, size_t size);

#endif
