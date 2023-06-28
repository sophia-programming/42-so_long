/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaoba <oaoba@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 03:46:03 by oaoba             #+#    #+#             */
/*   Updated: 2023/02/04 03:46:05 by oaoba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strndup(const char *s1, size_t n)
{
	return (ft_substr(s1, 0, n));
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t		len;
	char		*str;

	str = (char *)s1;
	if (str == NULL || set == NULL)
		return (NULL);
	while (*str != '\0' && ft_strchr(set, *str))
		str++;
	len = ft_strlen(str);
	while (len != 0 && ft_strchr(set, str[len]))
		len--;
	return (ft_strndup(str, len + 1));
}

//#include<stdio.h>
//int main(void)
//
//{
//	printf("%s\n", ft_strtrim("ababa", "a"));
//	printf("%s\n", ft_strtrim("ababababa", "a"));
//	printf("%s\n", ft_strtrim("ccdc", "a"));
//	printf("%s\n", ft_strtrim(" ", "a"));
//	printf("%s\n", ft_strtrim(NULL, "a"));
//	printf("%s\n", ft_strtrim(NULL, NULL));
//	printf("%s\n", ft_strtrim("1234AAA22331122", "1234"));
//}