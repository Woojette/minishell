/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wooyang <wooyang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 20:07:04 by wooyang           #+#    #+#             */
/*   Updated: 2025/05/14 15:51:54 by wooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	else
		return (0);
}
/*
int	main(void)
{
	printf("2 = %d (ft)\n", ft_isprint('2'));
	printf("2 = %d (vrai)\n\n", isprint('2'));
        printf("a = %d (ft)\n", ft_isprint('a'));
        printf("a = %d (vrai)\n\n", isprint('a'));
        printf("\t = %d (ft)\n", ft_isprint('\t'));
        printf("\t = %d (vrai)\n\n", isprint('\t'));
	return (0);
}*/
