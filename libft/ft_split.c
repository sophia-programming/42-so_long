/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaoba <oaoba@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 03:46:58 by oaoba             #+#    #+#             */
/*   Updated: 2023/02/04 03:47:01 by oaoba            ###   ########.fr       */
/*                                                                           */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_strs(char const *str, char c)
{
	size_t	strs_num;
	size_t	i;

	strs_num = 0;
	i = 0;
	while (str[i] == c)
		i++;
	while (str[i])
	{
		if (str[i] == c)
		{
			while (str[i] == c)
				i++;
			if (str[i] == '\0')
				break ;
			strs_num++;
		}
		i++;
	}
	return (strs_num + 1);
}

static char	**all_free(char **strs)
{
	size_t	i;

	i = 0;
	while (strs[i])
	{
		free(strs[i]);
		i++;
	}
	free(strs);
	return (NULL);
}

static char	*ft_strndup(const char *s1, size_t n)
{
	return (ft_substr(s1, 0, n));
}

static char	**get_strs(char **strs, const char *str, char c)
{
	size_t		len;
	size_t		strs_index;
	const char	*start_pos;

	strs_index = 0;
	while (*str != '\0')
	{
		while (*str == c)
			str++;
		start_pos = str;
		len = 0;
		while (*str != '\0' && *str != c)
		{
			str++;
			len++;
		}
		if (ft_strlen(start_pos) != 0)
		{
			strs[strs_index] = ft_strndup(start_pos, len);
			if (strs[strs_index] == NULL)
				return (all_free(strs));
			strs_index++;
		}
	}
	return (strs);
}

char	**ft_split(char const *str, char c)
{
	char		**strs;

	if (str == NULL)
		return (NULL);
	strs = ft_calloc(count_strs(str, c) + 1, sizeof(char *));
	if (strs == NULL)
		return (NULL);
	return (get_strs(strs, str, c));
}

//int main(int argc, char **argv)
//{
//	if (argc == 2)
//	{
//		char **strs = ft_split(argv[1], ',');
//		for (size_t i = 0; strs[i]; i++)
//		{
//			printf("%s\n", strs[i]);
//		}
//	}
//}

//#include <stdio.h>
// int	main(void)
// {
// 	char	**s;
// 	s = ft_split("a,b,c,d,e", ',');
// 	for (int i = 0; s[i] != NULL; i++)
// 		printf("%s\n", s[i]);
// 	printf("-----\n");
// 	s = ft_split("  aiueo   abc 123    ", ' ');
// 	for (int i = 0; s[i] != NULL; i++)
// 		printf("%s\n", s[i]);
// 	printf("-----\n");
// 	s = ft_split("     ", ' ');
//	 for (int i = 0; s[i] != NULL; i++)
// 		printf("%s\n", s[i]);
// 	printf("-----\n");
//     s = ft_split("",  ',');
//	 for (int i = 0; s[i] != NULL; i++)
//         printf("%s\n", s[i]);
// }
