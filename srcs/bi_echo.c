#include "minishell.h"

// Si on met -n, option_n = 1, sinon option_n = 0
void	ft_echo(char *str, int option_n)
{
	printf("%s", str);
	if (option_n == 0)
		printf("\n");
}
