/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wooyang <wooyang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 15:51:01 by wooyang           #+#    #+#             */
/*   Updated: 2025/05/14 16:14:52 by wooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t			i;
	unsigned char	*resultat;

	i = 0;
	if (size != 0 && (nmemb) > ULLONG_MAX / size)
		return (NULL);
	resultat = malloc(nmemb * size);
	if (resultat == NULL)
		return (NULL);
	while (i < nmemb * size)
	{
		resultat[i] = 0;
		i++;
	}
	return (resultat);
}
/*
int	main(void)
{
	size_t	nb = 5;
	int	*src_ft = ft_calloc(nb, sizeof(int));
	int	*src_vrai = calloc(nb, sizeof(int));
	
//	char	*src_ft = ft_calloc(nb , sizeof(char));
//	char 	*src_vrai = calloc(nb, sizeof(char));

	size_t	i = 0;
	size_t	j = 0;

	printf("%zu\n", (size_t)-1);
	printf("ft_calloc : ");
	while (i < nb)
	{
		printf("%d | ", src_ft[i]);
		i++;
	}
	printf("\nvrai calloc : ");
	while (j < nb)
	{
		printf("%d | ", src_vrai[j]);
		j++;
	}
	return (0);
}*/
