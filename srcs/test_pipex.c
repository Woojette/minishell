
#include "test_minishell.h"

void	ft_redirection(t_minis *mini, int *pipefd_in, int *pipefd_out, int pos)
{
	if (pos == 0)
		dup2(pipefd_in[1], 1);
	else if (pos == (mini->nbr_commande - 1))
		dup2(pipefd_out[0], 0);
	else
	{
		dup2(pipefd_in[0], 0);
		dup2(pipefd_out[1], 1);
	}
}

void	ft_pipe_ouvrir(t_minis *mini)
{
	int	i;

	i = 0;
	while (i < mini->nbr_commande)
	{
		if (pipe(mini->t_commande[i].pipefd) == -1)
			return ;
		i++;
	}
}

void	ft_pipe_fermer(t_minis *mini)
{
	int	pos = 0;
	while (pos < mini->nbr_commande)
	{
		close(mini->t_commande[pos].pipefd[0]);
		close(mini->t_commande[pos].pipefd[1]);
		pos++;
	}
}

void	boucle(t_minis *mini)
{
	int	pos;
	int	status;

	pos = 0;
	status = 0;
	ft_pipe_ouvrir(mini);	
	while (pos < mini->nbr_commande)
	{	
		mini->t_commande[pos].id = fork();
		if (mini->t_commande[pos].id == 0)
		{
			ft_redirection(mini, mini->t_commande[pos+1].pipefd, mini->t_commande[pos].pipefd, pos);
			// if (pos == 0)
			// {
				// close(mini->t_commande[pos+1].pipefd[1]);
				// close(mini->t_commande[pos].pipefd[0]);
				ft_pipe_fermer(mini);
				execve(mini->t_commande[pos].cmd[0], mini->t_commande[pos].cmd, 0);
				exit (0);
			// }
		}
		// ft_pipe_fermer(mini);
		pos++;
	}
	ft_pipe_fermer(mini);
	waitpid(mini->t_commande[0].id, &status, 0);
	waitpid(mini->t_commande[1].id, &status, 0);
	waitpid(mini->t_commande[2].id, &status, 0);
}




// {
// 	if (pipe(pipefd) == -1)
// 		return (perror("pipe"), 1);
// 	id = fork();
// 	if (id == 0)
// 	{
// 		ft_redirection(mini, pipefd, pipefd_2, 0);

// 		close(pipefd[1]);
// 		close(pipefd[0]);

// 		execve(mini->t_commande[0].cmd[0], mini->t_commande[0].cmd, 0);

// 		exit (0);
// 	}
// 	if (pipe(pipefd_2) == -1)
// 		return (perror("pipe"), 1);
// 	id2 = fork();
// 	if (id2 == 0)
// 	{
// 		ft_redirection(mini, pipefd, pipefd_2, 1);

// 		close(pipefd_2[1]);
// 		close(pipefd[1]);

// 		execve(mini->t_commande[1].cmd[0], mini->t_commande[1].cmd, env);

// 		exit (0);
// 	}
// 	id3 = fork();
// 	if (id3 == 0)
// 	{
// 		ft_redirection(mini, pipefd, pipefd_2, 2);

// 		close(pipefd_2[1]);
// 		close(pipefd_2[0]);
// 		close(pipefd[1]);
// 		close(pipefd[0]);

// 		execve(mini->t_commande[2].cmd[0], mini->t_commande[2].cmd, env);

// 		exit (0);
// 	}
// 	close(pipefd_2[0]);
// 	close(pipefd_2[1]);
// 	close(pipefd[0]);
// 	close(pipefd[1]);
// 	waitpid(id, &status, 0);
// 	waitpid(id2, &status, 0);
// 	waitpid(id3, &status, 0);
// }



