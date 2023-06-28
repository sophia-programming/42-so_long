/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaoba <oaoba@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 16:49:03 by oaoba             #+#    #+#             */
/*   Updated: 2023/01/11 16:49:05 by oaoba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

int	ft_isprint(int c)
{
	if (32 <= c && c <= 126)
		return (true);
	else
		return (false);
}

//#include<stdio.h>
//int main(void)
//{
//	printf("%d\n", ft_isprint('a'));
//	printf("%d\n", ft_isprint(' '));
//	printf("%d\n", ft_isprint('A'));
//	printf("%d\n", ft_isprint('#'));
//	printf("%d\n", ft_isprint(23));
//}
