/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cstd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenia <bgenia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 12:12:02 by bgenia            #+#    #+#             */
/*   Updated: 2022/04/30 12:54:33 by bgenia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft/io/fdstream.h>

#ifdef FT_CCLOSE_EXIT_HOOK
# define _FT_AUTO_CCLOSE 1
#else
# define _FT_AUTO_CCLOSE 0
#endif

t_stream
	*ft_cout(void)
{
	static bool		is_initialized = false;
	static t_stream	cout = (t_stream){};

	if (is_initialized)
		return (&cout);
	if (_FT_AUTO_CCLOSE)
		atexit(ft_cclose);
	cout = ft_stream_open_fd(STDOUT_FILENO, STREAM_MODE_IO, false);
	ft_stream_use_write_buffer(&cout, ft_stream_buffer_create_dynamic(1024));
	is_initialized = true;
	return (&cout);
}


t_stream
	*ft_cin(void)
{
	static bool		is_initialized = false;
	static t_stream	cin = (t_stream){};

	if (is_initialized)
		return (&cin);
	if (_FT_AUTO_CCLOSE)
		atexit(ft_cclose);
	cin = ft_stream_open_fd(STDIN_FILENO, STREAM_MODE_IO, false);
	ft_stream_use_read_buffer(&cin, ft_stream_buffer_create_dynamic(1024));
	is_initialized = true;
	return (&cin);
}


t_stream
	*ft_cerr(void)
{
	static bool		is_initialized = false;
	static t_stream	cerr = (t_stream){};

	if (is_initialized)
		return (&cerr);
	if (_FT_AUTO_CCLOSE)
		atexit(ft_cclose);
	cerr = ft_stream_open_fd(STDERR_FILENO, STREAM_MODE_IO, false);
	ft_stream_use_write_buffer(&cerr, ft_stream_buffer_create_dynamic(1024));
	is_initialized = true;
	return (&cerr);
}


t_stream
	*ft_clog(void)
{
	static bool		is_initialized = false;
	static t_stream	clog = (t_stream){};

	if (is_initialized)
		return (&clog);
	if (_FT_AUTO_CCLOSE)
		atexit(ft_cclose);
	clog = ft_stream_open_fd(STDERR_FILENO, STREAM_MODE_IO, false);
	is_initialized = true;
	return (&clog);
}

// Closes all standard streams, intended for use at the end of the program
void
	ft_cclose(void)
{
	ft_stream_close(ft_cout());
	ft_stream_close(ft_cin());
	ft_stream_close(ft_cerr());
	ft_stream_close(ft_clog());
}
