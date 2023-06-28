/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaoba <oaoba@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 14:11:13 by oaoba             #+#    #+#             */
/*   Updated: 2023/02/19 14:11:27 by oaoba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const	*s, char (*f) (unsigned int, char))
{
	size_t	i;
	char	*result;

	if (s == NULL || f == NULL)
		return (NULL);
	result = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (result == NULL)
		return (NULL);
	i = 0;
	while (i < ft_strlen(s))
	{
		result[i] = f(i, s[i]);
		i++;
	}
	result[i] = '\0';
	return (result);
}

//char f(unsigned	 int i, char c)
//{
//	if ('a' <= c && c <= 'z')
//		c = (c - 'a' + 'A');
//	return (c);
//}
//
//#include <libc.h>
//int main(void)
//{
//	char *s = ft_strmapi("HeLlO wOrLd!!", f);
//	printf("%s\n", s);
//}
//