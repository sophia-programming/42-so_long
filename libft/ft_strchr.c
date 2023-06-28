/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaoba <oaoba@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 19:53:39 by oaoba             #+#    #+#             */
/*   Updated: 2023/02/01 19:53:41 by oaoba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	if (c == '\0')
		return ((char *)&s[i]);
	return (NULL);
}

//#include <stdio.h>
//#include <stdlib.h>
//
//int    main(int argc, char *argv[])
//{
//	int        c;
//	char    *p;
//
//	if (argc != 3)
//	{
//		fprintf(stderr, "Usage: %s [str] [char]\n", argv[0]);
//		exit(1);
//	}
//	c = argv[2][0];
//	if ((p = ft_strchr(argv[1], c)) != NULL)
//	{
//		printf("ft_strchr():  '%c' is found in \"%s\".\n", c, argv[1]);
//		printf("ft_strchr():  s = %p, p = %p, pos = %ld\n", argv[1],
//			   p, p - argv[1]);
//	}
//	else
//		printf("ft_strchr():  '%c' is not found in \"%s\".\n", c, argv[1]);
//	return (0);
//}