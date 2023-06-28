/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaoba <oaoba@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 19:55:19 by oaoba             #+#    #+#             */
/*   Updated: 2023/02/01 19:55:21 by oaoba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

int	ft_tolower(int c)
{
	if ('A' <= c && c <= 'Z')
		return (c - 'A' + 'a');
	else
		return (c);
}

//#include<stdio.h>
//#include<ctype.h>
//int main(void)
//{
//	printf("%c\n", tolower('a'));
//	printf("%c\n", tolower('E'));
//	printf("%c\n", tolower('5'));
//	printf("%c\n", tolower('$'));
//	printf("--------------------------\n");
//	printf("%c\n", ft_tolower('a'));
//	printf("%c\n", ft_tolower('E'));
//	printf("%c\n", ft_tolower('5'));
//	printf("%c\n", ft_tolower('$'));
//}