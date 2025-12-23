#include "minishell.h"

char	**ft_copie_tab(char ***env)
{
	int		j;
	int		taille;
	char	**tab;

	taille = 0;
	while ((*env)[taille] != NULL)
		taille++;
	tab = malloc(sizeof(char *) * (taille + 1));
	if (!tab)
		return (NULL);
	j = 0;
	while ((*env)[j] != NULL)
	{
		tab[j] = ft_strdup((*env)[j]);
		if (!tab[j])
			return (ft_free_tab(tab), NULL);
		j++;
	}
	tab[j] = NULL;
	return (tab);
}

int	ft_init_mini(char **env, t_minis **mini)
{
	(*mini)->env = ft_copie_tab(&env);
	if ((*mini)->env == NULL)
		return (-1);
	return (0);
}