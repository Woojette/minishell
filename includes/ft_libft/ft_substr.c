/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wooyang <wooyang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 17:42:18 by wooyang           #+#    #+#             */
/*   Updated: 2025/05/22 16:00:30 by wooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	size_t			n;
	char			*resultat;

	i = 0;
	n = 0;
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	resultat = malloc((len + 1) * sizeof(char));
	if (resultat == NULL)
		return (NULL);
	while (s[start + i] != '\0' && n < len && start < ft_strlen(s))
	{
		resultat[i] = s[start + i];
		n++;
		i++;
	}
	resultat[i] = '\0';
	return (resultat);
}

// int	main(void)
// {
// 	char	texte[] = "0123456789abcdef123465789";
// 	printf("%s\n", ft_substr(texte, 5, 10));
// 	return (0);
// }
