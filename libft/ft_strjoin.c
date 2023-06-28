/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaoba <oaoba@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 03:32:37 by oaoba             #+#    #+#             */
/*   Updated: 2023/02/04 03:32:38 by oaoba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	size_t	i;
	size_t	j;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	new = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!new)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		new[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		new[i] = s2[j];
		i++;
		j++;
	}
	new[i] = '\0';
	return (new);
}

//#include<stdio.h>
//int main(void)
//{
//	printf("%s\n", ft_strjoin("neko", "world"));
//	printf("%s\n", ft_strjoin("", ""));
//	printf("%s\n", ft_strjoin("", "world"));
//	printf("%s\n", ft_strjoin("42", "Tokyo"));
//	printf("%s\n", ft_strjoin(NULL, "Tokyo"));
//	printf("%s\n", ft_strjoin(NULL, NULL));
//}