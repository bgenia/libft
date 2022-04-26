/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 08:23:01 by bgenia            #+#    #+#             */
/*   Updated: 2022/04/18 00:05:55 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include <ft/process/env.h>
#include <ft/string/string.h>

int
	ft_putenv(char *string)
{
	char	**parts;
	int		result;

	parts = ft_smsplit(string, '=');
	if (!parts)
		return (-1);
	result = ft_setenv(parts[0], parts[1], 1);
	free(parts);
	return (result);
}
