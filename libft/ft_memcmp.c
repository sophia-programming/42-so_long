/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaoba <oaoba@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 19:52:53 by oaoba             #+#    #+#             */
/*   Updated: 2023/02/01 19:52:58 by oaoba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	const unsigned char	*str1;
	const unsigned char	*str2;

	i = 0;
	str1 = (const unsigned char *)s1;
	str2 = (const unsigned char *)s2;
	while (i < n)
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		i++;
	}
	return (0);
}

//#include<stdio.h>
//#include<string.h>
//int main(void)
//{
//	printf("%d\n", memcmp("hello", "hello", 6));
//	printf("%d\n", memcmp("cats", "catt", 4));
//	printf("%d\n", memcmp(NULL, NULL, 2));
//	printf("-------------------------------\n");
//	printf("%d\n", ft_memcmp("hello", "hello", 6));
//	printf("%d\n", ft_memcmp("cats", "catt", 4));
//	printf("%d\n", ft_memcmp(NULL, NULL, 2));
//}