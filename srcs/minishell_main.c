#include "minishell.h"

// On ajoute le token dans la structure t_token;
void add_token(char *line, t_type_token type_token, int len, t_token **token)
{
	t_token *new;

	new = malloc(sizeof(t_token));
	if (!new)
		return ; // Il faudra return une erreur
	new->str = ft_strndup(line, len);	
	new->type_token = type_token;
	new->type_quote = GENERAL; // on va gerer plus tard ***
	line += len; // demander a ma princesse (pour )

	if (!token)
	{
		*token = new;
		return;
	}
	while (token->next)
		token = token->next; // On avance a la fin de la liste chainee
	token->next = new;
}

// On parse pour les mots pour trouver les builtins, on ajoute dans la structure si on en trouve
void parse_builtin(char *line)
{
	if (!ft_strncmp(line, "echo", 4))
		add_token(line, T_ECHO, 4);
	else if (!ft_strncmp(line, "cd", 2))
		add_token(line, T_CD, 2);
	else if (!ft_strncmp(line, "pwd", 3))
		add_token(line, T_PWD, 3);
	else if (!ft_strncmp(line, "export", 6))
		add_token(line, T_EXPORT, 6);
	else if (!ft_strncmp(line, "unset", 5))
		add_token(line, T_UNSET, 5);
	else if (!ft_strncmp(line, "env", 3))
		add_token(line, T_ENV, 3);
	else if (!ft_strncmp(line, "exit", 4))
		add_token(line, T_EXIT, 4);
}

int	ft_strlen_mot_sans_quote(char *line)
{
	int	i;

	i = 0;
	while ((*line) != '>' && (*line) != '<' && (*line) != '|'
		&& (*line) != '"' && (*line) != '\'')
	{
		line++;
		i++;
	}
	return (i);
}
int	ft_strlen_mot_avec_quote(char *line)
{
	int		i;
	int		check_quote;
	char	*temp;

	line++;
	temp = line;
	i = 1;
	check_quote = 1;
	while (*line)
	{
		if ((*line) == '"' || (*line) == '\'')
		{
			i++;
			check_quote++;
			break ;
		}
		line++;
		i++;
	}
	if (check_quote == 2)
		return (i);
	else if (check_quote == 1)
	{
		i = 1;
		while ((*temp) != '>' && (*temp) != '<' && (*temp) != '|'
			&& (*temp) != '"' && (*temp) != '\'')
		{
			temp++;
			i++;
		}
		return (i);
	}
}

// On parse tout pour trouver les operations ou les builtins
// chaque noeud serait d'abord divise que par soit mot, soit redir, soit pipe  (cf. t_type token)
void parse_input(char *line, t_token **token) 
{
	while (*line)
	{
		if (!ft_strncmp(line, ">>", 2) || !ft_strncmp(line, "<<", 2)) // redirection 
		{
			if (!ft_strncmp(line, ">>", 2))
				add_token(line, T_RD_APPEND, 2, token); // on ajoute dans la liste chainee : >>, type : T_RD_APPEND;
			else if (!ft_strncmp(line, "<<", 2))
				add_token(line, T_RD_HEREDOC, 2, token);
			line += 2;
		}
		else if (!ft_strncmp(line, ">", 1) || !ft_strncmp(line, "<", 1))
		{
			if (!ft_strncmp(line, ">", 1))
				add_token(line, T_RD_OUT, 1, token);
			else if (!ft_strncmp(line, "<", 1))
				add_token(line, T_RD_IN, 1, token);
			line += 1;
		}
		else if (!ft_strncmp(line, "|", 1)) // pipe  (noeud '|'  /  type : T_PIPE)
		{
			add_token(line, T_PIPE, 1, token);
			line += 1;
		}
		else if ((*line) != ' ' && (*line) != '\t' && (*line) != '"' && (*line) != '"') // mot qui commence pas par quote
		{
			add_token(line, T_MOT, ft_strlen_mot_sans_quote(line));
			line += ft_strlen_mot_sans_quote(line);
		}
		else if ((*line) == '"' || (*line) == '"') // mot qui commence par quote
		{
			add_token(line, T_MOT, ft_strlen_mot_avec_quote(line));
			line += ft_strlen_mot_avec_quote(line);
		}
		// else if (ft_isalpha(*line) == 1 || line == '"' || line == '\'') // builtin est toujours miniscule ***
		// {
		// 	if (((line == '"') || (line == '\'')) && ft_isalpha(line++) == 1)
		// 		parse_builtin(line++);
		// 	else if (ft_isalpha(line) == 1)
		// 		parse_builtin(line);
		// 	line++;
		// }
		else if ((*line) == ' ' || (*line) == '\t')
		{
			while ((*line) == ' ' || (*line) == '\t')
				line++;
		}
	}
}

// void parse_input(char *line, t_token **token)
// {
// 	while (*line)
// 	{
// 		if (!ft_strncmp(line, ">>", 2))
// 		{
// 			add_token(line, T_RD_APPEND, 2, token); // on ajoute dans la liste chainee : >>, type : T_RD_APPEND;
// 			line += 2;
// 		}
// 		else if (!ft_strncmp(line, ">", 1))
// 		{
// 			add_token(line, T_RD_OUT, 1, token);
// 			line += 1;
// 		}
// 		else if (!ft_strncmp(line, "<<", 2))
// 		{
// 			add_token(line, T_RD_HEREDOC, 2, token);
// 			line += 2;
// 		}
// 		else if (!ft_strncmp(line, "<", 1))
// 		{
// 			add_token(line, T_RD_IN, 1, token);
// 			line += 1;
// 		}
// 		else if (!ft_strncmp(line, "|", 1))
// 		{
// 			add_token(line, T_PIPE, 1, token);
// 			line += 1;
// 		}
// 		else if (ft_isalpha(line) == 1 || line == '"' || line == "'") // builtin est toujours miniscule ***
// 		{
// 			parse_builtin(line);
// 			line++;
// 		}
// 		else
// 			line++;
// 	}
// }

int	main(int ac, char **av, char **env)
{
	(void)ac;
	(void)av;
	(void)env;
	char	*line;
	// t_token	parsing;
	t_minis	*mini;
	// int		j;

	mini = malloc(sizeof(mini));
	if (!mini)
		return (0);
	while (1)
	{
		line = readline("coucou$ ");
		if (!line)
			break ;
		parse_input(line);
		// if (mini->parse->state == DQUOTES)
	}
	return (0);
}
