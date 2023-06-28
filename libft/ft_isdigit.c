/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaoba <oaoba@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 16:48:45 by oaoba             #+#    #+#             */
/*   Updated: 2023/01/11 16:48:48 by oaoba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

int	ft_isdigit(int c)
{
	if ('0' <= c && c <= '9')
		return (true);
	else
		return (false);
}

//#include<stdio.h>
//int main(void)
//{
//	printf("%d\n",ft_isdigit('3'));
//	printf("%d\n",ft_isdigit('1'));
//	printf("%d\n",ft_isdigit('a'));
//	printf("%d\n",ft_isdigit('4'));
//	printf("%d\n",ft_isdigit('0'));
//}