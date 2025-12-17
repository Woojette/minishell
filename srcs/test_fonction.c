#include "test.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

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

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	int		resultat;

	i = 0;
	resultat = 0;
	while ((s1[i] != '\0' || s2[i] != '\0') && i < n)
	{
		if (s1[i] != s2[i])
		{
			resultat = (unsigned char)s1[i] - (unsigned char)s2[i];
			return (resultat);
		}
		i++;
	}
	return (0);
}
