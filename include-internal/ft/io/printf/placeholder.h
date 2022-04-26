/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   placeholder.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 18:38:45 by bgenia            #+#    #+#             */
/*   Updated: 2021/09/22 05:43:50 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLACEHOLDER_H
# define PLACEHOLDER_H

# include <stdint.h>

typedef uint8_t		t_flag_field;

# define FLAG_LEFT_ALIGN	0b0000001U
# define FLAG_ZERO_PAD		0b0000010U
# define FLAG_BLANK_PLUS	0b0000100U
# define FLAG_FORCE_SIGN	0b0001000U
# define FLAG_ALT_FORM		0b0010000U
# define FLAG_ARG_WIDTH		0b0100000U
# define FLAG_ARG_PRECISION	0b1000000U

typedef uint32_t	t_type_field;

// FIXME: Reorganize this into enums or something

# define TYPE_SIZE_L	0b10000000000000000000000000000000U
# define TYPE_SIZE_LL	0b01000000000000000000000000000000U
# define TYPE_SIZE_H	0b00100000000000000000000000000000U
# define TYPE_SIZE_HH	0b00010000000000000000000000000000U

# define TYPE_C			0b00000000000000000000000000000001U
# define TYPE_S			0b00000000000000000000000000000010U
# define TYPE_P			0b00000000000000000000000000000100U
# define TYPE_DI		0b00000000000000000000000000001000U
# define TYPE_U			0b00000000000000000000000000010000U
# define TYPE_XL		0b00000000000000000000000000100000U
# define TYPE_XU		0b00000000000000000000000001000000U
# define TYPE_N			0b00000000000000000000000010000000U
# define TYPE_F			0b00000000000000000000000100000000U
# define TYPE_E			0b00000000000000000000001000000000U
# define TYPE_G			0b00000000000000000000010000000000U
# define TYPE_PERCENT	0b00000000000000000000100000000000U

// Non-standard conversions

// Unsigned binary integer (1010)
# define TYPE_B			0b00000000000000000001000000000000U

// Unsigned octal integer (1470)
# define TYPE_O			0b00000000000000000010000000000000U

// Freeable string
# define TYPE_FS		0b00000000000000000100000000000000U

# define TYPE_INVALID	0U

typedef struct s_placeholder
{
	t_flag_field	flags;
	t_type_field	type;
	int				width;
	int				precision;
}	t_placeholder;

#endif
