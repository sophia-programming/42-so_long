/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaoba <oaoba@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 18:14:56 by oaoba             #+#    #+#             */
/*   Updated: 2023/04/02 18:16:16 by oaoba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	launch_printf(va_list *ap, const char word)
{
	if (word == 'c')
		return (print_format_c(va_arg(*ap, int)));
	if (word == 's')
		return (print_format_s(va_arg(*ap, char *)));
	if (word == 'p')
	{
		print_format_s("0x");
		return (print_format_p((uintptr_t)va_arg(*ap, void *)) + 2);
	}
	if (word == 'd' || word == 'i')
		return (print_format_di(va_arg(*ap, int)));
	if (word == 'u')
		return (print_format_u(va_arg(*ap, int)));
	if (word == 'x')
		return (ft_smallhex(va_arg(*ap, int)));
	if (word == 'X')
		return (ft_largehex(va_arg(*ap, int)));
	return (0);
}

static bool	is_format_specifiers(const char word)
{
	return (word == 'd' || word == 'c' || word == 's' || word == 'p'
		|| word == 'i' || word == 'u' || word == 'x' || word == 'X');
}

static t_format	after_per(const char word)
{
	if (is_format_specifiers(word))
		return (FORMAT_SPECIFIERS);
	else if (word == '\0')
		return (FORMAT_NULL);
	return (FORMAT_OTHER);
}

static void	check_printf(va_list *ap, const char *fmt, size_t *count)
{
	size_t	i;

	i = 0;
	while (fmt[i])
	{
		if (fmt[i] == '%')
		{
			if (after_per(fmt[i + 1]) != FORMAT_NULL)
			{
				if (after_per(fmt[i + 1]) == FORMAT_SPECIFIERS)
					*count += launch_printf(ap, fmt[i + 1]);
				else if (after_per(fmt[i + 1]) == FORMAT_OTHER)
					*count += write(1, &fmt[i + 1], 1);
				i += 2;
			}
			else
				i++;
		}
		else
		{
			*count += write(1, &fmt[i], 1);
			i++;
		}
	}
}

int	ft_printf(const char *fmt, ...)
{
	va_list	ap;
	size_t	count;

	count = 0;
	va_start(ap, fmt);
	check_printf(&ap, fmt, &count);
	va_end(ap);
	return ((int)count);
}
