/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wooyang <wooyang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 19:48:10 by wooyang           #+#    #+#             */
/*   Updated: 2025/05/14 15:45:11 by wooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (0);
	return (1);
}
/*
int	main(void)
{
	printf("1 = %d (ft)\n", ft_isdigit('1'));
	printf("1 = %d (vrai)\n\n", isdigit('1'));
        printf("0 = %d (ft)\n", ft_isdigit('0'));
        printf("0 = %d (vrai)\n\n", isdigit('0'));
	printf("a = %d (ft)\n", ft_isdigit('a'));
	printf("a = %d (vrai)\n\n", isdigit('a'));
	printf("A = %d (ft)\n", ft_isdigit('A'));
	printf("A = %d (vrai)\n\n", ft_isdigit('A'));
	printf("\t = %d (ft)\n", ft_isdigit('\t'));
	printf("\t = %d (vrai)\n\n", ft_isdigit('\t'));
	return (0);
}*/
