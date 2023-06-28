/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaoba <oaoba@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 16:49:20 by oaoba             #+#    #+#             */
/*   Updated: 2023/01/11 16:49:21 by oaoba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*destination;
	unsigned const char	*source;

	if (dst == NULL && src == NULL)
		return (NULL);
	i = 0;
	destination = (unsigned char *)dst;
	source = (unsigned char *)src;
	while (i < n)
	{
		destination[i] = source[i];
		i++;
	}
	return (dst);
}

//#include<string.h>
//#include<stdio.h>
//int main(void)
//{
//	char str1[] = "abcdefg";
//	char str2[] = "abcdefg";
//	printf("Before str1 = %s\n", str1);
//	memcpy(str1 + 2, NULL, 3);
//	printf("After memcpy  = %s\n", str1);
//	printf("---------------------------\n");
//	printf("Before ft_memcpy  = %s\n", str2);
//	ft_memcpy(str2 + 2, NULL, 3);
//	printf("After ft_memcpy  = %s\n", str2);
//	char str3[] = "hello";
//	ft_memcpy(str3, NULL, 3);
//}