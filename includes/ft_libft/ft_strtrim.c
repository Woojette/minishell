/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wooyang <wooyang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 17:09:45 by wooyang           #+#    #+#             */
/*   Updated: 2025/05/12 17:38:15 by wooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isinset(char c, const char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

// size_t	ft_debut(const char *s1, const char *set)
// {
// 	size_t	i;
// 	size_t	j;

// 	i = 0;
// 	j = 0;
// 	if (s1[0] == '\0')
// 		return 0;
// 	while (s1 != NULL && s1[i] != '\0')
// 	{
// 		while (set[j] != '\0' && s1[i] != set[j])
// 			j++;
// 		if (set[j] == '\0')
// 			return (i);
// 		j = 0;
// 		i++;
// 	}
// 	if (i == ft_strlen(s1))
// 		return (1);
// 	return (i);
// }

static int	ft_debut(char const *s1, char const *set)
{
	int	i;

	i = 0;
	while (s1[i] && ft_isinset(s1[i], set) == 1)
		i++;
	return (i);
}

// size_t		ft_fin(const char *s1, const  char *set)
// {
// 	size_t	i;
// 	size_t	j;

// 	i = 0;
// 	if (s1[0] == '\0')
// 		return 0;
// 	j = ft_strlen(s1) - 1;

// 	while (j > 0)
// 	{
// 		while (set[i] != '\0' && s1[j] != set[i])
// 			i++;
// 		if (set[i] == '\0')
// 			return (j);
// 		i = 0;
// 		j--;
// 	}
// 	return (j);
// }

static int	ft_fin(char const *s1, char const *set)
{
	int	len;

	len = 0;
	while (s1[len])
		len++;
	len--;
	while (len >= 0 && ft_isinset(s1[len], set) == 1)
		len--;
	return (len);
}

// char	*ft_strtrim(const char *s1, const char *set)
// {
// 	size_t	k;
// 	size_t	d;
// 	size_t	f;
// 	size_t	len;
// 	char	*resultat;

// 	k = 0;
// 	len = ft_strlen(s1);
// 	d = ft_debut(s1, set);
// 	// printf("d:%zu\n", d);
// 	f = ft_fin(s1, set);
// 	// printf("f:%zu\n", f);
// 	// if (d == f && f == len)
// 	if (d > f)
// 		return (ft_strdup(""));
// 	resultat = malloc(sizeof(char) * (f - d  + 2));
// 	if (resultat == NULL)
// 		return (NULL);
// 	while (d <= f)
// 	{
// 		resultat[k] = s1[d];
// 		k++;
// 		d++;
// 	}
// 	resultat[k] = '\0';
// 	return (resultat);
// }

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*res;
	int		start;
	int		end;
	int		i;

	i = 0;
	if (!s1 || !set)
		return (NULL);
	start = ft_debut(s1, set);
	end = ft_fin(s1, set);
	if (start > end)
		return (ft_strdup(""));
	res = malloc(sizeof(char) * (end - start + 2));
	if (!res)
		return (NULL);
	while (start <= end)
		res[i++] = s1[start++];
	res[i] = '\0';
	return (res);
}

// int	main(void)
// {
// 	char	texte[] = "123";
// 	char	set[] = "";
// 	char	*resultat = ft_strtrim(texte, set);
// 	printf("avant : %s\n", texte);
// 	printf("apres : %s\n", resultat);
// 	free(resultat);
// 	return (0);
// }
