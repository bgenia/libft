/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 20:17:09 by bgenia            #+#    #+#             */
/*   Updated: 2022/04/15 20:02:19 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <errno.h>

#include <ft/memory/memory.h>
#include <ft/io/printf.h>

#if defined FT_MALLOC_MODE_ABORT

void
	*ft_malloc(size_t size)
{
	void	*result;

	result = malloc(size);
	if (!result)
	{
		ft_xdprintf(STDERR_FILENO, FT_MALLOC_ERROR_MESSAGE);
		abort();
	}
	return (result);
}

#elif defined FT_MALLOC_MODE_EXIT

void
	*ft_malloc(size_t size)
{
	void	*result;

	result = malloc(size);
	if (!result)
	{
		ft_xdprintf(STDERR_FILENO, FT_MALLOC_ERROR_MESSAGE);
		exit(ENOMEM);
	}
	return (result);
}

#elif defined FT_MALLOC_MODE_DISABLED

void
	*ft_malloc(size_t size)
{
	return (NULL);
}

#else

void
	*ft_malloc(size_t size)
{
	return (malloc(size));
}

#endif
