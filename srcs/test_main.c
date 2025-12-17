#include "test.h"

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
			return (j);
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
	// char	**env_ajoute;

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

void	ft_unset_init_int_zero(int *j, int *supprime, int *taille)
{
	*j = 0;
	*supprime = 0;
	*taille = 0;
}

int	ft_unset(char *str, char ***env)
{
	int		j;
	int		supprime;
	int		taille;
	int		len_str;
	char	**env_supprime;

	ft_unset_init_int_zero(&j, &supprime, &taille);
	while ((*env)[taille] != NULL)
		taille++;
	len_str = ft_strlen(str);
	env_supprime = malloc(sizeof(char *) * (taille + 1));
	if (!env_supprime)
		return (-1);
	while ((*env)[j + supprime] != NULL)
	{
		if (((j + supprime) < taille) 
			&& ft_strncmp(str, (*env)[j + supprime], len_str) == 0
			&& (*env)[j + supprime][len_str] == '=')
			supprime++;
		if ((j + supprime) < taille)
			env_supprime[j] = ft_strdup((*env)[j + supprime]);
		j++; 
	}
	env_supprime[j] = NULL;
	// (*env) = env_supprime;
	return ((*env) = env_supprime, 0);
}

int	ft_unset_all(char **tab, char ***env)
{
	int	j;

	j = 1;
	while (tab[j] != NULL)
	{
		ft_unset(tab[j], env);
		j++;
	}
	return (0);
}

int	ft_pwd(void)
{
	char	buf[1024];
	size_t		size;

	size = sizeof(buf);
	if (getcwd(buf, size) != NULL)
	{
		printf("%s\n", buf);
		return (0);
	}
	return (-1);
}

int	main(int ac, char **av, char **env) 
{

	(void)ac;
	(void)av;
	(void)env;
	// //Test echo
	// printf("#####Test echo#####\n");
	// ft_echo(av[1], 0);
	// ft_echo(av[1], 1);
	// printf("#####Fin de test echo#####");

	// // Test env
	// printf("#####Test env#####\n");
	// ft_env(env);
	// printf("#####Fin de test env#####");

	// // Test export
	// printf("#####Test export#####\n");
	// char	*tab[5];
	// tab[0] = "export";
	// tab[1] = "coucou=youpi";
	// tab[2] = "coucou123=bonjour123";
	// tab[3] = "coucou=faim";
	// tab[4] = NULL;
	// ft_export_all(tab, &env);
	// // ft_export(tab[1], &env);
	// // ft_export(tab[2], &env);
	// // ft_export(tab[3], &env);
	// ft_env(env);
	// printf("#####Fin de test export#####");
	// printf("\n%d", ft_check_env_double("coucou=salut", env));
	// printf("\n%d", ft_check_env_double("coucou1=salut", env));
	// printf("\n%d", ft_check_env_double("coucou123=salut", env));
	// printf("\n%d", ft_check_env_double("coucou", env));

	// ft_export("new=salut", &env);

	// Test unset
	printf("\n########unset#######\n");
	// ft_env(env);
	char	*tab2[5];
	tab2[0] = "unset";
	tab2[1] = "coucou";
	tab2[2] = "coucou123";
	tab2[3] = "coucou";
	tab2[4] = NULL;
	// ft_unset(tab2[1], &env);
	// ft_unset(tab2[2], &env);
	ft_unset_all(tab2, &env);

	ft_env(env);

	ft_export("new123=salut", &env);
	ft_unset("new123", &env);
	ft_unset("_", &env);
	// ft_env(env);
	printf("\n%d", ft_check_env_double("MAIL", env));
	ft_env(env);

	// Test pwd
	// ft_pwd();

	// // Test cd
	// printf("#####Test cd#####");
	return (0);
}

//export coucou=youpi salut=bonjour123
// ft_export(char **tab);
// tab[0] = "export";
// tab[1] = "coucou=youpi";
// tab[2] = "salut=bonjour123";