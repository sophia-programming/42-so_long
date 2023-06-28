/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaoba <oaoba@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 02:02:21 by oaoba             #+#    #+#             */
/*   Updated: 2023/01/17 02:02:32 by oaoba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	real_dst_len;
	size_t	result;

	if (dst == NULL && dstsize == 0)
		return (ft_strlen(src));
	real_dst_len = ft_strlen(dst);
	if (real_dst_len < dstsize)
		result = real_dst_len + ft_strlen(src);
	else
		result = dstsize + ft_strlen(src);
	if (real_dst_len < dstsize)
		ft_strlcpy(dst + real_dst_len, src, dstsize - real_dst_len);
	return (result);
}

//#include<stdio.h>
//#include<string.h>
//int main(void)
//{
//	char dst[9] = "42";
//	char src[] = "world";
//	printf("[before strlcat]%s\n", dst);
//	size_t len = strlcat(dst, src, 8);
//	printf("[after strlcat]%s\n", dst);
//	printf("------------------------------\n");
//	char dst2[9] = "42";
//	char src2[] = "world";
//	printf("[before ft_strlcat]%s\n", dst2);
//	size_t dstsize = ft_strlcat(dst2, src2, 8);
//	printf("[after ft_strlcat]%s\n", dst2);
//}
//