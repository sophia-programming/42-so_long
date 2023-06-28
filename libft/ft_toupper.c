/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaoba <oaoba@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 19:56:02 by oaoba             #+#    #+#             */
/*   Updated: 2023/02/01 19:56:04 by oaoba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

int	ft_toupper(int c)
{
	if ('a' <= c && c <= 'z')
		return (c - 'a' + 'A');
	else
		return (c);
}

//#include<ctype.h>
//#include<stdio.h>
//int main(void)
//{
//    printf("%c\n", toupper ('a'));
//    printf("%c\n", toupper ('f'));
//    printf("%c\n", toupper ('Z'));
//    printf("%c\n", toupper ('$'));
//    printf("%c\n", toupper ('3'));
//    printf("----------------------\n");
//    printf("%c\n", ft_toupper ('a'));
//    printf("%c\n", ft_toupper ('f'));
//    printf("%c\n", ft_toupper ('Z'));
//    printf("%c\n", ft_toupper ('$'));
//    printf("%c\n", ft_toupper ('3'));
//}