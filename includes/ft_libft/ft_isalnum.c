/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wooyang <wooyang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 19:56:06 by wooyang           #+#    #+#             */
/*   Updated: 2025/05/14 18:42:35 by wooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else if (c >= '0' && c <= '9')
		return (2);
	else
		return (0);
}
/*
int	main(void)
{
	printf("a = %d (ft)\n", ft_isalnum('a'));
	printf("a = %d (vrai)\n\n", isalnum('a'));
        printf("A = %d (ft)\n", ft_isalnum('A'));
        printf("A = %d (vrai)\n\n", isalnum('A'));
        printf("0 = %d (ft)\n", ft_isalnum('0'));
        printf("0 = %d (vrai)\n\n", isalnum('0'));
	printf("1 = %d (ft)\n", ft_isalnum('1'));
        printf("1 = %d (vrai)\n\n", isalnum('1'));
        printf("! = %d (ft)\n", ft_isalnum('!'));
        printf("! = %d (vrai)\n\n", isalnum('!'));
        printf("\t = %d (ft)\n", ft_isalnum('\t'));
        printf("\t = %d (vrai)\n\n", isalnum('\t'));
	return (0);
}*/
