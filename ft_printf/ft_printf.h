/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaoba <oaoba@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 18:15:03 by oaoba             #+#    #+#             */
/*   Updated: 2023/04/02 18:16:16 by oaoba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <limits.h>
# include <stdbool.h>

typedef enum e_format{
	FORMAT_SPECIFIERS = 1,
	FORMAT_NULL = 2,
	FORMAT_OTHER = 3,
}	t_format;

int		ft_printf(const char *fmt, ...);
int		print_format_c(int c);
int		print_format_s(char *s);
size_t	print_format_p(uintptr_t num);
size_t	print_format_di(int64_t num);
size_t	print_format_u(uint32_t num);
size_t	ft_numlen_hex(uint64_t nb);
size_t	ft_smallhex(uint32_t num);
size_t	ft_largehex(uint32_t num);

#endif
