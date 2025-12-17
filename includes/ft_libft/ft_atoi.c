/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wooyang <wooyang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 18:29:34 by wooyang           #+#    #+#             */
/*   Updated: 2025/05/14 16:13:15 by wooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_atoi(const char *str, int *error)
{
	int		i;
	int		signe;
	long	nb;

	i = 0;
	signe = 1;
	nb = 0;
	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			signe = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (signe == 1 && (nb > (INT_MAX - (str[i] - '0')) / 10))
			return (*error = 1, LONG_MAX);
		if (signe == -1 && (-nb < (INT_MIN + (str[i] - '0')) / 10))
			return (*error = 1, LONG_MIN);
		nb = (nb * 10) + (str[i] - '0');
		i++;
	}
	return (nb * signe);
}
/*
int	main(void)
{
        printf("moins sg = %d (ft)\n", ft_atoi("    -12"));
        printf("moins sg = %d (vrai)\n\n", atoi("    -12"));
        printf("moins sg alphabet = %d (ft)\n", ft_atoi("    -12a!12"));
        printf("moins sg alphabet = %d (vrai)\n\n", atoi("    -12a!12"));
        printf("moins pl pair = %d (ft)\n", ft_atoi("\t\t--24A11"));
        printf("moins pl pair = %d (vrai)\n\n", atoi("\t\t--24A11"));
        printf("plus sg = %d (ft)\n", ft_atoi("\r\r    +555"));
        printf("plus sg = %d (vrai)\n\n", atoi("\r\r    +555"));
        printf("plus sg alphabet = %d (ft)\n", ft_atoi("\f\f   +7!fdsa77   "));
        printf("plus sg alphabet = %d (vrai)\n\n", atoi("\f\f   +7!fdsa77   "));
        printf("plus pl impair = %d (ft)\n", ft_atoi("  +++33!@33"));
        printf("plus pl impair = %d (vrai)\n\n", atoi("  +++33!@33"));
        printf("alphabet = %d (ft)\n", ft_atoi("abc"));
        printf("alphabet = %d (vrai)\n\n", atoi("abc"));
	return (0);
}*/
