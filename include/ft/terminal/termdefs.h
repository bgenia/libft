/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termdefs.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 02:44:27 by bgenia            #+#    #+#             */
/*   Updated: 2021/09/30 03:46:15 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TERMDEFS_H
# define TERMDEFS_H

////// Basic control sequences

// Control Sequence Introducer
# define TERM_CSI		"\e["

# define TERM_SEPARATOR	";"

# define TERM_RESET		"\e[0m"

////// Foreground colors

//// Basic foreground colors

# define TERM_F_BLACK			"\e[30m"
# define TERM_F_RED				"\e[31m"
# define TERM_F_GREEN			"\e[32m"
# define TERM_F_YELLOW			"\e[33m"
# define TERM_F_BLUE			"\e[34m"
# define TERM_F_MAGENTA			"\e[35m"
# define TERM_F_CYAN			"\e[36m"
# define TERM_F_WHITE			"\e[37m"

//// Light foreground Colors

# define TERM_F_LIGHT_BLACK		"\e[30;1m"
# define TERM_F_LIGHT_RED		"\e[31;1m"
# define TERM_F_LIGHT_GREEN		"\e[32;1m"
# define TERM_F_LIGHT_YELLOW	"\e[33;1m"
# define TERM_F_LIGHT_BLUE		"\e[34;1m"
# define TERM_F_LIGHT_MAGENTA	"\e[35;1m"
# define TERM_F_LIGHT_CYAN		"\e[36;1m"
# define TERM_F_LIGHT_WHITE		"\e[37;1m"

//// Light black foreground aliases

# define TERM_F_GREY			"\e[30;1m"
# define TERM_F_GRAY			"\e[30;1m"

// Implementation defined / may not work as expected
# define TERM_F_DEFAULT			"\e[39;1m"

////// Background colors

//// Basic background colors

# define TERM_B_BLACK			"\e[40m"
# define TERM_B_RED				"\e[41m"
# define TERM_B_GREEN			"\e[42m"
# define TERM_B_YELLOW			"\e[43m"
# define TERM_B_BLUE			"\e[44m"
# define TERM_B_MAGENTA			"\e[45m"
# define TERM_B_CYAN			"\e[46m"
# define TERM_B_WHITE			"\e[47m"

//// Light background Colors

# define TERM_B_LIGHT_BLACK		"\e[40;1m"
# define TERM_B_LIGHT_RED		"\e[41;1m"
# define TERM_B_LIGHT_GREEN		"\e[42;1m"
# define TERM_B_LIGHT_YELLOW	"\e[43;1m"
# define TERM_B_LIGHT_BLUE		"\e[44;1m"
# define TERM_B_LIGHT_MAGENTA	"\e[45;1m"
# define TERM_B_LIGHT_CYAN		"\e[46;1m"
# define TERM_B_LIGHT_WHITE		"\e[47;1m"

//// Light black background aliases

# define TERM_B_GREY			"\e[40;1m"
# define TERM_B_GRAY			"\e[40;1m"

// Implementation defined / may not work as expected
# define TERM_B_DEFAULT			"\e[49;1m"

////// Advanced colors

# define TERM_STYLE_SUFFIX		"m"

//// x256 colors

// TERM_B_RGB_PREFIX r TERM_SEPARATOR g TERM_SEPARATOR b TERM_STYLE_SUFFIX
# define TERM_F_X256_PREFIX		"\e[38;5;"

// TERM_B_RGB_PREFIX r TERM_SEPARATOR g TERM_SEPARATOR b TERM_STYLE_SUFFIX
# define TERM_B_X256_PREFIX		"\e[48;5;"

// ====================[RGB colors]====================

// TERM_F_RGB_PREFIX r TERM_SEPARATOR g TERM_SEPARATOR b TERM_STYLE_SUFFIX
# define TERM_F_RGB_PREFIX		"\e[38;2;"

// TERM_B_RGB_PREFIX r TERM_SEPARATOR g TERM_SEPARATOR b TERM_STYLE_SUFFIX
# define TERM_B_RGB_PREFIX		"\e[48;2;"

////// Text decorations

# define TERM_BOLD				"\e[1m"
# define TERM_FAINT				"\e[2m"
# define TERM_ITALIC			"\e[3m"
# define TERM_UNDERLINE			"\e[4m"
# define TERM_BLINK_SLOW		"\e[5m"
# define TERM_BLINK_FAST		"\e[6m"
# define TERM_INVERT			"\e[7m"
# define TERM_HIDE				"\e[8m"
# define TERM_STRIKE			"\e[9m"

# define TERM_NOT_BOLD			"\e[21m"
# define TERM_NOT_FAINT			"\e[22m"
# define TERM_NOT_ITALIC		"\e[22m"
# define TERM_NOT_UNDERLINE		"\e[24m"
# define TERM_NOT_BLINK			"\e[25m"
# define TERM_NOT_INVERT		"\e[27m"
# define TERM_NOT_HIDE			"\e[28m"
# define TERM_NOT_STRIKE		"\e[29m"

////// Cursor movement

//// Cursor offset

// TERM_CSI n TERM_CURSOR_*_SUFFIX
# define TERM_CURSOR_UP_SUFFIX				"A"
# define TERM_CURSOR_DOWN_SUFFIX			"B"
# define TERM_CURSOR_RIGHT_SUFFIX			"C"
# define TERM_CURSOR_LEFT_SUFFIX			"D"

//// Line offset

// TERM_CSI n TERM_CURSOR_*_LINE_SUFFIX
# define TERM_CURSOR_PREV_LINE_SUFFIX		"E"
# define TERM_CURSOR_NEXT_LINE_SUFFIX		"F"

//// Direct movement

// TERM_CSI n TERM_CURSOR_SET_COLUMN_SUFFIX
# define TERM_CURSOR_SET_COLUMN_SUFFIX		"G"

// TERM_CSI n TERM_SEPARATOR m TERM_CURSOR_SET_POSITION_SUFFIX
# define TERM_CURSOR_SET_POSITION_SUFFIX	"H"

////// Screen

# define TERM_CLEAR_SCREEN					"\e[2J"
# define TERM_CLEAR_SCREEN_FROM_CURSOR		"\e[0J"
# define TERM_CLEAR_SCREEN_TO_TERM_CURSOR	"\e[1J"

////// Line

# define TERM_CLEAR_LINE					"\e[2K"
# define TERM_CLEAR_LINE_FROM_CURSOR		"\e[0K"
# define TERM_CLEAR_LINE_TO_CURSOR			"\e[1K"

#endif
