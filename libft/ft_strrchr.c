/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaoba <oaoba@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 19:54:48 by oaoba             #+#    #+#             */
/*   Updated: 2023/02/01 19:54:51 by oaoba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	char	*last_occurence;

	last_occurence = NULL;
	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			last_occurence = (char *)&s[i];
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)&s[i]);
	return (last_occurence);
}

//#include<stdio.h>
//#include<string.h>
//int main(void)
//{
//    printf("%s\n", strrchr("hello world", 'w'));
//    printf("%s\n", strrchr("cat4", '4'));
//    printf("%s\n", strrchr("NULL", '4'));
//    printf("-------------------------------\n");
//    printf("%s\n", ft_strrchr("hello world", 'w'));
//    printf("%s\n", ft_strrchr("cat4", '4'));
//    printf("%s\n", ft_strrchr("NULL", '4'));
//}