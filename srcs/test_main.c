#include "minishell.h"

// int	ft_echo_option_n(char *str)
// {
// 	int	i;

// 	if (!str)
// 		return (0);
// 	if (str[0] != '-')
// 		return (0);
// 	i = 1;
// 	while (str[i] != '\0')
// 	{
// 		if (str[i] == 'n')
// 			i++;
// 		else
// 			return (0);
// 	}
// 	return (1);
// }

// void	ft_echo_all(char **tab)
// {
// 	int	j;
// 	int	option_n;

// 	j = 1;
// 	option_n = 0;
// 	while (tab[j] != NULL && ft_echo_option_n(tab[j]) == 1)
// 		j++;
// 	if (j > 1)
// 		option_n = 1;
// 	while (tab[j] != NULL)
// 	{
// 		printf("%s", tab[j]);
// 		if (tab[j + 1] != NULL)
// 			printf(" ");
// 		j++;
// 	}
// 	if (option_n == 0)
// 		printf("\n");
// }

// void	ft_env(char **env)
// {
// 	int	j;

// 	j = 0;
// 	while (env[j] != NULL)
// 	{
// 		printf("%s\n", env[j]);
// 		j++;
// 	}
// }

// int	ft_compter_env(char **env)
// {
// 	int	i;
// 	int	j;
// 	int	len;
// 	int	n;

// 	i = 0;
// 	j = 0;
// 	n = 1;
// 	while (env[j] != NULL)
// 	{
// 		len = ft_strlen(env[j]);
// 		i = i + len + n;
// 		j++;
// 	}
// 	return (i);
// }

// int	ft_check_env_egal(char *str)
// {
// 	int		i;

// 	i = 0;
// 	while (str[i] != '\0')
// 	{
// 		if (str[i] == '=')
// 			break;
// 		i++;
// 	}
// 	if (str[i] == '\0')
// 		return (-1);
// 	return (i);
// }

// int	ft_check_env_double(char *str, char **env)
// {
// 	int	j;
// 	int	egal;

// 	j = 0;
// 	egal = ft_check_env_egal(str);
// 	if (egal == -1)
// 		return (-1);
// 	while (env[j] != NULL)
// 	{
// 		if (ft_strncmp(str, env[j], egal + 1) == 0)
// 			return (j);
// 		j++;
// 	}
// 	return (0);
// }

// int	ft_export_double(char *str, char ***env)
// {
// 	int		j;
// 	int		taille;
// 	int		check;
// 	char	**env_ajoute;

// 	check = ft_check_env_double(str, (*env));
// 	j = 0;
// 	taille = 0;
// 	while ((*env)[taille] != NULL)
// 		taille++;
// 	env_ajoute = malloc(sizeof(char *) * (taille + 1));
// 	if (!env_ajoute)
// 		return (-1);
// 	while ((*env)[j] != NULL)
// 	{
// 		if (check == j)
// 			env_ajoute[j] = ft_strdup(str);
// 		else
// 			env_ajoute[j] = ft_strdup((*env)[j]);
// 		j++;
// 	}
// 	env_ajoute[j] = NULL;
// 	ft_free_tab((*env));
// 	(*env) = env_ajoute;
// 	return (0);
// }

// int	ft_export_sans_double(char *str, char ***env)
// {
// 	int		j;
// 	int		taille;
// 	int		check;
// 	char	**env_ajoute;

// 	check = ft_check_env_double(str, (*env));
// 	j = 0;
// 	taille = 0;
// 	while ((*env)[taille] != NULL)
// 		taille++;
// 	env_ajoute = malloc(sizeof(char *) * (taille + 1 + 1));
// 	if (!env_ajoute)
// 		return (-1);
// 	while ((*env)[j] != NULL)
// 	{
// 		env_ajoute[j] = ft_strdup((*env)[j]);
// 		j++;
// 	}
// 	env_ajoute[j] = ft_strdup(str);
// 	j++;
// 	env_ajoute[j] = NULL;
// 	ft_free_tab((*env));
// 	(*env) = env_ajoute;
// 	return (0);
// }

// int	ft_export(char *str, char ***env)
// {
// 	int		j;
// 	int		taille;
// 	int		check;
// 	char	**env_ajoute;

// 	j = 0;
// 	taille = 0;
// 	check = ft_check_env_double(str, (*env));
// 	if (check != 0)
// 	{
// 		ft_export_double(str, env);
// 		return (0);
// 	}
// 	ft_export_sans_double(str, env);
// 	return (0);
// }

// int	ft_export_all(char **tab, char ***env)
// {
// 	int	j;

// 	j = 1;
// 	while (tab[j] != NULL)
// 	{
// 		ft_export(tab[j], env);
// 		j++;
// 	}
// 	return (0);
// }

