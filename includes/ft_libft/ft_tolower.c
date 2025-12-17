/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wooyang <wooyang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 19:15:42 by wooyang           #+#    #+#             */
/*   Updated: 2025/05/14 16:03:00 by wooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		c = c + 32;
	return (c);
}
/*
int	main(void)
{
	printf("a = %d (ft)\n", ft_tolower('a'));
	printf("a = %d (vrai)\n\n", tolower('a'));
	printf("A = %d (ft)\n", ft_tolower('A'));
	printf("A = %d (vrai)\n\n", tolower('A'));
	printf("1 = %d (ft)\n", ft_tolower('1'));
	printf("1 = %d (vrai)\n\n", tolower('1'));
	printf("! = %d (ft)\n", ft_tolower('!'));
	printf("! = %d (vrai)\n\n", tolower('!'));
	printf("\t = %d (ft)\n", ft_tolower('\t'));
	printf("\t = %d (vrai)\n\n", tolower('\t'));
	return (0);
}*/
