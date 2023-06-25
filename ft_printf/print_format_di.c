/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_format_di.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaoba <oaoba@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 18:15:41 by oaoba             #+#    #+#             */
/*   Updated: 2023/04/02 18:16:16 by oaoba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	print_format_di(int64_t num)
{
	size_t	len;

	len = 0;
	if (num < 0)
	{
		len += print_format_c('-');
		len += print_format_di(-num);
	}
	else if (num >= 10)
	{
		len += print_format_di(num / 10);
		len += print_format_c(num % 10 + '0');
	}
	else
		len += print_format_c(num + '0');
	return (len);
}
