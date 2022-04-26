/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_assert.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 01:26:13 by bgenia            #+#    #+#             */
/*   Updated: 2022/04/15 20:02:19 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include <ft/debug/assert.h>
#include <ft/io/printf.h>
#include <ft/terminal/termdefs.h>

#if defined FT_ASSERT_IGNORE

void
	ft_assert(bool assertion)
{
	(void) assertion;
	return ;
}

#elif defined FT_ASSERT_WARN

void
	ft_assert(bool assertion)
{
	if (assertion)
		return ;
	ft_xdprintf(
		STDERR_FILENO,
		TERM_F_RED
		"[ft_assert]: Assertion failed.\n"
		TERM_RESET
		);
}

#elif defined FT_ASSERT_EXIT

void
	ft_assert(bool assertion)
{
	if (assertion)
		return ;
	ft_xdprintf(
		STDERR_FILENO,
		TERM_F_RED
		"[ft_assert]: Assertion failed.\n"
		TERM_RESET
		);
	exit(1);
}

#else

void
	ft_assert(bool assertion)
{
	if (assertion)
		return ;
	ft_xdprintf(
		STDERR_FILENO,
		TERM_F_RED
		"[ft_assert]: Assertion failed, aborting.\n"
		TERM_RESET
		);
	abort();
}

#endif
