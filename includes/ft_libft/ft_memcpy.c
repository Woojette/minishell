/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wooyang <wooyang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 12:46:52 by wooyang           #+#    #+#             */
/*   Updated: 2025/05/22 15:56:54 by wooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (!dest && !src)
		return (dest);
	while (i < n)
	{
		((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dest);
}
/*
int	main(void)
{
	char	destination[10] = "aaaaaaaaa";
	char	destination_vrai[10] = "aaaaaaaaa";
	char	source[] = "coucou";

	printf("%s\n", (unsigned char *)ft_memcpy(destination, source + 2, 7));
	printf("%s\n", (unsigned char *)memcpy(destination_vrai, source + 2, 7));
	return (0);
}*/
