#include "minishell.h"

int	main(int ac, char **av, char **env)
{
	char	*line;
	t_state state;
	t_mini	*mini;
	int		i;
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
		i = 0;
		// if (mini->parse->state == DQUOTES)
		while (line[i] != '\0')
		{
			while (line[i] != '|' && line[i] != '\0')
			{
				if (line[i] == '>' || line[i] == '<')
				{
					
				}
			}
		}
	}
	return (0);
}


echo "coucou" | wc -l

""
''


>cat texte.txt 
>>

while (!= '\0')
{
	while ( | && != '\0')
		if (> <)
			if (> <)
				noeud
				++
			noeud
			++

		if (' ' !=)
			i++
			strjoin (앞에서부터 마지막 문자까지)
		' '
		++;
	if (!= '\0')
		++;
}