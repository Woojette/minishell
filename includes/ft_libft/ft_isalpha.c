/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wooyang <wooyang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 19:41:48 by wooyang           #+#    #+#             */
/*   Updated: 2025/05/14 15:45:51 by wooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (2);
	else if (c >= 'a' && c <= 'z')
		return (1);
	else
		return (0);
}
/*
int	main(void)
{
	printf("a = %d (ft)\n", ft_isalpha('a'));
	printf("a = %d (vrai)\n\n", isalpha('a'));
        printf("A = %d (ft)\n", ft_isalpha('A'));
        printf("A = %d (vrai)\n\n", isalpha('A'));
        printf("1 = %d (ft)\n", ft_isalpha('1'));
        printf("1 = %d (vrai)\n\n", isalpha('1'));
        printf("b = %d (ft)\n", ft_isalpha('b'));
        printf("b = %d (vrai)\n\n", isalpha('b'));
	return (0);
}*/
