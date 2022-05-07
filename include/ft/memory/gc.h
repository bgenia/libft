/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 22:41:32 by bgenia            #+#    #+#             */
/*   Updated: 2022/05/07 13:56:43 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GC_H
# define GC_H

# include <stddef.h>
# include <stdint.h>
# include <stdbool.h>

typedef void	(*t_gcdestructor)	(void *pointer);

typedef struct s_gc_record
{
	uint64_t		pointer;
	t_gcdestructor	destructor;
	bool			indirect;
}	t_gc_record;

typedef struct s_gc
{
	t_gc_record	*vec_records;
}	t_gc;

bool
ft_gc_init(t_gc *gc);
bool
ft_gc_init_with_capacity(t_gc *gc, size_t capacity, bool fixed);

bool
ft_gc_is_valid(t_gc *gc);

// Track direct pointer (*p -> free(p))
void
*ft_gc_track(t_gc *gc, void *pointer, t_gcdestructor destructor);

// Track indirect pointer (**p -> free(*p))
void
*ft_gc_track_indirect(t_gc *gc, void *pointer_ptr, t_gcdestructor destructor);

bool
ft_gc_untrack(t_gc *gc, void *pointer);

// Frees all tracked pointers
void
ft_gc_release(t_gc *gc);

// Frees all tracked pointers and destroys gc
void
ft_gc_destroy(t_gc *gc);

#endif
