/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaoba <oaoba@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 16:50:26 by oaoba             #+#    #+#             */
/*   Updated: 2023/01/11 16:50:28 by oaoba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	srcsize;
	size_t	i;

	srcsize = ft_strlen(src);
	i = 0;
	if (dstsize != 0)
	{
		while (src[i] != '\0' && i < (dstsize -1))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (srcsize);
}

//#include<string.h>
//#include<stdio.h>
//int main(void)
//{
//	char dest1[20] = "abcdef";
//	char src1[] = "1234567";
//	printf("before strlcpy = %s\n", src1);
//	strlcpy(dest1, src1, 5);
//	printf("after strlcpy = %s\n", dest1);
//	printf("==========================\n");
//	char dest2[20] = "abcdef";
//	char src2[] = "1234567";
//	printf("before ft_strlcpy = %s\n", src2);
//	ft_strlcpy(dest2, src2, 5);
//	printf("after ft_strlcpy = %s\n", dest2);
//}