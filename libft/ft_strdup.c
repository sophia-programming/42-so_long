/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaoba <oaoba@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 02:04:59 by oaoba             #+#    #+#             */
/*   Updated: 2023/02/11 02:04:59 by oaoba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*new;
	size_t	i;

	new = malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (new == NULL)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		new[i] = s1[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

//#include<stdio.h>
//int main(void)
//{
//	printf("%s\n", ft_strdup("hello"));
//	printf("%s\n", ft_strdup("cats"));
//	printf("%s\n", ft_strdup("42Tokyo"));
//	printf("%s\n", ft_strdup("world"));
//}
