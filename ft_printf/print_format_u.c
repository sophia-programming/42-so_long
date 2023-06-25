/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_format_u.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaoba <oaoba@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 18:16:15 by oaoba             #+#    #+#             */
/*   Updated: 2023/04/02 18:16:16 by oaoba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	print_format_u(uint32_t num)
{
	size_t	len;

	len = 0;
	if (num >= 10)
	{
		len += print_format_u(num / 10);
		len += print_format_c(num % 10 + '0');
	}
	else
		len += print_format_c(num + '0');
	return (len);
}
