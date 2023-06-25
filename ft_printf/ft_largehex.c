/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_largehex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaoba <oaoba@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 13:52:14 by oaoba             #+#    #+#             */
/*   Updated: 2023/04/09 13:52:38 by oaoba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_largehex(uint32_t num)
{
	size_t	len;

	len = ft_numlen_hex(num);
	if (num == 0)
		return (print_format_c('0'));
	if (num >= 16)
	{
		ft_largehex(num / 16);
		num = num % 16;
	}
	if (0 <= num && num <= 9)
		print_format_c((num + '0'));
	else if (10 <= num && num <= 15)
	{
		num = num - 10 + 'A';
		print_format_c(num);
	}
	return (len);
}
