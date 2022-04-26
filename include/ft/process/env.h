/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 00:39:33 by bgenia            #+#    #+#             */
/*   Updated: 2022/01/05 17:43:16 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

extern char	**environ;

// libc's *env api implementation

int
ft_setenv(const char *name, const char *value, int overwrite);

int
ft_unsetenv(const char *name);

char
*ft_getenv(const char *name);

// Copies the string to the environment
int
ft_putenv(char *string);

// If clearenv_exit_hook is not set, ft_clearenv must be called at
// the end of each program to ensure that the environ is properly freed.
void
ft_clearenv(void);

// Additional *env functions

// Enables calling ft_clearenv at exit.
// Will be used automatically if FT_ENV_CLEARENV_EXIT_HOOK is defined.
void
ft_set_clearenv_exit_hook(void);

// The same as ft_set_clearenv_exit_hook, but works only if
// FT_ENV_CLEARENV_EXIT_HOOK macro is defined.
void
ft_try_set_clearenv_exit_hook(void);

typedef struct s_env_info
{
	char	**last_env;
}	t_env_info;

// Get global t_env_info object
volatile t_env_info
*ft_envinfo(void);

// Realloc environ into the heap
int
ft_reallocenv(void);

#endif
