/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaoba <oaoba@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 16:46:52 by oaoba             #+#    #+#             */
/*   Updated: 2023/01/11 16:46:59 by oaoba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if (ft_isalpha(c) || ft_isdigit(c))
		return (true);
	else
		return (false);
}

//#include <stdio.h>
// int main(void)
// {
//	printf("%d\n", ft_isalnum('a'));
//	printf("%d\n", ft_isalnum('4'));
//	printf("%d\n", ft_isalnum('0'));
//	printf("%d\n", ft_isalnum('F'));
//	printf("%d\n", ft_isalnum('#'));
// }