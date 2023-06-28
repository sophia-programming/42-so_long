/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaoba <oaoba@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 14:11:09 by oaoba             #+#    #+#             */
/*   Updated: 2023/02/19 14:11:27 by oaoba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	size_t	i;
	size_t	s_len;

	i = 0;
	if (s == NULL || f == NULL)
		return ;
	s_len = ft_strlen(s);
	while (i < s_len)
	{
		f(i, &s[i]);
		i++;
	}
}

//void func(unsigned int i, char *c)
//{
//	if ('a' <= *c && *c <= 'z')
//		*c = (*c - 'a' + 'A');
//}
//
//#include<stdio.h>
//int main()
//{
//	char str[] = "hello world";
//	ft_striteri(str, &func);
//	printf("%s\n", str);
//	return 0;
//}