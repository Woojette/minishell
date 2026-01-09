
#include "minishell.h"

// void	ft_pipe_pl(int ac, char **av)
// {

// }

int	main(int ac, char **av)
{
	(void)ac;
	(void)av;
	int		id;
	int		pipefd[2];
	int		id2;
	int		pipefd_2[2];
	char	buff[5000];
	int		n;

	if (pipe(pipefd) == -1)
		return (perror("pipe"), 1);
	id = fork();
	if (id == 0)
	{
		if (dup2(pipefd[1], 1) == -1)
			return (perror("dup2"), close(pipefd[0]), close(pipefd[1]), 1);
		printf("coucou\n");
		close(pipefd[1]);
	}
	close(pipefd[0]);
	if (pipe(pipefd_2) == -1)
		return (perror("pipe"), 1);
	id2 = fork();
	if (id2 == 0)
	{
		if (dup2(pipefd_2[0], 0) == -1)
			return (perror("dup2"), close(pipefd_2[0]), close(pipefd_2[1]), 1);
		n = read(0, buff, sizeof(buff));
		buff[n] = 0;
		printf("%s\n", buff);
		close(pipefd_2[1]);
	}
	close(pipefd_2[1]);
	return (0);
}
