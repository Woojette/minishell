#include "minishell.h"

int	ft_exit_check_not_int(char *str)
{
	int	i;

	i = 0;
	if ((str[0] == '+') || (str[0] == '-'))
		i++;
	while (str[i] != '\0')
	{
		if (ft_isdigit(str[i]) == 1)
			return (1);
		i++;
	}
	return (0);
}

long long	ft_exit_atoi_long(const char *str, int *error)
{
	int			i;
	int			signe;
	long long	nb;

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
		if (signe == 1 && (nb > (LLONG_MAX - (str[i] - '0')) / 10))
			return (*error = 1, LLONG_MAX);
		if (signe == -1 && (-nb < (LLONG_MIN + (str[i] - '0')) / 10))
			return (*error = 1, LLONG_MIN);
		nb = (nb * 10) + (str[i] - '0');
		i++;
	}
	return (nb * signe);
}

void	ft_exit_sans_arg(int *exit_temp, t_minis *mini)
{
	(*exit_temp) = mini->exit_status % 256;
	free(mini);
	printf("exit\n");
	exit ((*exit_temp));
}

void	ft_exit_normal_arg(char *str, t_minis **mini)
{
	long long	val;
	int			error;

	error = 0;
	val = ft_exit_atoi_long(str, &error);
	val = val % 256;
	free((*mini));
	printf("exit\n");
	exit (val);
}

void	ft_exit_pl_arg(int *exit_temp, t_minis **mini)
{
	(*mini)->exit_status = 1;
	*exit_temp = (*mini)->exit_status;
	free((*mini));
	printf("exit\n");
	printf("minishell: exit: too many arguments\n");
}

void	ft_exit_wrong_arg(int *exit_temp, char *str, t_minis **mini)
{
	(*mini)->exit_status = 2;
	*exit_temp = (*mini)->exit_status;
	free(*mini);
	printf("exit\n");
	printf("minishell: exit: %s: numeric argument required\n", str);
	exit (*exit_temp);
}

int	ft_exit(char **tab, t_minis **mini)
{
	int			error;
	long long	temp;
	int			exit_temp;

	error = 0;
	if (tab[1] == NULL)
		ft_exit_sans_arg(&exit_temp, (*mini));
	else if ((tab[1] != NULL) && (tab[2] != NULL))
	{
		ft_exit_pl_arg(&exit_temp, mini);
		return (exit_temp);
	}
	else if ((tab[1] != NULL) && (tab[2] == NULL))
	{
		if (ft_exit_check_not_int(tab[1]) == 1)
			ft_exit_wrong_arg(&exit_temp, tab[1], mini);
		temp = ft_exit_atoi_long(tab[1], &error);
		if (error == 1)// long long++
			ft_exit_wrong_arg(&exit_temp, tab[1], mini);
		ft_exit_normal_arg(tab[1], mini);
	}
	return (0);
}