// void	ft_unset_init_int_zero(int *j, int *supprime, int *taille)
// {
// 	*j = 0;
// 	*supprime = 0;
// 	*taille = 0;
// }

// int	ft_unset(char *str, char ***env)
// {
// 	int		j;
// 	int		supprime;
// 	int		taille;
// 	int		len_str;
// 	char	**env_supprime;

// 	ft_unset_init_int_zero(&j, &supprime, &taille);
// 	while ((*env)[taille] != NULL)
// 		taille++;
// 	len_str = ft_strlen(str);
// 	env_supprime = malloc(sizeof(char *) * (taille + 1));
// 	if (!env_supprime)
// 		return (-1);
// 	while ((*env)[j + supprime] != NULL)
// 	{
// 		if (((j + supprime) < taille) 
// 			&& ft_strncmp(str, (*env)[j + supprime], len_str) == 0
// 			&& (*env)[j + supprime][len_str] == '=')
// 			supprime++;
// 		if ((j + supprime) < taille)
// 			env_supprime[j] = ft_strdup((*env)[j + supprime]);
// 		j++; 
// 	}
// 	env_supprime[j] = NULL;
// 	return ((*env) = env_supprime, 0);
// }

// int	ft_unset_all(char **tab, char ***env)
// {
// 	int	j;

// 	j = 1;
// 	while (tab[j] != NULL)
// 	{
// 		ft_unset(tab[j], env);
// 		j++;
// 	}
// 	return (0);
// }

// int	ft_pwd(void)
// {
// 	char	buf[1024];
// 	size_t		size;

// 	size = sizeof(buf);
// 	if (getcwd(buf, size) != NULL)
// 	{
// 		printf("%s\n", buf);
// 		return (0);
// 	}
// 	else
// 	{
// 		printf("pwd: error retrieving current directory: ");
// 		printf("getcwd: cannot access parent directories: No such file or directory");
// 		printf("\n");
// 	}
// 	return (-1);
// }

// char *ft_cd_val_env(char *str, char ***env)
// {
//   int   j;
//   char	*str_path;

//   j = 0;
//   while ((*env)[j] != NULL)
//   {
//     if (ft_strncmp((*env)[j], str, ft_strlen(str)) == 0)
// 	{
// 		str_path = ft_strdup((*env)[j] + ft_strlen(str));
// 		if (!str_path)
// 			return (NULL);
// 		return (str_path);
// 	}
//     j++;
//   }
//   return (NULL);
// }

// int	ft_cd_sans_av(char **val, char **path, char *str, char ***env)
// {
// 	char	*new_oldpwd;
// 	char	*new_pwd;

//     (*val) = ft_cd_val_env(str, env);
// 	if (!(*val))
// 	{
// 		if (ft_strncmp(str, "HOME=", 5) == 0)
// 			printf("minishell: cd: HOME not set\n");
// 		else if (ft_strncmp(str, "OLDPWD=", 7) == 0)
// 			printf("minishell: cd: OLDPWD not set\n");
// 		return (-1);
// 	}
//     (*path) = (*val);
// 	new_oldpwd = getcwd(NULL, 0);
// 	if (chdir((*path)) == -1)
// 	{
// 		perror ("chdir");
// 		return (-1);
// 	}
// 	new_pwd = getcwd(NULL, 0);
// 	ft_cd_env_update(&new_oldpwd, &new_pwd, env);
// 	return (0);
// }

// int	ft_cd_tiret(char **oldpwd, char **path, char ***env)
// {
// 	char	*new_oldpwd;
// 	char	*new_pwd;

// 	(*oldpwd) = ft_cd_val_env("OLDPWD=", env);
// 	if ((*oldpwd) == NULL)
//     {
//       printf("minishell: cd: OLDPWD not set\n");
//       return (-1);
//     }
// 	(*path) = (*oldpwd);
// 	new_oldpwd = getcwd(NULL, 0);
// 	if (chdir((*path)) == -1)
// 	{
// 		printf("cd: %s", (*path));
// 		printf(": No such file or directory\n");
// 		return (-1);
// 	}
// 	new_pwd = getcwd(NULL, 0);
// 	ft_cd_env_update(&new_oldpwd, &new_pwd, env);
// 	printf("%s\n", (*path));
// 	return (0);
// }

// int	ft_cd_env_update(char **oldpwd, char **pwd, char ***env)
// {
// 	int		j;
// 	char	*temp;

