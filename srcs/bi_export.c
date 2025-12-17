#include "minishell.h"

int	ft_export_double(char *str, char ***env)
{
	int		j;
	int		taille;
	int		check;
	char	**env_ajoute;

	check = ft_check_env_double(str, (*env));
	j = 0;
	taille = 0;
	while ((*env)[taille] != NULL)
		taille++;
	env_ajoute = malloc(sizeof(char *) * (taille + 1));
	if (!env_ajoute)
		return (-1);
	while ((*env)[j] != NULL)
	{
		if (check == j)
			env_ajoute[j] = ft_strdup(str);
		else
			env_ajoute[j] = ft_strdup((*env)[j]);
		j++;
	}
	env_ajoute[j] = NULL;
	(*env) = env_ajoute;
	return (0);
}

int	ft_export_sans_double(char *str, char ***env)
{
	int		j;
	int		taille;
	int		check;
	char	**env_ajoute;

	check = ft_check_env_double(str, (*env));
	j = 0;
	taille = 0;
	while ((*env)[taille] != NULL)
		taille++;
	env_ajoute = malloc(sizeof(char *) * (taille + 1 + 1));
	if (!env_ajoute)
		return (-1);
	while ((*env)[j] != NULL)
	{
		env_ajoute[j] = ft_strdup((*env)[j]);
		j++;
	}
	env_ajoute[j] = ft_strdup(str);
	j++;
	env_ajoute[j] = NULL;
	(*env) = env_ajoute;
	return (0);
}

int	ft_export(char *str, char ***env)
{
	int		j;
	int		taille;
	int		check;
	char	**env_ajoute;

	j = 0;
	taille = 0;
	check = ft_check_env_double(str, (*env));
	if (check != 0)
	{
		ft_export_double(str, env);
		return (0);
	}
	ft_export_sans_double(str, env);
	return (0);
}

int	ft_export_all(char **tab, char ***env)
{
	int	j;

	j = 1;
	while (tab[j] != NULL)
	{
		ft_export(tab[j], env);
		j++;
	}
	return (0);
}
