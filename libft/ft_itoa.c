/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaoba <oaoba@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 22:20:49 by oaoba             #+#    #+#             */
/*   Updated: 2023/02/01 22:20:53 by oaoba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

size_t	len(long long nb)
{
	size_t	len;

	len = 0;
	if (nb == 0)
		return (1);
	if (nb < 0)
	{
		nb = nb * -1;
		len++;
	}
	while (nb > 0)
	{
		nb = nb / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int nb)
{
	char		*str;
	long long	n;
	size_t		i;

	n = nb;
	i = len(n);
	str = (char *)ft_calloc(i + 1, sizeof(char));
	if (str == NULL)
		return (NULL);
	if (n == 0)
	{
		str[0] = '0';
		return (str);
	}
	if (n < 0)
	{
		str[0] = '-';
		n = n * -1;
	}
	while (n > 0)
	{
		str[--i] = (n % 10) + '0';
		n = n / 10;
	}
	return (str);
}

//#include <limits.h>
//#include<stdio.h>
//int main(void)
//{
//	printf("%s\n", ft_itoa(42));
//	printf("%s\n", ft_itoa(12345));
//	printf("%s\n", ft_itoa(9870));
//	printf("%s\n", ft_itoa(INT_MIN));
//	printf("%s\n", ft_itoa(INT_MAX));
//	return (0);
//}