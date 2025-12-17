/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wooyang <wooyang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 18:28:05 by wooyang           #+#    #+#             */
/*   Updated: 2025/05/14 16:12:31 by wooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*s1_char;
	unsigned char	*s2_char;

	i = 0;
	s1_char = (unsigned char *)s1;
	s2_char = (unsigned char *)s2;
	while (i < n)
	{
		if (s1_char[i] != s2_char[i])
			return (s1_char[i] - s2_char[i]);
		i++;
	}
	return (0);
}
/*
int	main(void)
{
	printf("3 abcde vs abcde = %d (ft)\n", ft_memcmp("abcde", "abcde", 3));
	printf("3 abcde vs abcde = %d (vrai)\n\n", memcmp("abcde", "abcde", 3));
	printf("3 abccc vs abc = %d (ft)\n", ft_memcmp("abccc", "abc", 3));
	printf("3 abcde vs abc = %d (vrai)\n\n", memcmp("abcde", "abc", 3));
	printf("4 abcde vs abc = %d (ft)\n", ft_memcmp("abcde", "abc", 4));
	printf("4 abcde vs abc = %d (vrai)\n\n", memcmp("abcde", "abc", 4));
        printf("4 abaaa vs abc = %d (ft)\n", ft_memcmp("abaaa", "abc", 5));
        printf("4 abaaa vs abc = %d (vrai)\n\n", memcmp("abaaa", "abc", 5));
	printf("1 zaa vs azz = %d (ft)\n", ft_memcmp("zaa", "azz", 1));
	printf("1 zaa vs azz = %d (vrai)\n\n", memcmp("zaa", "azz", 1));
        printf("2 zaa vs azz = %d (ft)\n", ft_memcmp("zaa", "azz", 2));
        printf("2 zaa vs azz = %d (vrai)\n\n", memcmp("zaa", "azz", 2));
        printf("3 zaa vs azz = %d (ft)\n", ft_memcmp("zaa", "azz", 3));
        printf("3 zaa vs azz = %d (vrai)\n\n", memcmp("zaa", "azz", 3));
        printf("3 zaa vs az = %d (ft)\n", ft_memcmp("zaa", "az", 3));
        printf("3 zaa vs az = %d (vrai)\n\n", memcmp("zaa", "az", 3));
        printf("3 aeaa vs ax = %d (ft)\n", ft_memcmp("aeaa", "ax", 3));
        printf("3 aeaa vs ax = %d (vrai)\n\n", memcmp("aeaa", "ax", 3));

	return (0);
}*/
