/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaoba <oaoba@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 16:48:15 by oaoba             #+#    #+#             */
/*   Updated: 2023/01/11 16:48:19 by oaoba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

int	ft_isascii(int c)
{
	if (0 <= c && c <= 127)
		return (true);
	else
		return (false);
}

//#include <stdio.h>
//int main(void)
//{
//	printf("%d\n", ft_isascii(' '));
//	printf("%d\n", ft_isascii('g'));
//	printf("%d\n", ft_isascii('5'));
//	printf("%d\n", ft_isascii('0'));
//	printf("%d\n", ft_isascii(128));
//}