/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaoba <oaoba@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 19:54:01 by oaoba             #+#    #+#             */
/*   Updated: 2023/02/01 19:54:04 by oaoba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] != '\0' \
		&& s2[i] != '\0' \
		&& s1[i] == s2[i] \
		&& i < n - 1)
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

//#include<stdio.h>
//#include<string.h>
//int main(void)
//{
//	printf("%d\n", strncmp("hello", "hel", 4));
//	printf("%d\n", strncmp("hello", "wor", 5));
//	printf("%d\n", strncmp("hello", "hello", 5));
//	printf("------------------------------\n");
//	printf("%d\n", ft_strncmp("hello", "hel", 4));
//	printf("%d\n", ft_strncmp("hello", "wor", 5));
//	printf("%d\n", ft_strncmp("hello", "hello", 5));
//}