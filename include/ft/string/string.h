/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 18:38:35 by bgenia            #+#    #+#             */
/*   Updated: 2022/04/15 01:23:11 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRING_H
# define STRING_H

# include <unistd.h>
# include <stdint.h>
# include <stdbool.h>

void
*ft_memset(void *dst, uint8_t value, size_t len);

void
*ft_memcpy(void *dst, const void *src, size_t n);

void
*ft_memccpy(void *dst, const void *src, int c, size_t n);

void
*ft_memmove(void *dst, const void *src, size_t len);

void
*ft_memchr(const void *s, int c, size_t n);

int
ft_memcmp(const void *s1, const void *s2, size_t n);

void
*ft_memswap(void *dst, void *src, size_t size);

void
*ft_memmem(
	const void *haystack,
	size_t haystack_length,
	const void *needle,
	size_t needle_length
	);

size_t
ft_strlcpy(char *dst, const char *src, size_t dstsize);

size_t
ft_strlcat(char *dst, const char *src, size_t dstsize);

char
*ft_strchr(const char *s, int c);

char
*ft_strrchr(const char *s, int c);

char
*ft_strnstr(
	const char *haystack,
	const char *needle,
	size_t len
	);

int
ft_strcmp(const char *s1, const char *s2);

int
ft_strncmp(const char *s1, const char *s2, size_t n);

bool
ft_strisempty(char *string);

char
*ft_substr(char const *s, unsigned int start, size_t len);

char
*ft_strjoin(char const *s1, char const *s2);

char
*ft_strtrim(char const *s1, char const *set);

char
**ft_split(char const *s, char c);
char
**ft_smsplit(char const *s, char c);

char
*ft_strmapi(char const *s, char (*f)(unsigned int, char));

char
*ft_strdup(const char *s1);

size_t
ft_strlen(const char *str);

bool
ft_streq(const char *s1, const char *s2);
bool
ft_strneq(const char *s1, const char *s2, size_t n);

char
*ft_concat(char *str1, char *str2);

char
*ft_strresize(char *str, size_t new_length);

#endif
