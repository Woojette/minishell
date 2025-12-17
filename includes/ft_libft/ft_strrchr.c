/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wooyang <wooyang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 19:07:28 by wooyang           #+#    #+#             */
/*   Updated: 2025/05/22 15:59:27 by wooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int val)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	if (val == '\0' && str[i] == '\0')
		return ((char *)&str[i]);
	while (i >= 0)
	{
		if (str[i] == (unsigned char)val)
			return ((char *)&str[i]);
		i--;
	}
	return (NULL);
}

// int	main(void)
// {
// 	char *test = "teste";
// 	char *res = ft_strrchr("teste", '\0');
// 	printf("test: %p, res: %p\n", test, res);

// 	char *test1 = "teste";
// 	char *res1 = strrchr("teste", '\0');
// 	printf("test: %p, res: %p", test1, res1);
// 	return (0);
// }
