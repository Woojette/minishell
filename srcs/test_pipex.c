
#include "minishell.h"

// void	ft_pipe_pl(int ac, char **av)
// {

// }

int	main(int ac, char **av)
{
	(void)ac;
	(void)av;
	int		status;
	int		id;
	int		pipefd[2];
	int		id2;
	int		id3;
	int		pipefd_2[2];
	char	buff[5000];
	int		n;

	status = 0;
	if (pipe(pipefd) == -1)
		return (perror("pipe"), 1);
	id = fork();
	if (id == 0)
	{
		if (dup2(pipefd[1], 1) == -1)
			return (perror("dup2 1"), close(pipefd[0]), close(pipefd[1]), 1);

		printf("bonjour");
		close(pipefd[1]);
		pipefd[1] = -1;
		// close(pipefd[0]);
		// pipefd[0] = -1;
		exit (0);
	}
	// waitpid(id, &status, 0);
	if (pipe(pipefd_2) == -1)
		return (perror("pipe"), 1);
	id2 = fork();
	if (id2 == 0)
	{
		if (dup2(pipefd[0], 0) == -1)
			return (perror("dup2 2"), close(pipefd[0]), close(pipefd[1]), 1);
		if (dup2(pipefd_2[1], 1) == -1)
			return (perror("dup2 3"), close(pipefd_2[0]), close(pipefd_2[1]), 1);

		n = read(0, buff, sizeof(buff));
		buff[n] = 0;
		printf("%s coucou", buff);


		close(pipefd_2[1]);
		// close(pipefd_2[0]);
		close(pipefd[1]);
		close(pipefd[0]);
		exit (0);
	}
	//  waitpid(id2, &status, 0);
	id3 = fork();
	if (id3 == 0)
	{
		if (dup2(pipefd_2[0], 0) == -1)
			return (perror("dup2 4"), close(pipefd_2[0]), close(pipefd_2[1]), 1);
			
		n = read(0, buff, sizeof(buff));
		buff[n] = 0;
		printf("%s hello\n", buff);
		close(pipefd_2[1]);
		close(pipefd_2[0]);
		close(pipefd[1]);
		close(pipefd[0]);
		exit (0);
	}
	close(pipefd_2[0]);
	close(pipefd_2[1]);
	close(pipefd[0]);
	close(pipefd[1]);
	waitpid(id, &status, 0);
	waitpid(id2, &status, 0);
	waitpid(id3, &status, 0);
	return (0);
}
