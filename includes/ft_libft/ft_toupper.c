/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wooyang <wooyang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 19:03:00 by wooyang           #+#    #+#             */
/*   Updated: 2025/05/14 16:02:16 by wooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		c = c - 32;
	return (c);
}
/*
int	main(void)
{
	printf("min = %d (ft)\n", ft_toupper('a'));
	printf("min = %d (vrai)\n\n", toupper('a'));
	printf("maj = %d (ft)\n", ft_toupper('A'));
	printf("maj = %d (vrai)\n\n", toupper('A'));
	printf("5 = %d (ft)\n", ft_toupper('5'));
	printf("5 = %d (vrai)\n\n", toupper('5'));
        printf("ligne = %d (ft)\n", ft_toupper('\n'));
        printf("ligne = %d (vrai)\n\n", toupper('\n'));
	printf("# = %d (ft)\n", ft_toupper('#'));
        printf("# = %d (vrai)\n\n", toupper('#'));
	return (0);
}*/
