/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaoba <oaoba@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 16:47:30 by oaoba             #+#    #+#             */
/*   Updated: 2023/01/11 16:47:52 by oaoba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

int	ft_isalpha(int c)
{
	if (('A' <= c && c <= 'Z') || ('a' <= c && c <= 'z'))
		return (true);
	else
		return (false);
}

//#include <stdio.h>
//int main(void)
//{
//	printf("%d\n",ft_isalpha('a'));
//	printf("%d\n",ft_isalpha('0'));
//	printf("%d\n",ft_isalpha('3'));
//	printf("%d\n",ft_isalpha('b'));
//	printf("%d\n",ft_isalpha('2'));
//}