/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nullexit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 02:43:34 by bgenia            #+#    #+#             */
/*   Updated: 2022/04/15 20:02:19 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include <ft/utils.h>

void
	*ft_nullexit(void *ptr, int status)
{
	if (!ptr)
		exit(status);
	return (ptr);
}

void
	*ft_nullexit_message(void *ptr, int fd, char *message, int status)
{
	if (!ptr)
		ft_exit_message(fd, message, status);
	return (ptr);
}

void
	*ft_nullexit_perror(void *ptr, char *prefix, int status)
{
	if (!ptr)
		ft_exit_perror(prefix, status);
	return (ptr);
}
