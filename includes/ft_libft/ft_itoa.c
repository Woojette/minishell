/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wooyang <wooyang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 13:44:00 by wooyang           #+#    #+#             */
/*   Updated: 2025/05/22 14:35:56 by wooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_compter_itoa(int n)
{
	int	signe;
	int	len;

	signe = 0;
	len = 1;
	if (n == -2147483648)
		return (11);
	if (n < 0)
	{
		signe = 1;
		n = n * (-1);
	}
	while (n > 9)
	{
		n = n / 10;
		len++;
	}
	len = len + signe;
	return (len);
}

char	*ft_itoa(int n)
{
	int		i;
	int		len;
	int		temp;
	char	*resultat;

	i = 0;
	len = ft_compter_itoa(n);
	resultat = malloc(sizeof(char) * (len + 1));
	if (resultat == NULL)
		return (NULL);
	while (i < len)
	{
		temp = n % 10;
		if (temp < 0)
			temp = temp * -1;
		resultat[len - i -1] = temp + '0';
		n = n / 10;
		i++;
	}
	if (resultat[0] == '0' && len >= 2)
		resultat[0] = '-';
	resultat[len] = '\0';
	return (resultat);
}

// int	main(void)
// {
// 	char	*np = ft_itoa(-9);

// 	printf("2411 = %s\n", np);

// 	free(np);

// 	return (0);
// }