int	main(int ac, char **av, char **env)
{
	(void)ac;
	(void)av;
	int		status;
	// int		id;
	// int		pipefd[2];
	// int		id2 = 0;
	// int		id3 = 0;
	// (void)id3;
	// int		pipefd_2[2];
	char	buff[5000];
	int		n;
	t_minis	*mini;
	(void)buff;
	(void)n;
	(void)env;

	mini = malloc(sizeof(t_minis));
	if (!mini)
		return (1);
	mini->t_commande = malloc(sizeof(t_cmd) * 3);
	if (!mini->t_commande)
		return (1);
	
	mini->t_commande[0].cmd[0]="/bin/echo";
	mini->t_commande[0].cmd[1]="BONJOUR";
	mini->t_commande[0].cmd[2]=NULL; 

	mini->t_commande[1].cmd[0]="/bin/cat";
	mini->t_commande[1].cmd[1]="-e";
	mini->t_commande[1].cmd[2]=NULL; 

	mini->t_commande[2].cmd[0]="/bin/echo";
	mini->t_commande[2].cmd[1]="salut";
	mini->t_commande[2].cmd[2]=NULL; 

	mini->nbr_commande = 3;
	// char *arg[3];
	// arg[0] = "/bin/echo";
	// arg[1] = "asd";
	// arg[2] = NULL;

	// execve(arg[0], arg, 0);
	status = 0;

	// if (pipe(pipefd) == -1)
	// 	return (perror("pipe"), 1);
	// id = fork();
	// if (id == 0)
	// {
	// 	// if (dup2(pipefd[1], 1) == -1)
	// 	// 	return (perror("dup2 1"), close(pipefd[0]), close(pipefd[1]), 1);
	// 	ft_redirection(mini, pipefd, pipefd_2, 0);
	// 	// printf("bonjour");
	// 	close(pipefd[1]);
	// 	// mini->path = get_path(env);
	// 	// mini->pathd = ft_split(mini->path, ':');
	// 	// if (!mini->pathd)
	// 	// 	return (free(mini), 1);

	// 	close(pipefd[0]);
	// 	// printf("salut");

	// 	execve(mini->t_commande[0].cmd[0], mini->t_commande[0].cmd, 0);
	// 	// execve(arg[0], arg, 0);
	// 	// pipefd[1] = -1;
		
	// 	// pipefd[0] = -1;
	// 	exit (0);
	// }
	// // waitpid(id, &status, 0);

	// if (pipe(pipefd_2) == -1)
	// 	return (perror("pipe"), 1);
	// id2 = fork();
	// if (id2 == 0)
	// {
	// 	ft_redirection(mini, pipefd, pipefd_2, 1);
	// 	// if (dup2(pipefd[0], 0) == -1)
	// 	// 	return (perror("dup2 2"), close(pipefd[0]), close(pipefd[1]), 1);
	// 	// if (dup2(pipefd_2[1], 1) == -1)
	// 	// 	return (perror("dup2 3"), close(pipefd_2[0]), close(pipefd_2[1]), 1);

	// 	// n = read(0, buff, 2);
	// 	// buff[n] = 0;
	// 	// printf("%s coucou", buff);
	
	// 	close(pipefd_2[1]);
	// 	// close(pipefd_2[0]);
	// 	close(pipefd[1]);
	// 	// close(pipefd[0]);

	// 	execve(mini->t_commande[1].cmd[0], mini->t_commande[1].cmd, env);
	// 	exit (0);
	// }
	// //  waitpid(id2, &status, 0);
	// id3 = fork();
	// if (id3 == 0)
	// {
		
	// 	ft_redirection(mini, pipefd, pipefd_2, 2);
	// 	// if (dup2(pipefd_2[0], 0) == -1)
	// 	// 	return (perror("dup2 4"), close(pipefd_2[0]), close(pipefd_2[1]), 1);
	// 	// n = read(0, buff, sizeof(buff));
	// 	// buff[n] = 0;
	// 	// printf("%s hello\n", buff);
		
	// 	close(pipefd_2[1]);
	// 	close(pipefd_2[0]);
	// 	close(pipefd[1]);
	// 	close(pipefd[0]);

	// 	execve(mini->t_commande[2].cmd[0], mini->t_commande[2].cmd, env);
	// 	exit (0);
	// }
	boucle(mini);


	// close(pipefd_2[0]);
	// close(pipefd_2[1]);
	// close(pipefd[0]);
	// close(pipefd[1]);
	// waitpid(id, &status, 0);
	// waitpid(id2, &status, 0);
	// waitpid(id3, &status, 0);
	return (0);
}