// 	j = 0;
// 	while ((*env)[j] != NULL)
// 	{
// 		if (ft_strncmp((*env)[j], "OLDPWD=", 7) == 0)
// 		{
// 			temp = ft_strjoin("OLDPWD=", (*oldpwd));
// 			if (!temp)
// 				return (-1);
// 			(*env)[j] = temp;
// 		}
// 		else if (ft_strncmp((*env)[j], "PWD=", 4) == 0)
// 		{
// 			temp = ft_strjoin("PWD=", (*pwd));
// 			if (!temp)
// 				return (-1);
// 			(*env)[j] = temp;
// 		}
// 		j++;
// 	}
// 	return (0);
// }

// int	ft_cd_all(char **tab, char ***env)
// {
// 	char	*oldpwd;
// 	char	*pwd;
// 	char	*home;
// 	char	*path;

// 	if ((tab[1] != NULL) && (tab[2] != NULL))
// 	{
// 		printf("cd: too many arguments\n");
// 		return (-1);
// 	}
// 	if (tab[1] == NULL || (tab[1][0] == '~' && tab[1][1] == '\0'))
// 	{
// 		if (ft_cd_sans_av(&home, &path, "HOME=", env) == -1)
// 			return (-1);
// 		return (0);
// 	}
// 	if (tab[2] == NULL)
// 	{
// 		if (tab[1][0] == '-' && tab[1][1] == '\0')
// 		{
// 			if (ft_cd_tiret(&oldpwd, &path, env) == -1)
// 				return (-1);
// 			return (0);
// 		}
// 		oldpwd = getcwd(NULL, 0);
// 		if (!oldpwd)
// 			return (perror("mininshell: cd"), -1);
// 		if (chdir(tab[1]) == -1)
// 			return (perror ("chdir"), -1);
// 		pwd = getcwd(NULL, 0);
// 		if (!pwd)
// 			return (perror("minishell: cd"), -1);
// 		ft_cd_env_update(&oldpwd, &pwd, env);
// 		return (0);
// 	}
// 	return (0);
// }

// int	ft_exit_check_not_int(char *str)
// {
// 	int	i;

// 	i = 0;
// 	if ((str[0] == '+') || (str[0] == '-'))
// 		i++;
// 	while (str[i] != '\0')
// 	{
// 		if (ft_isdigit(str[i]) == 1)
// 			return (1);
// 		i++;
// 	}
// 	return (0);
// }

// long long	ft_exit_atoi_long(const char *str, int *error)
// {
// 	int			i;
// 	int			signe;
// 	long long	nb;

// 	i = 0;
// 	signe = 1;
// 	nb = 0;
// 	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
// 		i++;
// 	if (str[i] == '-' || str[i] == '+')
// 	{
// 		if (str[i] == '-')
// 			signe = -1;
// 		i++;
// 	}
// 	while (str[i] >= '0' && str[i] <= '9')
// 	{
// 		if (signe == 1 && (nb > (LLONG_MAX - (str[i] - '0')) / 10))
// 			return (*error = 1, LLONG_MAX);
// 		if (signe == -1 && (-nb < (LLONG_MIN + (str[i] - '0')) / 10))
// 			return (*error = 1, LLONG_MIN);
// 		nb = (nb * 10) + (str[i] - '0');
// 		i++;
// 	}
// 	return (nb * signe);
// }

// void	ft_exit_sans_arg(int *exit_temp, t_minis *mini)
// {
// 	(*exit_temp) = mini->exit_status % 256;
// 	free(mini);
// 	printf("exit\n");
// 	exit ((*exit_temp));
// }

// void	ft_exit_normal_arg(char *str, t_minis **mini)
// {
// 	long long	val;
// 	int			error;

// 	error = 0;
// 	val = ft_exit_atoi_long(str, &error);
// 	val = val % 256;
// 	free((*mini));
// 	printf("exit\n");
// 	exit (val);
// }

// void	ft_exit_pl_arg(int *exit_temp, t_minis **mini)
// {
// 	(*mini)->exit_status = 1;
// 	*exit_temp = (*mini)->exit_status;
// 	free((*mini));
// 	printf("exit\n");
// 	printf("minishell: exit: too many arguments\n");
// }

// void	ft_exit_wrong_arg(int *exit_temp, char *str, t_minis **mini)
// {
// 	(*mini)->exit_status = 2;
// 	*exit_temp = (*mini)->exit_status;
// 	free(*mini);
// 	printf("exit\n");
// 	printf("minishell: exit: %s: numeric argument required\n", str);
// 	exit (*exit_temp);
// }

// int	ft_exit(char **tab, t_minis **mini)
// {
// 	int			error;
// 	long long	temp;
// 	int			exit_temp;

