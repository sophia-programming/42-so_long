/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaoba <oaoba@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 19:54:23 by oaoba             #+#    #+#             */
/*   Updated: 2023/02/01 19:54:26 by oaoba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	if (needle == NULL || haystack == NULL)
		return (NULL);
	if (needle[0] == '\0')
		return ((char *)haystack);
	i = 0;
	while (haystack[i] && i < len)
	{
		j = 0;
		while (haystack[i + j] != '\0'
			&& needle[j] != '\0'
			&& i + j < len
			&& haystack[i + j] == needle[j])
			j++;
		if (needle[j] == '\0')
			return ((char *)&haystack[i]);
		i++;
	}
	return (NULL);
}

//#include<stdio.h>
//#include<string.h>
//int main(void)
//{
//	printf("%s\n", strnstr("hello", "ll", 6));
//	printf("%s\n", strnstr("world", "ld", 0));
//	printf("%s\n", strnstr(NULL, "is", 0));
//	printf("%s\n", strnstr("abbbcdefg", "bbc", 20));
//	printf("--------------------\n");
//	printf("%s\n", ft_strnstr("hello", "ll", 6));
//	printf("%s\n", ft_strnstr("world", "ld", 0));
//	printf("%s\n", ft_strnstr(NULL, "is", 0));
//	printf("%s\n", ft_strnstr("abbbcdefg", "bbc", 20));
//}