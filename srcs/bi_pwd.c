#include "minishell.h"

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
	else
		perror("getcwd");
	return (-1);
}