// 	error = 0;
// 	if (tab[1] == NULL)
// 		ft_exit_sans_arg(&exit_temp, (*mini));
// 	else if ((tab[1] != NULL) && (tab[2] != NULL))
// 	{
// 		ft_exit_pl_arg(&exit_temp, mini);
// 		return (exit_temp);
// 	}
// 	else if ((tab[1] != NULL) && (tab[2] == NULL))
// 	{
// 		if (ft_exit_check_not_int(tab[1]) == 1)
// 			ft_exit_wrong_arg(&exit_temp, tab[1], mini);
// 		temp = ft_exit_atoi_long(tab[1], &error);
// 		if (error == 1)// long long++
// 			ft_exit_wrong_arg(&exit_temp, tab[1], mini);
// 		ft_exit_normal_arg(tab[1], mini);
// 	}
// 	return (0);
// }

int	main(int ac, char **av, char **env) 
{
	t_minis	*mini;

	mini = malloc(sizeof(t_minis)); 
	if (!mini)
		return (-1);
	// &mini
	(void)ac;
	(void)av;
	// (void)env;

	ft_init_mini(env, &mini);

	// //Test echo
	// printf("#####Test echo#####\n");
	// char	*tab[8];
	// tab[0] = "echo";
	// tab[1] = "-nnn";
	// tab[2] = "-n";
	// tab[3] = "-nnann";
	// tab[4] = "coucou";
	// tab[5] = "-n";
	// tab[6] = "hihi";
	// tab[7] = NULL;
	// ft_echo_all(tab);
	// // ft_echo(av[1], 0);
	// // ft_echo(av[1], 1);
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
	// ft_export_all(tab, &(mini->env));

	// char	*tab_export_2[5];
	// tab_export_2[0] = "export";
	// tab_export_2[1] = "coucou=youpi";
	// tab_export_2[2] = "coucou123=bonjour123";
	// tab_export_2[3] = "coucou=faim";
	// tab_export_2[4] = NULL;
	// ft_export_all(tab_export_2, &env);
	// ft_export(tab[1], &env);
	// ft_export(tab[2], &env);
	// ft_export(tab[3], &env);
	// ft_env(mini->env);
	// printf("#####Fin de test export#####");
	// printf("\n%d", ft_check_env_double("coucou=salut", env));
	// printf("\n%d", ft_check_env_double("coucou1=salut", env));
	// printf("\n%d", ft_check_env_double("coucou123=salut", env));
	// printf("\n%d", ft_check_env_double("coucou", env));

	// ft_export("new=salut", &env);

	// // Test unset
	// printf("\n########unset#######\n");
	// // ft_env(env);
	// char	*tab2[5];
	// tab2[0] = "unset";
	// tab2[1] = "coucou";
	// tab2[2] = "coucou123";
	// tab2[3] = "coucou";
	// tab2[4] = NULL;
	// // ft_unset(tab2[1], &env);
	// // ft_unset(tab2[2], &env);
	// ft_unset_all(tab2, &(mini->env));

	// ft_env(mini->env);

	// ft_export("new123=salut", &env);
	// ft_unset("new123", &env);
	// ft_unset("_", &env);
	// // ft_env(env);
	// printf("\n%d", ft_check_env_double("MAIL", env));
	// ft_env(env);

	// // Test pwd
	// ft_pwd();
	// chdir("/home/wooyang/42cursus/minishell/srcs/dossier");
	// rmdir("../dossier");
	// ft_pwd();	

	// Test cd
	// printf("#####Test cd#####\n");
	// // av 2+
	// char	*tab3[5];
	// tab3[0] = "cd";
	// tab3[1] = "hihi";
	// tab3[2] = "faim";
	// tab3[3] = "pho";
	// tab3[4] = NULL;
	// ft_cd_all(tab3, &env);

	// printf("########################################################################\n");
	// printf("avant: ");
	// ft_pwd();
	// ft_env(mini->env);

	// cd -
	char *tab4[3];
	tab4[0] = "cd";
	tab4[1] ="dossiertest";
	tab4[2] = NULL;
	// tab4[3] = NULL;
	printf("\n\n\n############# cd effectue ################\n");
	ft_cd_all(tab4, &(mini->env));
	printf("\n\n\n########################################################################\n\n");
	printf("apres: ");
	ft_pwd();
	ft_env(mini->env);

	// //Test exit
	// mini->exit_status = 412;
	// char *tab5[2];
	// tab5[0] = "exit";
	// // tab5[1] ="asd";
	// // tab5[2] ="2000";
	// tab5[1] = NULL;
	// ft_exit(tab5, &mini);
	// printf("Test exit status:%d\n", mini->exit_status);
	// // free(mini);
	ft_free_all(&mini);
	// free(mini);
	return (0);
}

//export coucou=youpi salut=bonjour123
// ft_export(char **tab);
// tab[0] = "export";
// tab[1] = "coucou=youpi";
// tab[2] = "salut=bonjour123";


