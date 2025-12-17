/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wooyang <wooyang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 17:42:20 by wooyang           #+#    #+#             */
/*   Updated: 2025/05/14 15:10:45 by wooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// static char	ft_test(unsigned int n, char c)
// {
// 	if (n >= 0 && (c >= 'a' && c <= 'z'))
// 		c = c - 32;
// 	return (c);
// }

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	int		len;
	char	*resultat;

	i = 0;
	len = ft_strlen(s);
	resultat = malloc(sizeof(char) * (len + 1));
	if (resultat == NULL)
		return (NULL);
	while (s[i])
	{
		resultat[i] = f(i, s[i]);
		i++;
	}
	resultat[i] = '\0';
	return (resultat);
}
/*
int main(void)
{
	char *mot = "bonjour";
	char *str = ft_strmapi(mot, &ft_test);
	char *str2 = ft_strmapi(mot, &ft_test);
	printf("avant : %s\n", mot);
	printf("apres : %s\n", str);
	printf("apres : %s\n", str2);
	return (0);
}*/
