/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaoba <oaoba@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 18:10:03 by oaoba             #+#    #+#             */
/*   Updated: 2023/02/01 19:42:32 by oaoba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"libft.h"

/*
 * https://en.cppreference.com/w/cpp/string/byte/atoi
 * 戻り値の型であるintの範囲外である時の動作は未定義動作なので、対応する必要がない
 * [参考資料]
 * https://yohhoy.hatenadiary.jp/entry/20200604/p1
 */

int	ft_isspace(int c)
{
	return (c == '\f' || c == '\t' || c == ' '
		|| c == '\n' || c == '\r' || c == '\v');
}

int	ft_atoi(const char *str)
{
	int			sign;
	long long	result;
	size_t		i;

	result = 0;
	sign = 1;
	i = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] && '0' <= str[i] && str[i] <= '9')
		result = result * 10 + (str[i++] - '0');
	return (result * sign);
}

//#include<libc.h>
//int main(int argc, char **argv)
//{
//	if (argc == 2)
//		printf("%d\n", atoi(argv[1]));
//}
//