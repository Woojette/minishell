/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wooyang <wooyang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 16:07:50 by wooyang           #+#    #+#             */
/*   Updated: 2025/05/05 16:36:19 by wooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *str)
{
	char	*resultat;
	size_t	len;
	size_t	i;

	i = 0;
	len = ft_strlen(str);
	resultat = malloc(sizeof(char) * (len + 1));
	if (resultat == NULL)
		return (NULL);
	while (str[i] != '\0')
	{
		resultat[i] = str[i];
		i++;
	}
	resultat[i] = '\0';
	return (resultat);
}
/*
int	main(void)
{
	char	texte[] = "j'ai sommeil.";
	char    texte_vrai[] = "j'ai sommeil.";
	char	*copie;
	char	*copie_vrai;

	copie = ft_strdup(texte);
	copie_vrai = strdup(texte_vrai);
	printf("ft = %s\n", copie);
	printf("vrai = %s\n", copie_vrai);
	return (0);
}*/
