/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaoba <oaoba@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 14:11:04 by oaoba             #+#    #+#             */
/*   Updated: 2023/02/19 14:11:27 by oaoba            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	ssize_t	ret;

	if (s == NULL)
		return ;
	ret = write(fd, s, ft_strlen(s));
	if (ret == -1)
		ft_putstr_fd("Error: write()", 2);
}

//#include <limits.h>
//#include <libc.h>
//int main(void)
//{
//	ft_putstr_fd("neko\n", 1);
//	ft_putstr_fd("42 Tokyo\n", 1);
//	ft_putstr_fd("Tokyo\n", 1);
//	ft_putstr_fd("Paris\n", 1);
//	ft_putstr_fd(NULL, 1);
//	char *s = malloc(sizeof(char) * (INT_MAX + 2L));
//	memset(s, 'a', INT_MAX + 1L);
//	ft_putstr_fd(s, 1);
//}
