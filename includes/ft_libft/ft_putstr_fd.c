/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wooyang <wooyang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 16:20:04 by wooyang           #+#    #+#             */
/*   Updated: 2025/05/14 16:18:40 by wooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		write(fd, &s[i], 1);
		i++;
	}
}
/*
int	main(void)
{
	char	texte1[] = "il fait beau.";
	char	texte2[] = "\nhihi";
	char	texte3[] = "\nj'ai sommeil.";
	char	texte4[] = "\nj'ai envie d'un cafe.";
	ft_putstr_fd(texte1, 1);
	ft_putstr_fd(texte2, 2);
	ft_putstr_fd(texte3, 3);
	ft_putstr_fd(texte4, 0);
	return (0);
}*/
