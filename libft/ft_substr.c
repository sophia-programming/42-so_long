/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaoba <oaoba@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 03:31:56 by oaoba             #+#    #+#             */
/*   Updated: 2023/02/04 03:31:59 by oaoba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;

	if (s == NULL)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s))
		len = ft_strlen(s);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	ft_strlcpy(str, &s[start], len + 1);
	return (str);
}

//#include<stdio.h>
//int main(void)
//{
//	printf("%s\n", ft_substr("abcde", 4, 3));
//	printf("%s\n", ft_substr("abcdefghi", 3, 5));
//	printf("%s\n", ft_substr(NULL, 3, 5));
//	printf("%s\n", ft_substr("hello", 3, 0));
//	printf("%s\n", ft_substr("hello", 6, 5));
//}