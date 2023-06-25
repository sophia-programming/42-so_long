/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_format_p.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaoba <oaoba@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 18:15:52 by oaoba             #+#    #+#             */
/*   Updated: 2023/04/02 18:16:16 by oaoba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	print_format_p(uintptr_t num)
{
	size_t	len;

	len = ft_numlen_hex(num);
	if (num == 0)
		return (print_format_c('0'));
	if (num >= 16)
	{
		print_format_p(num / 16);
		num = num % 16;
	}
	if (0 <= num && num <= 9)
		print_format_c(num + '0');
	if (10 <= num && num <= 15)
	{
		num = num - 10 + 'a';
		print_format_c(num);
	}
	return (len);
}
