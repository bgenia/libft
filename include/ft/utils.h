/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 18:38:41 by bgenia            #+#    #+#             */
/*   Updated: 2022/03/14 01:07:37 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

int
ft_free1pass(void *ptr, int pass);

int
ft_free2pass(void *ptr1, void *ptr2, int pass);

void
ft_exit_message(int fd, char *message, int status);

void
ft_exit_perror(char *prefix, int status);

// This is cringe but sometimes needed
// Equivalent of *(void **)ptr_ptr
void
*ft_deref(void *ptr_ptr);

void
ft_exitf(int fd, int status, char *format, ...);

#endif
