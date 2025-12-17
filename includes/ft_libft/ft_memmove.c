/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wooyang <wooyang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 15:30:01 by wooyang           #+#    #+#             */
/*   Updated: 2025/05/14 15:58:06 by wooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*char_dest;
	unsigned char	*char_src;

	char_dest = (unsigned char *)dest;
	char_src = (unsigned char *)src;
	i = 0;
	if (!dest && !src)
		return (NULL);
	while (i < n)
	{
		if (dest < src)
			char_dest[i] = char_src[i];
		else
			char_dest[n -1 - i] = char_src[n -1 - i];
		i++;
	}
	return (dest);
}

/*
int	main(void)
	char    ap[] = "abcdefghijklmnopqrs";
        char    ap_vrai[] = "abcdefghijklmnopqrs";
        char    Lecourbe[] = "Lecourbe";
        char    Lecourbe_vrai[] = "Lecourbe";
        char    montrouge[] = "montrouge";
        char    montrouge_vrai[] = "montrouge";

        printf("ap[15] - ap[16] = %ld\n", &ap[15] - &ap[16]);
        printf("ap[15] - ap[17] = %ld\n", &ap[15] - &ap[17]);
        printf("ap[18] - ap[0] = %ld\n", &ap[18] - &ap[0]);
        printf("ap[0] - ap[2] = %ld\n", &ap[0] - &ap[2]);
        printf("ap[9] - ap[0] = %ld\n", &ap[9] - &ap[2]);
        printf("len ap = %zu\n", strlen(ap));

        char    a[] = "abc";
        char    b[] = "bcd";
        char    c[] = "cde";
        char    d[] = "def";
        char    e[] = "efg";
        printf("a %p\nb %p\nc %p\nd %p\ne %p\n", &a, &b, &c, &d, &e);
        printf("a - b = %ld\n", a - b);
        printf("c - d = %ld\n", c - d);
        printf("a[0] - a[1] = %ld\n", &a[0] - &a[1]);
        printf("a[1] - a[2] = %ld\n", &a[1] - &a[2]);
        printf("a[2] - a[3] = %ld\n", &a[2] - &a[3]);
        printf("a[0] - a[2] = %ld\n", &a[0] - &a[2]);
        printf("a[0] = %p\na[1] = %p\na[2] = %p\n", &a[0], &a[1], &a[2]);
        return (0);
}*/
