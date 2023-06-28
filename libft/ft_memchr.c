/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaoba <oaoba@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 19:43:02 by oaoba             #+#    #+#             */
/*   Updated: 2023/02/01 19:44:04 by oaoba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	*ft_memchr(const void	*s, int c, size_t n)
{
	size_t			i;
	unsigned char	*string;

	if (s == NULL)
		return (NULL);
	i = 0;
	string = (unsigned char *)s;
	while (i < n)
	{
		if (string[i] == (unsigned char)c)
			return (&string[i]);
		i++;
	}
	return (NULL);
}

//#include <stdio.h>
//#include <string.h>
//
//int main ()
//{
//	const char str[] = "http://www.tutorialspoint.com";
//	const char ch = '.';
//	char *ret;
//
//	ret = ft_memchr(str, ch, strlen(str));
//
//	printf("String after |%c| is - |%s|\n", ch, ret);
//
//	return(0);
//}