/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wooyang <wooyang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 15:40:22 by wooyang           #+#    #+#             */
/*   Updated: 2025/05/01 17:46:56 by wooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	destlen;
	size_t	srclen;

	i = 0;
	j = 0;
	destlen = 0;
	if (size == 0)
		return (ft_strlen(src));
	while (dest[i] != '\0')
		i++;
	destlen = ft_strlen(dest);
	srclen = ft_strlen(src);
	while (src[j] != '\0' && destlen + j < size - 1)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	if (size < destlen)
		return (srclen + size);
	else
		return (srclen + destlen);
}
/*
int	main(void)
{
	char s1[50] = "bonjour";
	char s2[50] = "123456789";
	printf("%zu", ft_strlcat(s1, s2, 100));
}*/
