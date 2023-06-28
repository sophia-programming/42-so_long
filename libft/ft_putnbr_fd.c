/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaoba <oaoba@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 14:10:55 by oaoba             #+#    #+#             */
/*   Updated: 2023/02/19 14:11:27 by oaoba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long long	nb;

	nb = n;
	if (nb < 0)
	{
		ft_putchar_fd('-', fd);
		nb = nb * -1;
	}
	if (nb > 9)
	{
		ft_putnbr_fd(nb / 10, fd);
	}
	ft_putchar_fd((nb % 10) + '0', fd);
}

//#include<stdio.h>
//int main(void)
//{
//	ft_putnbr_fd(20, 1);
//	printf("\n");
//	ft_putnbr_fd(1234567, 2);
//	printf("\n");
//	ft_putnbr_fd(0, 1);
//	printf("\n");
//	ft_putnbr_fd(-2147483648, 2);
//	printf("\n");
//}