/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaoba <oaoba@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 16:50:50 by oaoba             #+#    #+#             */
/*   Updated: 2023/01/11 16:50:51 by oaoba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

//#include<stdio.h>
//int main(void)
//{
//	printf("%zu\n", ft_strlen("hello cats"));
//	printf("%zu\n", ft_strlen("42tokyo hello"));
//}