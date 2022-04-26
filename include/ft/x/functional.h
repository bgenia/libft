/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functional.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 13:51:33 by bgenia            #+#    #+#             */
/*   Updated: 2022/04/15 21:09:11 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONAL_H
# define FUNCTIONAL_H

# include <stdbool.h>

/**
 * Generic interface for function pointers
 */

typedef void	(*t_function) (void *ctx, void *res, ...);

typedef struct s_lambda
{
	t_function	invoke;
	void		*ctx;
}	t_lambda;

t_lambda
ft_lambda(t_function function, void *ctx);

#endif
