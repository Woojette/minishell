#include "minishell.h"

// Si on met -n, option_n = 1, sinon option_n = 0
void	ft_echo(char *str, int option_n)
{
	printf("%s", str);
	if (option_n == 0)
		printf("\n");
}

void	ft_env(char **env)
{
	int	j;

	j = 0;
	while (env[j] != NULL)
	{
		printf("%s\n", env[j]);
		j++;
	}
}

int	ft_compter_env(char **env)
{
	int	i;
	int	j;
	int	len;
	int	n;

	i = 0;
	j = 0;
	n = 1;
	while (env[j] != NULL)
	{
		len = ft_strlen(env[j]);
		i = i + len + n;
		j++;
	}
	return (i);
}

int	ft_check_env_egal(char *str)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '=')
			break;
		i++;
	}
	if (str[i] == '\0')
		return (-1);
	return (i);
}

int	ft_check_env_double(char *str, char **env)
{
	int	i;
	int	j;
	int	egal;

	i = 0;
	j = 0;
	egal = ft_check_env_egal(str);
	if (egal == -1)
		return (-1);
	while (env[j] != NULL)
	{
		if (ft_strncmp(str, env[j], egal + 1) == 0)
			return (printf("\n%s", env[j]), j);
		j++;
	}
	return (0);
}

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

int	ft_unset(char *str, char ***env)
{
	
}