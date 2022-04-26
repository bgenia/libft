/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 22:41:32 by bgenia            #+#    #+#             */
/*   Updated: 2021/10/18 01:26:32 by bgenia           ###   ########.fr       */
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
	t_gc_record	*records;
}	t_gc;

bool
ft_gc_init(t_gc *gc);
bool
ft_gc_init_with_capacity(t_gc *gc, size_t capacity, bool fixed);

// Track direct pointer (*p -> free(p))
void
*ft_gc_track(t_gc *gc, void *pointer, void *destructor);
// Track indirect pointer (**p -> free(*p))
void

*ft_gc_track_indirect(t_gc *gc, void *pointer_ptr, void *destructor);

bool
ft_gc_untrack(t_gc *gc, void *pointer);

// Frees all tracked pointers and destroys itself
void
ft_gc_free_all(t_gc *gc);

#endif