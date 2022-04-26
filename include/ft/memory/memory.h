/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 18:38:33 by bgenia            #+#    #+#             */
/*   Updated: 2021/09/11 21:01:27 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MEMORY_H
# define MEMORY_H

# include <unistd.h>

# ifndef FT_MALLOC_ERROR_MESSAGE
#  define FT_MALLOC_ERROR_MESSAGE "Error"
# endif

// Same as libc's malloc but may auto fail depending on FT_MALLOC_MODE_* macros
// Available behaviors: ABORT, EXIT, DISABLED, default (no macro)
void
*ft_malloc(size_t size);

void
*ft_calloc(size_t count, size_t size);

void
*ft_realloc(void *ptr, size_t old_size, size_t new_size);

void
*ft_reallocarray(void *ptr, size_t old_n, size_t new_n, size_t size);

void
*ft_free(void *ptr);

void
ft_free_each(void **arr, size_t size);

void
*ft_free_array(void **arr, size_t size);

int
ft_nullguard(void *ptr, void **var);

void
*ft_nullexit(void *ptr, int status);

void
*ft_nullexit_message(void *ptr, int fd, char *message, int status);

void
*ft_nullexit_perror(void *ptr, char *prefix, int status);

#endif
