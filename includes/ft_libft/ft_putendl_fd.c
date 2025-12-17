/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wooyang <wooyang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 16:26:46 by wooyang           #+#    #+#             */
/*   Updated: 2025/05/14 16:19:18 by wooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		write(fd, &s[i], 1);
		i++;
	}
	write(fd, "\n", 1);
}
/*
int	main(void)
{
	char	texte1[] = "coucou";
	char	texte2[] = "il fati beau aujourd'hui";
	char	texte3[] = "youpii";
	char	texte4[] = "hihi";
	ft_putendl_fd(texte1, 1);
	ft_putendl_fd(texte2, 2);
	ft_putendl_fd(texte3, 3);
	ft_putendl_fd(texte4, 0);
	return (0);
}*/
