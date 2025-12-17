/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wooyang <wooyang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 18:34:05 by wooyang           #+#    #+#             */
/*   Updated: 2025/05/14 16:18:00 by wooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// void	ft_test(unsigned int n, char c)
// {
// 	if (n >= 0 && (c >= 'a' && c <= 'z'))
// 	{
// 		c = c - 32;
// 		write(1, &c, 1);
// 	}
// }

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}
/*
int	main(void)
{
	char	*mot = "bonjour";
	printf("%s\n", mot);
	ft_striteri(mot, &ft_test);
	return (0);
}*/
