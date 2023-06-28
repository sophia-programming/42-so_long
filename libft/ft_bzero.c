/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaoba <oaoba@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 16:43:45 by oaoba             #+#    #+#             */
/*   Updated: 2023/01/11 16:44:53 by oaoba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}

//#include <stdio.h>
//#include <libc.h>
//int main(void) {
//	char s[] = "hello cats!";
//	ft_bzero(s + 5, 3);
//	printf("%s\n", s);
//	printf("-----------------\n");
//	bzero(s + 5, 3);
//	printf("%s\n", s);
//}

//sにnバイト分0を書き込む
//lenが０の場合、bzero()は何もしない