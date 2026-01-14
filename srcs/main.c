#include "minishell.h"

void parse_input(char **line)
{
	while (*line)
	{
		printf("%s", *line);
		*line++;
	}
}

int	main(int ac, char **av, char **env)
{
	char	*line;
	t_token	parsing;
	t_state state;
	t_mini	*mini;
	int		j;

	mini = malloc(sizeof(mini));
	if (!mini)
		return (0);
	state = GENERAL;
	while (1)
	{
		line = readline("coucou$ ");
		if (!line)
			break;
		parse_input(&line);
		// if (mini->parse->state == DQUOTES)
	}
	return (0);
}


cat>"test.txt"      |ls   -l | wc -l