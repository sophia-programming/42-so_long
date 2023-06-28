/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaoba <oaoba@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 16:49:35 by oaoba             #+#    #+#             */
/*   Updated: 2023/01/11 16:49:38 by oaoba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*dest;
	unsigned const char	*str;
	size_t				i;

	i = 0;
	dest = (unsigned char *)dst;
	str = (unsigned char *)src;
	if (dest > str)
	{
		while (len-- > 0)
		{
			dest[len] = str[len];
		}
	}
	else
	{
		while (i < len)
		{
			dest[i] = str[i];
			i++;
		}
	}
	return (dst);
}

//#include <stdio.h>
// #include <string.h>
// int main(void)
// {
// 	char str1[] = "abcdefghijklmnopqrstu";
// 	char str2[] = "abcdefghijklmnopqrstu";
// 	printf("移動前：%s\n", str1);
// 	memmove(str1+5, str1, 10);/* 重複エリアのコピー */
// 	printf("移動後：%s\n", str1);
// 	printf("%s\n", "-------------");
// 	printf("移動前：%s\n", str2);
// 	ft_memmove(str2+5, str2, 10);/* 重複エリアのコピー */
// 	printf("移動後：%s\n", str2);
// 	return (0);
// }