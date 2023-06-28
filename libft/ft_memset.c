/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaoba <oaoba@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 17:03:52 by oaoba             #+#    #+#             */
/*   Updated: 2023/01/11 17:03:54 by oaoba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * b: cで文字を埋める対象
 * c: これをunsigned charにキャストしてbを埋める
 * len: len文字分cで埋める
 */

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*dest;
	unsigned char	src;
	size_t			i;

	dest = b;
	src = c;
	i = 0;
	while (i < len)
	{
		dest[i] = src;
		i++;
	}
	return (b);
}

//#include<string.h>
//#include <stdio.h>
//int main(void)
//{
//	char s[] = "hello cats!";
//	ft_memset(s + 2, '3', 3);
//	printf("%s\n", s);
//	printf("---------------------\n");
//	memset(s + 2, '3', 3);
//	printf("%s\n", s);
//}